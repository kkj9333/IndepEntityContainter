
#include "IndepEntityContainer.hpp"
#include <llapi/mc/ItemStack.hpp>
#include <llapi/mc/CompoundTag.hpp>
#include "version.h"
extern Logger logger;


namespace Indep {
	void EntityContainer::PlayerData::setDataFromContainer(FillingContainer* c, xuid_t const& xuid) {
		this->mItems.clear();
		this->mPlayerXuid = xuid;
		int size=c->getContainerSize();
		for (auto i = 0; i < size; ++i) {
			auto& item = c->getItem(i);
			if (item.isNull())
				continue;
			this->mItems.push_back({ i,item.save()->toSNBT() });
		}
	}

    void EntityContainer::PlayerData::setDataToContainer(FillingContainer* c)
    {
        c->removeAllItems();
        int size = c->getContainerSize();
        for (auto& item : this->mItems) {
            if (item.first < size)
                c->setItem(item.first, ItemStack::fromTag(*CompoundTag::fromSNBT(item.second)));
            else
                logger.error("error at set data for{},when index {} is more than containersize{}", this->mPlayerXuid, item.first, size);
        }
    }

    void EntityContainer::PlayerData::initFromDefaultData(PlayerData const& d, xuid_t const& xuid)
    {
        this->mItems = d.mItems;
        this->mPlayerXuid = xuid;
    }

    void EntityContainer::PlayerData::initFromJson(nlohmann::json const& json)
    {
        this->mPlayerXuid = json["mPlayerXuid"].get<std::string>();
        this->mItems.clear();
        int max = json["mItems"].size();
        for (int i = 0; i < max; ++i) {
            auto& item = json["mItems"][i];
            int slot = item["slot"].get<int>();
            std::string snbt= item["nbt"].get<std::string>();
            mItems.push_back({ slot,snbt });
        }
    }

    nlohmann::json EntityContainer::PlayerData::toJson()
    {
        nlohmann::json json;
        EntityContainer::PlayerData::initAsPlayerDataJson(json, this->mPlayerXuid);
        //json["mPlayerXuid"] = this->mPlayerXuid;
        int max = this->mItems.size();
        for (int i = 0; i < max; ++i) {
            auto& item = json["mItems"][i];
            item["slot"] = this->mItems[i].first;
            item["nbt"] = this->mItems[i].second;
        }
        return json;
    }

    void EntityContainer::PlayerData::initAsPlayerDataJson(nlohmann::json& json, xuid_t const& xuid)
    {
        json["mPlayerXuid"] = xuid;
        json["mItems"] = nlohmann::json::array();//slot nbt
    }

	void EntityContainer::initFromJson(nlohmann::json const& json)
	{
        this->mId = json["mId"].get<__int64>();
        this->defaultData.initFromJson(json["defaultData"]);
        this->defaultData.mPlayerXuid = "";
        this->lastUpdateT= json["lastUpdateT"].get<__int64>();
        this->mPlayerData.clear();
        int max = json["mPlayerData"].size();
        for (int i = 0; i < max; ++i) {
            PlayerData playerdata;
            playerdata.initFromJson(json["mPlayerData"][i]);
            this->mPlayerData.emplace(playerdata.mPlayerXuid, playerdata);
        }
        //so on
	}


    void EntityContainer::startUseIndepContainer(xuid_t const& xuid, FillingContainer* c)
    {
        if (isUsing)
            return;
        //test needupdate or not
        if (checkneedupdate())
            resetToDefault();
        //first use
        if (this->mPlayerData.find(xuid) == this->mPlayerData.end())
            this->mPlayerData[xuid].initFromDefaultData(this->defaultData, xuid);
        //refresh container
        this->mPlayerData[xuid].setDataToContainer(c);
        isUsing = true;
    }

    void EntityContainer::stopUseIndepContainer(xuid_t const& xuid, FillingContainer* c)
    {
        if (!isUsing)
            return;
        //refresh data
        this->mPlayerData[xuid].setDataFromContainer(c,xuid);
        //save here? or use tick
        this->saveToDisk();
        isUsing = false;
    }

    void EntityContainer::startManageIndepContainer(xuid_t const& xuid, FillingContainer* c)
    {
        if (isUsing||isManagingDef)
            return;
        //refresh container
        this->defaultData.setDataToContainer(c);
        isUsing = true;
        isManagingDef = true;
    }
    void EntityContainer::stopManageIndepContainer(xuid_t const& xuid, FillingContainer* c)
    {
        if (!isUsing||!isManagingDef)
            return;
        //refresh data
        this->defaultData.setDataFromContainer(c, "");
        //save here? or use tick
        this->saveToDisk();
        isUsing = false;
        isManagingDef = false;
    }
    nlohmann::json EntityContainer::toJson()
    {
        nlohmann::json json;
        EntityContainer::initAsEntityContainerJson(json, this->mId);
        //json["mId"] = this->mId.id;
        json["defaultData"] = this->defaultData.toJson();
        json["lastUpdateT"] = this->lastUpdateT;
        int i = 0;
        for (auto ij= this->mPlayerData.begin(); ij!= this->mPlayerData.end(); ++ij,++i) {
            auto& playerdatajson = json["mPlayerData"][i];
            playerdatajson = ij->second.toJson();
        }
        return json;
    }

    bool EntityContainer::saveToDisk()
    {
        EntityContainer::saveEntityContainerJsonToFile(this->toJson(), this->mId);
        return true;
    }
    bool EntityContainer::hasEntityContainerFile(mUniqueID const& uid) {
        checkPluginDir();
        std::ifstream file(plugindatapath + std::to_string(uid));
        if (!file.is_open()) {
            return false;
        }
        file.close();
        return true;
    }

	nlohmann::json EntityContainer::loadEntityContainerJsonFromFile(mUniqueID const& uid, bool createIfNotFound)
    {

        checkPluginDir();
        nlohmann::json json;
        std::ifstream file(plugindatapath + std::to_string(uid));
        if (!file.is_open()) {
            logger.warn("Can't open file " + std::to_string(uid));
            if (createIfNotFound) {
                logger.warn("try load default json...");
                EntityContainer::initAsEntityContainerJson(json, uid);
                saveEntityContainerJsonToFile(json, uid);
            }
            return json;
        }
        file >> json;//auto open
        file.close();
        return json;
    }

    void EntityContainer::saveEntityContainerJsonToFile(nlohmann::json const& json, mUniqueID const& uid)
    {
        checkPluginDir();
        //write
        std::ofstream file(plugindatapath + std::to_string(uid), std::ios::out);
        file << json.dump(4, 32, false, nlohmann::detail::error_handler_t::ignore);
        file.close();
    }

    void EntityContainer::resetToDefault()
    {
        if (isUsing || isManagingDef)
            return;
        for (auto& pData : this->mPlayerData) {
            pData.second.initFromDefaultData(this->defaultData, pData.first);
        }
        this->lastUpdateT = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    }

    bool EntityContainer::checkneedupdate()
    {
        time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        //604800
        time_t nowweek = now / 604800;
        time_t lastupdateweek = this->lastUpdateT / 604800;
        return (lastupdateweek != nowweek);
    }

    void EntityContainer::initAsEntityContainerJson(nlohmann::json& js, mUniqueID const& uid)
    {
        js["mId"] = uid.id;
        EntityContainer::PlayerData::initAsPlayerDataJson(js["defaultData"]);
        js["mPlayerData"] = nlohmann::json::array();//slot nbt
        js["lastUpdateT"] = 0;
    }

}
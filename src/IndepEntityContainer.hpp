#pragma once
#include "CustomType.hpp"
#include <llapi/mc/FillingContainer.hpp>
#include <unordered_map>
#include <Nlohmann/json.hpp>
namespace Indep {
    class EntityContainer {
    public:
        struct PlayerData {
            using ItemSNBTData = std::string;
            using DataType=std::pair<int, ItemSNBTData>;//using SNBT to store
            xuid_t mPlayerXuid="";
            std::vector<DataType> mItems;
            //nlohmann::json toJson() const;
            void setDataFromContainer(FillingContainer* c, xuid_t const& xuid);
            void setDataToContainer(FillingContainer* c);
            void initFromDefaultData(PlayerData const& d, xuid_t const& xuid);
            void initFromJson(nlohmann::json const& js);
            nlohmann::json toJson();
            inline PlayerData(){}
            inline PlayerData(xuid_t const& xuid):mPlayerXuid(xuid) {}
            static void initAsPlayerDataJson(nlohmann::json & js, xuid_t const& xuid="");
        };
    private:
        mUniqueID mId;
        PlayerData defaultData;
        std::unordered_map<xuid_t, EntityContainer::PlayerData> mPlayerData;
    public:
        bool isUsing = false;
        bool isManagingDef = false;
        //bool isChanged = false;
        //bool isLoaded = false;
        int idleTick = 0;
        time_t lastUpdateT = 0;
        void initFromJson(nlohmann::json const& js);
        nlohmann::json toJson();
        bool saveToDisk();
        void startUseIndepContainer(xuid_t const& xuid,FillingContainer* c);
        void stopUseIndepContainer(xuid_t const& xuid, FillingContainer* c);
        void startManageIndepContainer(xuid_t const& xuid, FillingContainer* c);
        void stopManageIndepContainer(xuid_t const& xuid, FillingContainer* c);
        void resetToDefault();
        bool checkneedupdate();
        static bool hasEntityContainerFile(mUniqueID const& uid);
        static nlohmann::json loadEntityContainerJsonFromFile(mUniqueID const& uid,bool createIfNotFound);
        static void saveEntityContainerJsonToFile(nlohmann::json const& json, mUniqueID const& uid);
        static void initAsEntityContainerJson(nlohmann::json& js, mUniqueID const& uid=-1);
    };

}

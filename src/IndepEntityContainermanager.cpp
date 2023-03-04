
#include "IndepEntityContainermanager.hpp"
#include <llapi/mc/Level.hpp>
#include <llapi/mc/Item.hpp>
#include <llapi/mc/ItemStack.hpp>
extern Logger logger;
namespace Indep {
	EntityContainerManager mGlobalECManager;
	EntityContainer* EntityContainerManager::queryEntityContainer(mUniqueID const& uid, bool forceLoadfromDisk,bool createIfNone)
	{
		if (this->mControlList.find(uid) == this->mControlList.end())
		{
			if (forceLoadfromDisk) {
				if (!EntityContainer::hasEntityContainerFile(uid) && !createIfNone)
					return nullptr;
				auto json=EntityContainer::loadEntityContainerJsonFromFile(uid, createIfNone);
				if (json.is_null())
					return nullptr;
				else
				{
					this->mControlList[uid].initFromJson(json);
					return &this->mControlList[uid];
				}
			}
		}
		else {
			this->mControlList[uid].idleTick = 0;
			return &this->mControlList[uid];
		}
		return nullptr;
	}
	bool EntityContainerManager::isOpManaging(Player* p)
	{
		if ((int)p->getCommandPermissionLevel() == 0)
			return false;
		auto& item = p->getSelectedItem();
		return (!item.isNull() && item.getItem()->getSerializedName() == "minecraft:stick");
	}
	bool EntityContainerManager::forceReset(mUniqueID const& uid)
	{
		if (!hasIndepEntity(uid))
			return false;
		auto mEC = queryEntityContainer(uid);
		if(mEC->isManagingDef|| mEC->isUsing)
			return false;
		mEC->resetToDefault();
		return true;
	}
	bool EntityContainerManager::createIndepEntity(mUniqueID const& uid)
	{
		if(hasIndepEntity(uid))
			return false;
		return queryEntityContainer(uid, 1, 1)!=NULL;

	}
	bool EntityContainerManager::hasIndepEntity(mUniqueID const& uid)
	{
		return queryEntityContainer(uid)!=NULL;
	}
	bool EntityContainerManager::CanReOpenIndepEntity(mUniqueID const& uid)
	{
		return queryEntityContainer(uid)&& !queryEntityContainer(uid)->isUsing;
	}
	bool EntityContainerManager::handleIndepContainerOpen(Player* sp, Actor* ac, FillingContainer* fcontainer)
	{

		auto xuid = sp->getXuid();
		mUniqueID acuid = ac->getUniqueID();
		if (isOpManaging(sp)) {
			queryEntityContainer(acuid)->startManageIndepContainer(xuid, fcontainer);
		}
		else {
			queryEntityContainer(acuid)->startUseIndepContainer(xuid, fcontainer);
		}
		mUsingList[xuid] = { acuid,fcontainer };
		return true;
	}

	bool EntityContainerManager::handleIndepContainerRemove(Player* sp)
	{
		auto xuid = sp->getXuid();
		if (mUsingList.find(xuid) == mUsingList.end())
			return false;
		mUniqueID acuid = mUsingList[xuid].first;
		FillingContainer* fcontainer= mUsingList[xuid].second;
		bool failed = false;
		if (!queryEntityContainer(acuid)) {
			logger.warn("Error at{}, when Player {} is using without uid {} recorded", __FUNCDNAME__,sp->getRealName(),acuid);
			failed = true;
		}
		if (!Global<Level>->fetchEntity(acuid, 0)) {
			logger.error("Error at{}, the ContainerEntity is missing...", __FUNCDNAME__);
			if (queryEntityContainer(acuid) != NULL)
			{
				queryEntityContainer(acuid)->isUsing = false;
				queryEntityContainer(acuid)->isManagingDef = false;
			}
			failed = true;
		}
		mUsingList.erase(xuid);
		if (!failed) {
			if (queryEntityContainer(acuid)->isManagingDef)
				queryEntityContainer(acuid)->stopManageIndepContainer(xuid, fcontainer);
			else
			queryEntityContainer(acuid)->stopUseIndepContainer(xuid, fcontainer);
		}
		return !failed;
	}

	void EntityContainerManager::tick()
	{
		for (auto i = mControlList.begin(); i != mControlList.end();) {
			if (i->second.isUsing)
			{
				++i;
				continue;
			}
			++(i->second.idleTick);
			if (i->second.idleTick > this->defReleaseTick)
			{
				i->second.saveToDisk();
				i = mControlList.erase(i);
				continue;
			}
			++i;
		}
	}

}
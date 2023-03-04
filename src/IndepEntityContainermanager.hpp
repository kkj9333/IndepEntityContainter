#pragma once
#include <llapi/LoggerAPI.h>
#include <unordered_map>
#include "IndepEntityContainer.hpp"
#include <llapi/mc/Player.hpp>
namespace Indep {
	class EntityContainerManager {
	private:
		int defReleaseTick = 300;
		std::unordered_map<mUniqueID, EntityContainer,myHashFuc> mControlList;
		std::unordered_map<xuid_t, std::pair<mUniqueID,FillingContainer*>> mUsingList;
		EntityContainer* queryEntityContainer(mUniqueID const& uid, bool forceLoadfromDisk = true,bool createIfNone=false);
	public:
		bool isOpManaging(Player* p);
		bool forceReset(mUniqueID const& uid);
		bool createIndepEntity(mUniqueID const& uid);
		bool hasIndepEntity(mUniqueID const& uid);
		bool CanReOpenIndepEntity(mUniqueID const& uid);
		bool handleIndepContainerOpen(Player* sp,Actor* ac,FillingContainer* fcontainer);//
		bool handleIndepContainerRemove(Player* sp);
		void tick();
	};
	extern EntityContainerManager mGlobalECManager;
}

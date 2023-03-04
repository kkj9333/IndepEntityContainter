
#include <llapi/mc/Player.hpp>
#include <llapi/mc/ContainerComponent.hpp>
#include <llapi/mc/Level.hpp>
#include <llapi/mc/ServerPlayer.hpp>
#include <llapi/mc/ContainerClosePacket.hpp>
#include <llapi/ScheduleAPI.h>
#include "IndepEntityContainermanager.hpp"
//open container from entity
TInstanceHook(bool, "?openContainer@ContainerComponent@@QEAA_NAEAVActor@@AEAVPlayer@@@Z", ContainerComponent ,Actor* ac,Player* sp ) {
	std::cout << "Entity container open by:" << sp->getNameTag() << std::endl;
	auto c = this->_getRawContainerPtr();//is good?
	auto acuid = ac->getUniqueID();
	bool hasentity = Indep::mGlobalECManager.hasIndepEntity(acuid);
	if (hasentity && !Indep::mGlobalECManager.CanReOpenIndepEntity(acuid))
	{
		sp->sendText("...");
		return false;
	}
	bool ret=original(this, ac, sp);
	if (ret && hasentity)
	{
		Indep::mGlobalECManager.handleIndepContainerOpen(sp, ac, c);
	}
	return ret;
}
//from server
TInstanceHook(void, "?deleteContainerManager@Player@@UEAAXXZ", Player) {
	std::cout << "[Server]container will close for:" << this->getNameTag() << std::endl;
	Indep::mGlobalECManager.handleIndepContainerRemove(this);
	return original(this);
}
/*
//from client
TInstanceHook(void, "?doDeleteContainerManager@ServerPlayer@@QEAAX_N@Z", ServerPlayer,bool a2) {//a2 must be true
	std::cout << "[Client]container close by:" << this->getNameTag() << std::endl;
	return original(this,a2);
}
*/
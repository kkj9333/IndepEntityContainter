/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */
#include <llapi/LoggerAPI.h>
#include <direct.h>
#include <llapi/EventAPI.h>
#include <llapi/ScheduleAPI.h>
#include <llapi/mc/ItemStack.hpp>
#include <llapi/mc/Item.hpp>
#include "version.h"
#include "IndepEntityContainermanager.hpp"
// We recommend using the global logger.
Logger logger(PLUGIN_NAME);

// checkdir
void checkPluginDir() {
    if (0 != _access(pluginpath, 0))
    {
        logger.warn("Can't find direct,try create:{} ", pluginpath);
        int ss = _mkdir(pluginpath);
        if (!ss)
            logger.info("create {} success!", pluginpath);
        else
            logger.error("create {} error!", pluginpath);
    }
    if (0 != _access(plugindatapath, 0))
    {
        logger.warn("Can't find direct,try create:{} ", plugindatapath);
        int ss = _mkdir(plugindatapath);
        if (!ss)
            logger.info("create {} success!", plugindatapath);
        else
            logger.error("create {} error!", plugindatapath);
    }
}



/**
 * @brief The entrypoint of the plugin. DO NOT remove or rename this function.
 *        
 */
void PluginInit()
{
    logger.info("A BDS plugin that allows the same entity container to be opened by different players with different recording contents");
    checkPluginDir();
    Schedule::repeat([]() {
        Indep::mGlobalECManager.tick();
        }
    , 20);
    //op edit
    Event::PlayerAttackEvent::subscribe([](Event::PlayerAttackEvent const& ev) {
        if (Indep::mGlobalECManager.isOpManaging(ev.mPlayer)) {
            if (ev.mPlayer->isSneaking()&& Indep::mGlobalECManager.hasIndepEntity(ev.mTarget->getUniqueID())) {
                if (Indep::mGlobalECManager.forceReset(ev.mTarget->getUniqueID())) {
                    ev.mPlayer->sendText("Reset successfully!");
                    ev.mPlayer->sendPlaySoundPacket("random.levelup", ev.mPlayer->getPos(), 1, 1);
                }
                else {
                    ev.mPlayer->sendText("Failed to reset");
                    ev.mPlayer->sendPlaySoundPacket("mob.villager.no", ev.mPlayer->getPos(), 1, 1);
                }
            }
            else {
                if (Indep::mGlobalECManager.createIndepEntity(ev.mTarget->getUniqueID())) {
                    ev.mPlayer->sendText("Set successfully!");
                    ev.mPlayer->sendPlaySoundPacket("random.levelup", ev.mPlayer->getPos(), 1, 1);
                }
                else {
                    ev.mPlayer->sendText("Failed to set");
                    ev.mPlayer->sendPlaySoundPacket("mob.villager.no", ev.mPlayer->getPos(), 1, 1);
                }
            }

            return false;
        }
        return true;
        });
}

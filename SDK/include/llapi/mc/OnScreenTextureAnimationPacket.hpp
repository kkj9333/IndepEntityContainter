/**
 * @file  OnScreenTextureAnimationPacket.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class OnScreenTextureAnimationPacket.
 *
 */
class OnScreenTextureAnimationPacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ONSCREENTEXTUREANIMATIONPACKET
public:
    class OnScreenTextureAnimationPacket& operator=(class OnScreenTextureAnimationPacket const &) = delete;
    OnScreenTextureAnimationPacket(class OnScreenTextureAnimationPacket const &) = delete;
#endif

public:
    /**
     * @vftbl  0
     * @symbol  __unk_destructor_0
     */
    virtual ~OnScreenTextureAnimationPacket();
    /**
     * @hash   1901710738
     * @vftbl  1
     * @symbol  ?getId\@OnScreenTextureAnimationPacket\@\@UEBA?AW4MinecraftPacketIds\@\@XZ
     */
    virtual enum class MinecraftPacketIds getId() const;
    /**
     * @hash   1961204799
     * @vftbl  2
     * @symbol  ?getName\@OnScreenTextureAnimationPacket\@\@UEBA?AV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@XZ
     */
    virtual std::string getName() const;
    /**
     * @hash   -1046802264
     * @vftbl  3
     * @symbol  ?write\@OnScreenTextureAnimationPacket\@\@UEBAXAEAVBinaryStream\@\@\@Z
     */
    virtual void write(class BinaryStream &) const;
    /**
     * @hash   -1347379544
     * @vftbl  6
     * @symbol  ?_read\@OnScreenTextureAnimationPacket\@\@EEAA?AW4StreamReadResult\@\@AEAVReadOnlyBinaryStream\@\@\@Z
     */
    virtual enum class StreamReadResult _read(class ReadOnlyBinaryStream &);
    /**
     * @hash   910381016
     * @symbol  ??0OnScreenTextureAnimationPacket\@\@QEAA\@XZ
     */
    MCAPI OnScreenTextureAnimationPacket();
    /**
     * @hash   329862269
     * @symbol  ??0OnScreenTextureAnimationPacket\@\@QEAA\@I\@Z
     */
    MCAPI OnScreenTextureAnimationPacket(unsigned int);

};
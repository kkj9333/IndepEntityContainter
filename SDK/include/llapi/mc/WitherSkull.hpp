/**
 * @file  WitherSkull.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"
#include "Actor.hpp"
#include "Fireball.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class WitherSkull.
 *
 */
class WitherSkull : public Fireball {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_WITHERSKULL
public:
    class WitherSkull& operator=(class WitherSkull const &) = delete;
    WitherSkull(class WitherSkull const &) = delete;
    WitherSkull() = delete;
#endif

public:
    /**
     * @hash   1703024422
     * @vftbl  12
     * @symbol  ?initializeComponents\@WitherSkull\@\@UEAAXW4InitializationMethod\@Actor\@\@AEBVVariantParameterList\@\@\@Z
     */
    virtual void initializeComponents(enum class Actor::InitializationMethod, class VariantParameterList const &);
    /**
     * @vftbl  16
     * @symbol  __unk_destructor_16
     */
    virtual ~WitherSkull();
    /**
     * @vftbl  41
     * @symbol  __unk_vfn_41
     */
    virtual void __unk_vfn_41();
    /**
     * @vftbl  62
     * @symbol  __unk_vfn_62
     */
    virtual void __unk_vfn_62();
    /**
     * @vftbl  69
     * @symbol  __unk_vfn_69
     */
    virtual void __unk_vfn_69();
    /**
     * @vftbl  83
     * @symbol  __unk_vfn_83
     */
    virtual void __unk_vfn_83();
    /**
     * @vftbl  86
     * @symbol  __unk_vfn_86
     */
    virtual void __unk_vfn_86();
    /**
     * @vftbl  89
     * @symbol  __unk_vfn_89
     */
    virtual void __unk_vfn_89();
    /**
     * @hash   -896730236
     * @vftbl  96
     * @symbol  ?isPickable\@WitherSkull\@\@UEAA_NXZ
     */
    virtual bool isPickable();
    /**
     * @vftbl  97
     * @symbol  __unk_vfn_97
     */
    virtual void __unk_vfn_97();
    /**
     * @vftbl  100
     * @symbol  __unk_vfn_100
     */
    virtual void __unk_vfn_100();
    /**
     * @hash   887328397
     * @vftbl  105
     * @symbol  ?isOnFire\@WitherSkull\@\@UEBA_NXZ
     */
    virtual bool isOnFire() const;
    /**
     * @vftbl  107
     * @symbol  __unk_vfn_107
     */
    virtual void __unk_vfn_107();
    /**
     * @vftbl  109
     * @symbol  __unk_vfn_109
     */
    virtual void __unk_vfn_109();
    /**
     * @vftbl  110
     * @symbol  __unk_vfn_110
     */
    virtual void __unk_vfn_110();
    /**
     * @vftbl  112
     * @symbol  __unk_vfn_112
     */
    virtual void __unk_vfn_112();
    /**
     * @vftbl  179
     * @symbol  __unk_vfn_179
     */
    virtual void __unk_vfn_179();
    /**
     * @vftbl  193
     * @symbol  __unk_vfn_193
     */
    virtual void __unk_vfn_193();
    /**
     * @vftbl  218
     * @symbol  __unk_vfn_218
     */
    virtual void __unk_vfn_218();
    /**
     * @vftbl  219
     * @symbol  __unk_vfn_219
     */
    virtual void __unk_vfn_219();
    /**
     * @hash   1377761849
     * @vftbl  232
     * @symbol  ?canDestroyBlock\@WitherSkull\@\@UEBA_NAEBVBlock\@\@\@Z
     */
    virtual bool canDestroyBlock(class Block const &) const;
    /**
     * @vftbl  241
     * @symbol  __unk_vfn_241
     */
    virtual void __unk_vfn_241();
    /**
     * @vftbl  244
     * @symbol  __unk_vfn_244
     */
    virtual void __unk_vfn_244();
    /**
     * @vftbl  262
     * @symbol  __unk_vfn_262
     */
    virtual void __unk_vfn_262();
    /**
     * @hash   -1973754794
     * @vftbl  263
     * @symbol  ?_hurt\@WitherSkull\@\@MEAA_NAEBVActorDamageSource\@\@M_N1\@Z
     */
    virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /**
     * @vftbl  270
     * @symbol  __unk_vfn_270
     */
    virtual void __unk_vfn_270();
    /**
     * @vftbl  277
     * @symbol  __unk_vfn_277
     */
    virtual void __unk_vfn_277();
    /**
     * @hash   -598516574
     * @vftbl  278
     * @symbol  ?getInertia\@WitherSkull\@\@MEAAMXZ
     */
    virtual float getInertia();
    /**
     * @vftbl  279
     * @symbol  __unk_vfn_279
     */
    virtual void __unk_vfn_279();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_WITHERSKULL
    /**
     * @hash   1249433809
     * @symbol  ?shouldBurn\@WitherSkull\@\@UEAA_NXZ
     */
    MCVAPI bool shouldBurn();
#endif
    /**
     * @hash   -2093400922
     * @symbol  ??0WitherSkull\@\@QEAA\@PEAVActorDefinitionGroup\@\@AEBUActorDefinitionIdentifier\@\@AEAVEntityContext\@\@\@Z
     */
    MCAPI WitherSkull(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);

};
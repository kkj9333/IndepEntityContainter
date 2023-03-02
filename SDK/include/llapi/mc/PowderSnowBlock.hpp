/**
 * @file  PowderSnowBlock.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"
#include "BlockLegacy.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class PowderSnowBlock.
 *
 */
class PowderSnowBlock : public BlockLegacy {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_POWDERSNOWBLOCK
public:
    class PowderSnowBlock& operator=(class PowderSnowBlock const &) = delete;
    PowderSnowBlock(class PowderSnowBlock const &) = delete;
    PowderSnowBlock() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @symbol  __unk_destructor_0
     */
    virtual ~PowderSnowBlock();
    /**
     * @hash   -308856137
     * @vftbl  5
     * @symbol  ?getCollisionShape\@PowderSnowBlock\@\@UEBA_NAEAVAABB\@\@AEBVBlock\@\@AEBVIConstBlockSource\@\@AEBVBlockPos\@\@V?$optional_ref\@$$CBVGetCollisionShapeInterface\@\@\@\@\@Z
     */
    virtual bool getCollisionShape(class AABB &, class Block const &, class IConstBlockSource const &, class BlockPos const &, class optional_ref<class GetCollisionShapeInterface const>) const;
    /**
     * @hash   -1794069199
     * @vftbl  10
     * @symbol  ?getAABB\@PowderSnowBlock\@\@UEBAAEBVAABB\@\@AEBVIConstBlockSource\@\@AEBVBlockPos\@\@AEBVBlock\@\@AEAV2\@_N\@Z
     */
    virtual class AABB const & getAABB(class IConstBlockSource const &, class BlockPos const &, class Block const &, class AABB &, bool) const;
    /**
     * @vftbl  19
     * @symbol  __unk_vfn_19
     */
    virtual void __unk_vfn_19();
    /**
     * @hash   -1609070000
     * @vftbl  22
     * @symbol  ?canProvideSupport\@PowderSnowBlock\@\@UEBA_NAEBVBlock\@\@EW4BlockSupportType\@\@\@Z
     */
    virtual bool canProvideSupport(class Block const &, unsigned char, enum class BlockSupportType) const;
    /**
     * @hash   1530296472
     * @vftbl  25
     * @symbol  ?canConnect\@PowderSnowBlock\@\@UEBA_NAEBVBlock\@\@E0\@Z
     */
    virtual bool canConnect(class Block const &, unsigned char, class Block const &) const;
    /**
     * @vftbl  29
     * @symbol  __unk_vfn_29
     */
    virtual void __unk_vfn_29();
    /**
     * @vftbl  30
     * @symbol  __unk_vfn_30
     */
    virtual void __unk_vfn_30();
    /**
     * @hash   1815066923
     * @vftbl  31
     * @symbol  ?isClimbable\@PowderSnowBlock\@\@UEBA_NAEBUIActorMovementProxy\@\@\@Z
     */
    virtual bool isClimbable(struct IActorMovementProxy const &) const;
    /**
     * @vftbl  32
     * @symbol  __unk_vfn_32
     */
    virtual void __unk_vfn_32();
    /**
     * @vftbl  33
     * @symbol  __unk_vfn_33
     */
    virtual void __unk_vfn_33();
    /**
     * @vftbl  34
     * @symbol  __unk_vfn_34
     */
    virtual void __unk_vfn_34();
    /**
     * @hash   489969385
     * @vftbl  35
     * @symbol  ?isWaterBlocking\@PowderSnowBlock\@\@UEBA_NXZ
     */
    virtual bool isWaterBlocking() const;
    /**
     * @vftbl  36
     * @symbol  __unk_vfn_36
     */
    virtual void __unk_vfn_36();
    /**
     * @vftbl  37
     * @symbol  __unk_vfn_37
     */
    virtual void __unk_vfn_37();
    /**
     * @vftbl  38
     * @symbol  __unk_vfn_38
     */
    virtual void __unk_vfn_38();
    /**
     * @vftbl  39
     * @symbol  __unk_vfn_39
     */
    virtual void __unk_vfn_39();
    /**
     * @vftbl  40
     * @symbol  __unk_vfn_40
     */
    virtual void __unk_vfn_40();
    /**
     * @vftbl  41
     * @symbol  __unk_vfn_41
     */
    virtual void __unk_vfn_41();
    /**
     * @vftbl  42
     * @symbol  __unk_vfn_42
     */
    virtual void __unk_vfn_42();
    /**
     * @vftbl  44
     * @symbol  __unk_vfn_44
     */
    virtual void __unk_vfn_44();
    /**
     * @vftbl  45
     * @symbol  __unk_vfn_45
     */
    virtual void __unk_vfn_45();
    /**
     * @vftbl  46
     * @symbol  __unk_vfn_46
     */
    virtual void __unk_vfn_46();
    /**
     * @vftbl  47
     * @symbol  __unk_vfn_47
     */
    virtual void __unk_vfn_47();
    /**
     * @vftbl  48
     * @symbol  __unk_vfn_48
     */
    virtual void __unk_vfn_48();
    /**
     * @vftbl  49
     * @symbol  __unk_vfn_49
     */
    virtual void __unk_vfn_49();
    /**
     * @hash   1399226142
     * @vftbl  53
     * @symbol  ?canBeAscendedByJumping\@PowderSnowBlock\@\@UEBA_NAEBVActor\@\@AEBVBlockPos\@\@\@Z
     */
    virtual bool canBeAscendedByJumping(class Actor const &, class BlockPos const &) const;
    /**
     * @vftbl  54
     * @symbol  __unk_vfn_54
     */
    virtual void __unk_vfn_54();
    /**
     * @vftbl  60
     * @symbol  __unk_vfn_60
     */
    virtual void __unk_vfn_60();
    /**
     * @vftbl  61
     * @symbol  __unk_vfn_61
     */
    virtual void __unk_vfn_61();
    /**
     * @hash   -521525433
     * @vftbl  62
     * @symbol  ?canContainLiquid\@PowderSnowBlock\@\@UEBA_NXZ
     */
    virtual bool canContainLiquid() const;
    /**
     * @vftbl  75
     * @symbol  __unk_vfn_75
     */
    virtual void __unk_vfn_75();
    /**
     * @vftbl  82
     * @symbol  __unk_vfn_82
     */
    virtual void __unk_vfn_82();
    /**
     * @hash   -1939384774
     * @vftbl  96
     * @symbol  ?breaksFallingBlocks\@PowderSnowBlock\@\@UEBA_NAEBVBlock\@\@VBaseGameVersion\@\@\@Z
     */
    virtual bool breaksFallingBlocks(class Block const &, class BaseGameVersion) const;
    /**
     * @hash   714183257
     * @vftbl  103
     * @symbol  ?asItemInstance\@PowderSnowBlock\@\@UEBA?AVItemInstance\@\@AEBVBlock\@\@PEBVBlockActor\@\@\@Z
     */
    virtual class ItemInstance asItemInstance(class Block const &, class BlockActor const *) const;
    /**
     * @vftbl  105
     * @symbol  __unk_vfn_105
     */
    virtual void __unk_vfn_105();
    /**
     * @hash   1348385275
     * @vftbl  113
     * @symbol  ?entityInside\@PowderSnowBlock\@\@UEBAXAEAVBlockSource\@\@AEBVBlockPos\@\@AEAVActor\@\@\@Z
     */
    virtual void entityInside(class BlockSource &, class BlockPos const &, class Actor &) const;
    /**
     * @vftbl  123
     * @symbol  __unk_vfn_123
     */
    virtual void __unk_vfn_123();
    /**
     * @vftbl  125
     * @symbol  __unk_vfn_125
     */
    virtual void __unk_vfn_125();
    /**
     * @vftbl  126
     * @symbol  __unk_vfn_126
     */
    virtual void __unk_vfn_126();
    /**
     * @vftbl  131
     * @symbol  __unk_vfn_131
     */
    virtual void __unk_vfn_131();
    /**
     * @vftbl  156
     * @symbol  __unk_vfn_156
     */
    virtual void __unk_vfn_156();
    /**
     * @vftbl  165
     * @symbol  __unk_vfn_165
     */
    virtual void __unk_vfn_165();
    /**
     * @vftbl  166
     * @symbol  __unk_vfn_166
     */
    virtual void __unk_vfn_166();
    /**
     * @vftbl  167
     * @symbol  __unk_vfn_167
     */
    virtual void __unk_vfn_167();
    /**
     * @hash   1101439375
     * @vftbl  169
     * @symbol  ?onFallOn\@PowderSnowBlock\@\@UEBAXAEAVBlockSource\@\@AEBVBlockPos\@\@AEAVActor\@\@M\@Z
     */
    virtual void onFallOn(class BlockSource &, class BlockPos const &, class Actor &, float) const;
    /**
     * @vftbl  170
     * @symbol  __unk_vfn_170
     */
    virtual void __unk_vfn_170();
    /**
     * @vftbl  174
     * @symbol  __unk_vfn_174
     */
    virtual void __unk_vfn_174();
    /**
     * @vftbl  185
     * @symbol  __unk_vfn_185
     */
    virtual void __unk_vfn_185();
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_POWDERSNOWBLOCK
    /**
     * @hash   1111195172
     * @symbol  ?canBeDestroyedByWaterSpread\@PowderSnowBlock\@\@UEBA_NXZ
     */
    MCVAPI bool canBeDestroyedByWaterSpread() const;
    /**
     * @hash   -302833763
     * @symbol  ?canBeSilkTouched\@PowderSnowBlock\@\@UEBA_NXZ
     */
    MCVAPI bool canBeSilkTouched() const;
    /**
     * @hash   76243529
     * @symbol  ?causesFreezeEffect\@PowderSnowBlock\@\@UEBA_NXZ
     */
    MCVAPI bool causesFreezeEffect() const;
#endif
    /**
     * @hash   1279845320
     * @symbol  ??0PowderSnowBlock\@\@QEAA\@AEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@HAEBVMaterial\@\@\@Z
     */
    MCAPI PowderSnowBlock(std::string const &, int, class Material const &);
    /**
     * @hash   382268413
     * @symbol  ?canWalkOnTop\@PowderSnowBlock\@\@SA_NAEBUIActorMovementProxy\@\@\@Z
     */
    MCAPI static bool canWalkOnTop(struct IActorMovementProxy const &);
    /**
     * @hash   -880407947
     * @symbol  ?canWalkOnTop\@PowderSnowBlock\@\@SA_NAEBVGetCollisionShapeInterface\@\@\@Z
     */
    MCAPI static bool canWalkOnTop(class GetCollisionShapeInterface const &);
    /**
     * @hash   2124038108
     * @symbol  ?clearFire\@PowderSnowBlock\@\@SAXAEAVBlockSource\@\@AEBVBlockPos\@\@AEBVBlock\@\@\@Z
     */
    MCAPI static void clearFire(class BlockSource &, class BlockPos const &, class Block const &);
    /**
     * @symbol  ?spawnPowderSnowParticles\@PowderSnowBlock\@\@SAXAEAVLevel\@\@AEBVBlockPos\@\@\@Z
     */
    MCAPI static void spawnPowderSnowParticles(class Level &, class BlockPos const &);

};
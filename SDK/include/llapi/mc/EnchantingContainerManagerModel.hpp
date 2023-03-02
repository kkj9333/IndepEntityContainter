/**
 * @file  EnchantingContainerManagerModel.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"
#include "ContainerManagerModel.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class EnchantingContainerManagerModel.
 *
 */
class EnchantingContainerManagerModel : public ContainerManagerModel {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ENCHANTINGCONTAINERMANAGERMODEL
public:
    class EnchantingContainerManagerModel& operator=(class EnchantingContainerManagerModel const &) = delete;
    EnchantingContainerManagerModel(class EnchantingContainerManagerModel const &) = delete;
    EnchantingContainerManagerModel() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @symbol  __unk_destructor_0
     */
    virtual ~EnchantingContainerManagerModel();
    /**
     * @hash   -582928741
     * @vftbl  6
     * @symbol  ?getItemCopies\@EnchantingContainerManagerModel\@\@UEBA?AV?$vector\@VItemStack\@\@V?$allocator\@VItemStack\@\@\@std\@\@\@std\@\@XZ
     */
    virtual std::vector<class ItemStack> getItemCopies() const;
    /**
     * @hash   -1434548508
     * @vftbl  7
     * @symbol  ?setSlot\@EnchantingContainerManagerModel\@\@UEAAXHAEBVItemStack\@\@_N\@Z
     */
    virtual void setSlot(int, class ItemStack const &, bool);
    /**
     * @hash   -220627
     * @vftbl  8
     * @symbol  ?getSlot\@EnchantingContainerManagerModel\@\@UEBAAEBVItemStack\@\@H\@Z
     */
    virtual class ItemStack const & getSlot(int) const;
    /**
     * @hash   -1177360481
     * @vftbl  9
     * @symbol  ?setData\@EnchantingContainerManagerModel\@\@UEAAXHH\@Z
     */
    virtual void setData(int, int);
    /**
     * @hash   -1772482411
     * @vftbl  10
     * @symbol  ?broadcastChanges\@EnchantingContainerManagerModel\@\@UEAAXXZ
     */
    virtual void broadcastChanges();
    /**
     * @hash   -66679781
     * @vftbl  16
     * @symbol  ?isValid\@EnchantingContainerManagerModel\@\@UEAA_NM\@Z
     */
    virtual bool isValid(float);
    /**
     * @hash   913622354
     * @vftbl  17
     * @symbol  ?_postInit\@EnchantingContainerManagerModel\@\@MEAA?AVContainerScreenContext\@\@XZ
     */
    virtual class ContainerScreenContext _postInit();
    /**
     * @hash   484098161
     * @symbol  ??0EnchantingContainerManagerModel\@\@QEAA\@W4ContainerID\@\@AEAVPlayer\@\@AEBVBlockPos\@\@\@Z
     */
    MCAPI EnchantingContainerManagerModel(enum class ContainerID, class Player &, class BlockPos const &);
    /**
     * @hash   -658020036
     * @symbol  ?getEnchantOptions\@EnchantingContainerManagerModel\@\@QEBAAEBV?$vector\@VItemEnchantOption\@\@V?$allocator\@VItemEnchantOption\@\@\@std\@\@\@std\@\@XZ
     */
    MCAPI std::vector<class ItemEnchantOption> const & getEnchantOptions() const;
    /**
     * @hash   -576612423
     * @symbol  ?recalculateOptions\@EnchantingContainerManagerModel\@\@QEAAXXZ
     */
    MCAPI void recalculateOptions();
    /**
     * @hash   -943087509
     * @symbol  ?NUM_OPTIONS\@EnchantingContainerManagerModel\@\@2HB
     */
    MCAPI static int const NUM_OPTIONS;

};
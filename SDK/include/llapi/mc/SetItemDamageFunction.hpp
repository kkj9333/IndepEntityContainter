/**
 * @file  SetItemDamageFunction.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"
#include "Json.hpp"
#include "LootItemFunction.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class SetItemDamageFunction.
 *
 */
class SetItemDamageFunction : public LootItemFunction {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SETITEMDAMAGEFUNCTION
public:
    class SetItemDamageFunction& operator=(class SetItemDamageFunction const &) = delete;
    SetItemDamageFunction(class SetItemDamageFunction const &) = delete;
    SetItemDamageFunction() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @symbol  __unk_destructor_0
     */
    virtual ~SetItemDamageFunction();
    /**
     * @hash   1977364040
     * @vftbl  1
     * @symbol  ?apply\@SetItemDamageFunction\@\@UEAAXAEAVItemStack\@\@AEAVRandom\@\@AEAVLootTableContext\@\@\@Z
     */
    virtual void apply(class ItemStack &, class Random &, class LootTableContext &);
    /**
     * @hash   -1748860451
     * @vftbl  3
     * @symbol  ?apply\@SetItemDamageFunction\@\@UEAAXAEAVItemInstance\@\@AEAVRandom\@\@AEAVLootTableContext\@\@\@Z
     */
    virtual void apply(class ItemInstance &, class Random &, class LootTableContext &);
    /**
     * @hash   -68418321
     * @symbol  ?deserialize\@SetItemDamageFunction\@\@SA?AV?$unique_ptr\@VLootItemFunction\@\@U?$default_delete\@VLootItemFunction\@\@\@std\@\@\@std\@\@VValue\@Json\@\@AEAV?$vector\@V?$unique_ptr\@VLootItemCondition\@\@U?$default_delete\@VLootItemCondition\@\@\@std\@\@\@std\@\@V?$allocator\@V?$unique_ptr\@VLootItemCondition\@\@U?$default_delete\@VLootItemCondition\@\@\@std\@\@\@std\@\@\@2\@\@3\@\@Z
     */
    MCAPI static std::unique_ptr<class LootItemFunction> deserialize(class Json::Value, std::vector<std::unique_ptr<class LootItemCondition>> &);

};
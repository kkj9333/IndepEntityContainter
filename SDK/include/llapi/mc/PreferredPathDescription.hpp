/**
 * @file  PreferredPathDescription.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC structure PreferredPathDescription.
 *
 */
struct PreferredPathDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PREFERREDPATHDESCRIPTION
public:
    struct PreferredPathDescription& operator=(struct PreferredPathDescription const &) = delete;
    PreferredPathDescription(struct PreferredPathDescription const &) = delete;
#endif

public:
    /**
     * @hash   276849838
     * @vftbl  0
     * @symbol  ?getJsonName\@PreferredPathDescription\@\@UEBAPEBDXZ
     */
    virtual char const * getJsonName() const;
    /**
     * @vftbl  1
     * @symbol  __unk_destructor_1
     */
    virtual ~PreferredPathDescription();
    /**
     * @hash   2052664789
     * @vftbl  2
     * @symbol  ?deserializeData\@PreferredPathDescription\@\@UEAAXUDeserializeDataParams\@\@\@Z
     */
    virtual void deserializeData(struct DeserializeDataParams);
    /**
     * @hash   -766214033
     * @vftbl  3
     * @symbol  ?serializeData\@PreferredPathDescription\@\@UEBAXAEAVValue\@Json\@\@\@Z
     */
    virtual void serializeData(class Json::Value &) const;
    /**
     * @hash   -1468306078
     * @symbol  ??0PreferredPathDescription\@\@QEAA\@XZ
     */
    MCAPI PreferredPathDescription();

};
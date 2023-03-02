/**
 * @file  ActorHasTagTest.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"
#include "FilterTest.hpp"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

/**
 * @brief MC class ActorHasTagTest.
 *
 */
class ActorHasTagTest : public FilterTest {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTORHASTAGTEST
public:
    class ActorHasTagTest& operator=(class ActorHasTagTest const &) = delete;
    ActorHasTagTest(class ActorHasTagTest const &) = delete;
    ActorHasTagTest() = delete;
#endif

public:
    /**
     * @vftbl  0
     * @symbol  __unk_destructor_0
     */
    virtual ~ActorHasTagTest();
    /**
     * @hash   -1240571703
     * @vftbl  2
     * @symbol  ?evaluate\@ActorHasTagTest\@\@UEBA_NAEBUFilterContext\@\@\@Z
     */
    virtual bool evaluate(struct FilterContext const &) const;
    /**
     * @hash   -1554155831
     * @vftbl  4
     * @symbol  ?getName\@ActorHasTagTest\@\@UEBA?AV?$basic_string_span\@$$CBD$0?0\@gsl\@\@XZ
     */
    virtual class gsl::basic_string_span<char const, -1> getName() const;

};
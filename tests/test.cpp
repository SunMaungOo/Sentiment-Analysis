#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "NLP.h"
#include "TestDb.h"


TEST_CASE("Test1")
{
    TestDb db;

    NLP::NLP nlp{&db};

    std::string sentence = "do not work";

    auto prob = std::move(nlp.analysis(sentence));

    double positive = static_cast<double>(std::get<0>(prob));

    double negative = static_cast<double>(std::get<1>(prob));

    bool is_positive = positive>=0.7352 && positive<=0.7353;

    bool is_negative = negative>=0.2647 && negative<=0.2648;

    REQUIRE(is_positive);
    REQUIRE(is_negative);
}
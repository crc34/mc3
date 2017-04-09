
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "mcmc.h"

TEST_CASE("accept", "[]")
{
    REQUIRE(accept(-1.0, -2.0));

}



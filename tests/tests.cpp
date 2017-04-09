
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <vector>
#include <math.h>
#include "mcmc.h"

using std::vector;

TEST_CASE("accept", "[]")
{
    const double currentProb = 0.5;
    const double proposalProb = 0.4;
    double nAccepts = 0;
    const double n = 10000;
    for(int i = 0; i < n; i++)
    {
        nAccepts += accept(log(proposalProb),  (currentProb));
    }
    nAccepts /= n;
    REQUIRE(abs(nAccepts - proposalProb/currentProb) < 0.05);
}



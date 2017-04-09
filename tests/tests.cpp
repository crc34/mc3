
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <vector>
#include <math.h>
#include <algorithm>
#include "mcmc.h"

using std::vector;

TEST_CASE("accept", "[]")
{
    const double currentProb = 0.5;
    const double proposalProb = 0.4;
    const double n = 10000;
    vector<double> draws(n);
    std::transform(draws.cbegin(), draws.cend(), draws.begin(),
            [=](const double x){return  accept(log(proposalProb),  (currentProb));} );
    const double nAccepts = std::accumulate(draws.cbegin(), draws.cend(), 0) / n;
    REQUIRE(abs(nAccepts - proposalProb/currentProb) < 0.05);
}




#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <vector>
#include <math.h>
#include <algorithm>
#include "mcmc.h"
#include <iostream>

using std::vector;
using std::transform;


std::default_random_engine generator;

TEST_CASE("accept", "[]")
{

    const double n = 10000;
    vector<bool> draws(n, false);

    SECTION("uphill step")
    {
        const double currentProb = 0.5;
        const double proposalProb = 0.9;
        const auto runAccept =  [=](const double x)
        {
            return  accept(log(proposalProb),  log(currentProb), generator);
        };
        transform(draws.cbegin(), draws.cend(), draws.begin(), runAccept);
        const double nAccepts = std::accumulate(draws.cbegin(), draws.cend(), 0)/n;
        std::cout << proposalProb/currentProb << std::endl;
        REQUIRE(abs(nAccepts - proposalProb/currentProb) < 0.05);
    }
    SECTION("downhill step")
    {
        const double currentProb = 0.5;
        const double proposalProb = 0.3;
        const auto runAccept =  [=](const double x)
        {
            return  accept(log(proposalProb),  log(currentProb), generator);
        };
        transform(draws.cbegin(), draws.cend(), draws.begin(), runAccept);
        const double nAccepts = std::accumulate(draws.cbegin(), draws.cend(), 0)/n;
        REQUIRE(abs(nAccepts - proposalProb/currentProb) < 0.05);
    }

}



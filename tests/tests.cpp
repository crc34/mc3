
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <vector>
#include <math.h>
#include <algorithm>
#include "mcmc.h"
#include <iostream>
#include <math.h>

using std::vector;
using std::transform;

std::default_random_engine generator;

double getMean(const vector<double>& x)
{
    return accumulate(x.cbegin(), x.cend(), 0)/x.size();

}

double getSecondMoment(const vector<double>& x)
{
    auto x2 = vector<double>(x.size());
    auto square = [](const double x){return x*x;};
    transform(x.cbegin(), x.cend(), x2.begin(), square);
    return accumulate(x2.cbegin(), x2.cend(), 0);
}

double getVariance(const vector<double>& x)
{
    const auto x2 = getSecondMoment(x);
    const auto mean = getMean(x);
    return x2 - mean*mean;
}

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

TEST_CASE("step", "[]")
{
    const auto rate = 0.78;
    const auto n = 1000000;
    const auto posteriorKernel = [=](const double x){ return rate*exp(-rate*x);} ;
    std::exponential_distribution<double> distribution(rate);
    const auto currentValue = distribution(generator);
    vector<double> draws(n, 0);
    transform(draws.cbegin(), draws.cend(), draws.begin(), posteriorKernel);
    const auto mean = getMean(draws);
    REQUIRE(false);
}

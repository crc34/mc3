#include "mcmc.h"
#include <random>
#include <math.h>
#include <iostream>
std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0.0, 1.0);

bool accept(const double propLL, const double currentLL)
{
    const double draw = log(distribution(generator));
    return draw < propLL - currentLL;
}

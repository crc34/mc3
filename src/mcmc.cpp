#include "mcmc.h"
#include <random>
#include <math.h>

thread_local std::default_random_engine generator;

bool accept(const double propLL, const double currentLL)
{
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    const double draw = log(distribution(generator));
    return draw < propLL - currentLL;
}

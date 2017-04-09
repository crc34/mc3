#include "mcmc.h"
#include <random>
#include <math.h>

thread_local std::default_random_engine generator;
std::uniform_real_distribution<double> stdUnif(0.0, 1.0);

bool accept(const double propLL, const double currentLL)
{
    const double draw = log(stdUnif(generator));
    return draw < propLL - currentLL;
}

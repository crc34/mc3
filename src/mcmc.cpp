#include "mcmc.h"
#include <random>
#include <math.h>
#include <iostream>

bool accept(const double propLL, const double currentLL, std::default_random_engine& generator)
{
    std::uniform_real_distribution<double> stdUnif(0.0, 1.0);
    const double draw = log(stdUnif(generator));
    return draw < propLL - currentLL;
}

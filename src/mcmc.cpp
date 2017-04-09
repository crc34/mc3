#include "mcmc.h"
#include <random>

std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0.0, 1.0);

bool accept(const double propLL, const double currentLL)
{
    return distribution(generator) < propLL - currentLL;
}

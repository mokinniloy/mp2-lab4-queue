#include "gtest.h"
#include "tsystem.hpp"

TEST (TSystem, simulation_test)
{
    TSystem simulation;

    simulation.simulate(1000, 10, .8, .3);
    
    ASSERT_NO_THROW(simulation.printResults());
}
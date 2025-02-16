/*
  test_GA_Evolver.cpp - Testbench for GA_Evolver
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: This module tests the core functionality of GA_Evolver, including
               selection, crossover, and mutation. It ensures that evolution runs
               correctly on a basic population.
*/

#include "GA_Evolver.h"
#include "Population.h"
#include <iostream>

int main() {
    std::cout << "Initializing testbench for GA_Evolver..." << std::endl;
    
    // Initialize a population of 10 individuals
    Population population(10);
    
    // Create an instance of GA_Evolver
    GA_Evolver evolver(0.1, 0.7, 2); // Mutation rate = 10%, Crossover rate = 70%, 2 elites
    
    // Run evolution steps
    std::cout << "Running evolution process..." << std::endl;
    evolver.EvolvePopulation(population);
    
    std::cout << "Test completed!" << std::endl;
    return 0;
}

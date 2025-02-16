/*
  GA_Evolver.h - Header for Genetic Algorithm Evolution
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Defines the core genetic algorithm operations, including selection,
               crossover, and mutation, for evolving populations.
*/

#ifndef GA_EVOLVER_H
#define GA_EVOLVER_H

#include <vector>
#include "Population.h"

class GA_Evolver {
private:
    double mutationRate;
    double crossoverRate;
    int elitismCount;

public:
    GA_Evolver(double mutationRate, double crossoverRate, int elitismCount);
    
    void EvolvePopulation(Population& population);  // Performs selection, crossover, and mutation
    
    void Select(Population& population);  // Selects parents based on fitness
    
    void Crossover(Population& population);  // Performs genetic crossover
    
    void Mutate(Population& population);  // Applies mutation to offspring
};

#endif // GA_EVOLVER_H

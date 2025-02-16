/*
  Population.h - Defines Population Class for Genetic Algorithm
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: This module defines the population structure used in the
               genetic algorithm. It maintains a collection of individuals
               and provides methods for evaluating fitness and accessing individuals.
*/

#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include "BaseSpecies.h"

class Population {
private:
    std::vector<BaseSpecies> individuals;
    int populationSize;

public:
    Population(int size);
    void EvaluateFitness();
    BaseSpecies& GetIndividual(int index);
    int GetSize() const;
};

#endif // POPULATION_H

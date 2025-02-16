/*
  BaseSpecies.h - Base Class for Species in Genetic Algorithm
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: This module defines a generic species that can be evolved by
               the genetic algorithm. Each species has a fitness value and 
               basic operations for mutation and crossover.
*/

#ifndef BASESPECIES_H
#define BASESPECIES_H

class BaseSpecies {
private:
    double fitness;

public:
    BaseSpecies();
    void CalculateFitness();
    double GetFitness() const;
    void Mutate();
};

#endif // BASESPECIES_H
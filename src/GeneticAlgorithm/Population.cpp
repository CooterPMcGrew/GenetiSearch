/*
  Population.cpp - Implementation of Population Class for Genetic Algorithm
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: This module implements the population structure used in the
               genetic algorithm. It initializes a population of individuals
               and provides basic fitness evaluation.
*/

#include "Population.h"
#include <iostream>

// Constructor: Initializes a population with the given size
Population::Population(int size) : populationSize(size) {
    for (int i = 0; i < size; i++) {
        individuals.push_back(BaseSpecies()); // Placeholder for actual species initialization
    }
}

// Evaluates fitness of all individuals (To be implemented properly later)
void Population::EvaluateFitness() {
    std::cout << "Evaluating fitness of all individuals..." << std::endl;
    for (auto& individual : individuals) {
        individual.CalculateFitness(); // Assuming BaseSpecies has a CalculateFitness() function
    }
}

// Returns a reference to an individual at the given index
BaseSpecies& Population::GetIndividual(int index) {
    return individuals[index];
}

// Returns the total population size
int Population::GetSize() const {
    return populationSize;
}

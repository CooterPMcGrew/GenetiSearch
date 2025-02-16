/*
  BaseSpecies.cpp - Implementation of BaseSpecies Class
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Implements the basic properties of a species in the genetic algorithm,
               including fitness calculation and mutation operations.
*/

#include "BaseSpecies.h"
#include <iostream>
#include <cstdlib>

// Constructor: Initializes a species with default fitness value
BaseSpecies::BaseSpecies() : fitness(0.0) {}

// Calculates fitness (Placeholder logic)
void BaseSpecies::CalculateFitness() {
    fitness = static_cast<double>(rand() % 100) / 100.0; // Random fitness between 0.0 and 1.0
}

// Returns fitness value
double BaseSpecies::GetFitness() const {
    return fitness;
}

// Mutates the species (Placeholder logic)
void BaseSpecies::Mutate() {
    fitness += (static_cast<double>(rand() % 20) - 10) / 100.0; // Small random mutation
    if (fitness < 0.0) fitness = 0.0;
    if (fitness > 1.0) fitness = 1.0;
}

/*
  BaseAgent.cpp - Implementation of BaseAgent Class
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Implements the BaseAgent class, providing fundamental
               methods for fitness handling and initialization.
*/

#include "BaseAgent.h"

// Constructor: Initializes fitness to 0.0
BaseAgent::BaseAgent() : fitness(0.0) {}

// Getter for fitness value
double BaseAgent::GetFitness() const {
    return fitness;
}

// Setter for fitness value
void BaseAgent::SetFitness(double value) {
    fitness = value;
}

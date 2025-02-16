/*
  GeneticAgent.cpp - Implementation of GeneticAgent
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.4
  Description: Holds genes in an unordered_map, ensuring full modularity.
*/

#include "GeneticAgent.h"
#include <iostream>

GeneticAgent::GeneticAgent(int start_x, int start_y, int initial_stamina, const std::unordered_map<std::string, double>& inputGenes)
    : SensorAgent(start_x, start_y, initial_stamina), genes(inputGenes) {}

void GeneticAgent::ApplyGenes() {
    if (genes.at("movementBias") > 0) Move("FOOD_DIR");
    else Move("RANDOM");

    stamina -= genes.at("metabolism");
    if (stamina < 0) stamina = 0;
}

void GeneticAgent::PrintGenes() const {
    for (const auto& pair : genes) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;
}

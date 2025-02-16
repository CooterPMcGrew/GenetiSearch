/*
  Population.cpp - Fully Modular Genetic Algorithm
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.4
  Description: Evolves unordered_map genes without any dependencies.
*/

#include "Population.h"

Population::Population(std::vector<std::unordered_map<std::string, double>> initial_genes) 
    : geneticPool(initial_genes) {}

std::vector<std::unordered_map<std::string, double>> Population::Evolve() {
    // ✅ Sort genes by fitness (assuming better metabolism = better survival)
    std::sort(geneticPool.begin(), geneticPool.end(), [](const auto& g1, const auto& g2) {
        return g1.at("metabolism") > g2.at("metabolism");
    });

    std::vector<std::unordered_map<std::string, double>> newGeneration;
    
    // ✅ Breed the fittest genes
    for (size_t i = 0; i < geneticPool.size() / 2; ++i) {
        for (size_t j = i + 1; j < geneticPool.size() / 2; ++j) {
            auto childGenes = Crossover(geneticPool[i], geneticPool[j]);
            Mutate(childGenes);
            newGeneration.push_back(childGenes);
        }
    }

    return newGeneration;
}

std::unordered_map<std::string, double> Population::Crossover(const std::unordered_map<std::string, double>& g1, const std::unordered_map<std::string, double>& g2) {
    std::unordered_map<std::string, double> child;
    child["movementBias"] = (g1.at("movementBias") + g2.at("movementBias")) / 2;
    child["sensingRange"] = (rand() % 2) ? g1.at("sensingRange") : g2.at("sensingRange");
    child["riskTolerance"] = (g1.at("riskTolerance") + g2.at("riskTolerance")) / 2;
    child["metabolism"] = (rand() % 2) ? g1.at("metabolism") : g2.at("metabolism");
    return child;
}

void Population::Mutate(std::unordered_map<std::string, double>& g) {
    if (rand() % 100 < 10) g["movementBias"] += ((rand() % 20) - 10) / 100.0;
    if (rand() % 100 < 10) g["sensingRange"] = std::max(1.0, g["sensingRange"] + (rand() % 3 - 1));
    if (rand() % 100 < 10) g["riskTolerance"] += ((rand() % 20) - 10) / 100.0;
    if (rand() % 100 < 10) g["metabolism"] = std::max(1.0, g["metabolism"] + (rand() % 3 - 1));
}

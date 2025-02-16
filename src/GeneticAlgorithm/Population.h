/*
  Population.h - Fully Modular Genetic Algorithm
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.4
  Description: Evolves generic unordered_map genes without knowing about agents.
*/

#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cstdlib>

class Population {
private:
    std::vector<std::unordered_map<std::string, double>> geneticPool;  // ✅ No agent references

public:
    Population(std::vector<std::unordered_map<std::string, double>> initial_genes);
    
    std::vector<std::unordered_map<std::string, double>> Evolve();
    void Mutate(std::unordered_map<std::string, double>& g);
    std::unordered_map<std::string, double> Crossover(const std::unordered_map<std::string, double>& g1, const std::unordered_map<std::string, double>& g2);
};

#endif // POPULATION_H

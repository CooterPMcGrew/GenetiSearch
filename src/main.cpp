#include "Agents/GeneticAgent.h"
#include "GeneticAlgorithm/Population.h"
#include <iostream>

int main() {
    // ✅ Define genes explicitly
    std::vector<std::unordered_map<std::string, double>> initialGenes = {
        {{"speed", 5}, {"muscle_strength", 0.8}, {"sense_range", 3}},
        {{"speed", 3}, {"muscle_strength", 0.5}, {"sense_range", 2}},
        {{"speed", 7}, {"muscle_strength", 0.6}, {"sense_range", 4}},
        {{"speed", 2}, {"muscle_strength", 0.9}, {"sense_range", 1}},
        {{"speed", 6}, {"muscle_strength", 0.4}, {"sense_range", 5}}
    };

    Population population(initialGenes);
    std::vector<GeneticAgent> agents;

    // ✅ Create agents from genes
    for (const auto& g : initialGenes) {
        agents.emplace_back(2, 2, 10, g);
    }

    // ✅ Evolve and re-create agents
    auto newGenes = population.Evolve();
    agents.clear();
    for (const auto& g : newGenes) {
        agents.emplace_back(2, 2, 10, g);
    }

    return 0;
}

/*
  GeneticAgent.h - Completely Modular Genetic Algorithm-Driven Agent
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.4
  Description: Does NOT include anything from Population. Stores genes generically.
*/

#ifndef GENETIC_AGENT_H
#define GENETIC_AGENT_H

#include "SensorAgent.h"
#include <unordered_map>
#include <string>

class GeneticAgent : public SensorAgent {
private:
    std::unordered_map<std::string, double> genes;  // ✅ No external includes!

public:
    GeneticAgent(int start_x, int start_y, int initial_stamina, const std::unordered_map<std::string, double>& inputGenes);
    
    void ApplyGenes();
    std::unordered_map<std::string, double> GetGenes() const { return genes; }
    void SetGenes(const std::unordered_map<std::string, double>& newGenes) { genes = newGenes; }
    void PrintGenes() const;
};

#endif // GENETIC_AGENT_H

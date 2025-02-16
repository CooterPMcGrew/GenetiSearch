/*
  BaseAgent.h - Base Class for Species in Genetic Algorithm
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Defines a generic agent (species) that can be evolved
               within the genetic algorithm framework.
*/

#ifndef BASE_AGENT_H
#define BASE_AGENT_H

class BaseAgent {
protected:
    double fitness; // Fitness score of the agent

public:
    BaseAgent();
    virtual ~BaseAgent() = default;

    virtual void CalculateFitness() = 0; // Pure virtual function for fitness calculation
    virtual void Mutate() = 0;           // Pure virtual function for mutation

    double GetFitness() const;
    void SetFitness(double value);
};

#endif // BASE_AGENT_H


/*
  BaseAgent.h - Base Class for Species in Genetic Algorithm
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.3
  Description: Defines a generic agent that can interact with an environment
               via message passing instead of direct dependencies.
*/

#ifndef BASE_AGENT_H
#define BASE_AGENT_H

#include <string>

class BaseAgent {
protected:
    double fitness; // Fitness score

public:
    BaseAgent();
    virtual ~BaseAgent() = default;

    // Agents send a signal (interaction) to the environment
    virtual std::string SendSignal() = 0;

    // Agents receive a response from the environment
    virtual void ReceiveSignal(const std::string& response) = 0;

    // Get and set agent fitness
    double GetFitness() const;
    void SetFitness(double value);  // 🔹 **Fix: Add missing declaration**
};

#endif // BASE_AGENT_H

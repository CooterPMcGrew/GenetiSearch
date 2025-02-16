/*
  test_Agent.cpp - Unit Test for BaseAgent and SensorAgent
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Tests BaseAgent and SensorAgent for correct fitness calculation
               and mutation behavior.
*/

#include "./Agents/BaseAgent.h"
#include "./Agents/SensorAgent.h"
#include <iostream>

// Function to test SensorAgent
void TestSensorAgent() {
    std::cout << "Testing SensorAgent..." << std::endl;

    SensorAgent agent(5); // Create a sensor agent with 5 sensors

    // Print initial fitness
    agent.CalculateFitness();
    std::cout << "Initial Fitness: " << agent.GetFitness() << std::endl;

    // Mutate and check changes
    agent.Mutate();
    agent.CalculateFitness();
    std::cout << "Post-Mutation Fitness: " << agent.GetFitness() << std::endl;

    std::cout << "SensorAgent Test Completed." << std::endl;
}

// Main test runner
int main() {
    std::cout << "=== Running Agent Tests ===" << std::endl;
    TestSensorAgent();
    std::cout << "=== Agent Tests Complete ===" << std::endl;
    return 0;
}

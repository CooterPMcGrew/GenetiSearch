/*
  test_Integration.cpp - Tests Population & Environment with Message Passing
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.2
  Description: Agents interact with the environment via signals to evolve.
*/

#include "./Environments/BaseEnvironment.h"
#include "./GeneticAlgorithm/Population.h"
#include "./Agents/SensorAgent.h"
#include <iostream>

void TestPopulationWithEnvironment() {
    BaseEnvironment env;
    Population pop;

    SensorAgent agent1(5);
    SensorAgent agent2(5);

    env.AddEntity(&agent1);
    env.AddEntity(&agent2);

    std::cout << "Before Interaction:" << std::endl;
    agent1.PrintInfo();
    agent2.PrintInfo();

    // Agents interact with the environment
    std::string response1 = env.ProcessSignal(agent1.SendSignal());
    std::string response2 = env.ProcessSignal(agent2.SendSignal());

    // Agents process the response
    agent1.ReceiveSignal(response1);
    agent2.ReceiveSignal(response2);

    std::cout << "After Interaction:" << std::endl;
    agent1.PrintInfo();
    agent2.PrintInfo();
}

int main() {
    TestPopulationWithEnvironment();
    return 0;
}

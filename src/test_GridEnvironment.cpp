/*
  test_GridEnvironment.cpp - Tests Genetic Evolution in a Grid Environment
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.2
  Description: Runs multiple generations of GeneticAgents in a 2D grid environment.
               Logs results until all agents run out of stamina.
*/

#include "../Environments/GridEnvironment.h"
#include "../Agents/GeneticAgent.h"
#include "../GeneticAlgorithm/Population.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>

// ✅ Function to generate a timestamped filename
std::string GenerateFilename() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    std::ostringstream filename;
    filename << "build/results/test_GridEnvironment_"
             << (localTime->tm_year + 1900) << "-"
             << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1) << "-"
             << std::setw(2) << std::setfill('0') << localTime->tm_mday << "_"
             << std::setw(2) << std::setfill('0') << localTime->tm_hour << "-"
             << std::setw(2) << std::setfill('0') << localTime->tm_min << "-"
             << std::setw(2) << std::setfill('0') << localTime->tm_sec
             << ".txt";
    return filename.str();
}

// ✅ Main Test Function
void TestGridEnvironment() {
    GridEnvironment env(10, 10, 5, 5);  // 10x10 grid, 5 food, 5 enemies

    // ✅ Create initial agents
    std::vector<Evolvable*> agents;
    agents.push_back(new GeneticAgent(2, 2, 10, Genes()));
    agents.push_back(new GeneticAgent(3, 3, 10, Genes()));
    agents.push_back(new GeneticAgent(4, 4, 10, Genes()));
    agents.push_back(new GeneticAgent(5, 5, 10, Genes()));
    agents.push_back(new GeneticAgent(6, 6, 10, Genes()));

    Population population(agents);

    Population population(agents);

    // ✅ Create results directory if it doesn’t exist
    system("mkdir -p build/results");

    // ✅ Open the results file
    std::ofstream resultsFile(GenerateFilename());
    resultsFile << "=== Grid Environment Genetic Evolution Test ===\n";
    resultsFile << "Starting with 5 agents in a 10x10 environment.\n\n";

    for (int generation = 0; generation < 20; ++generation) {
        resultsFile << "=== Generation " << generation << " ===\n";

        int round = 0;
        while (!population.IsEmpty()) {
            resultsFile << "=== Round " << round++ << " ===\n";

            for (size_t i = 0; i < population.Size(); ++i) {
                GeneticAgent* agent = dynamic_cast<GeneticAgent*>(population.GetAgent(i));
                if (!agent) continue;

                // ✅ Agents "look" before moving
                std::string look_response = env.ProcessSignal(agent->GetX(), agent->GetY(), "LOOK");
                agent->ReceiveSignal(look_response);

                // ✅ Move and process interactions
                std::string move_response = env.ProcessSignal(agent->GetX(), agent->GetY(), "MOVE");
                agent->ReceiveSignal(move_response);

                resultsFile << "Agent " << i + 1 << " - Pos: (" << agent->GetX() << "," << agent->GetY()
                            << ") | Fitness: " << agent->GetFitness() << " | Stamina: " << agent->GetStamina()
                            << " | Movement Bias: " << agent->GetGenes().movementBias
                            << " | Sensing Range: " << agent->GetGenes().sensingRange << "\n";
            }

            // ✅ Remove dead agents (stamina <= 0)
            population.RemoveDeadAgents();

            resultsFile << "Active Agents: " << population.Size() << "\n\n";
        }

        // ✅ Run genetic algorithm after each generation
        population.Evolve();
    }

    resultsFile << "=== Simulation Complete ===\n";
    resultsFile.close();
}

// ✅ Entry Point
int main() {
    TestGridEnvironment();
    return 0;
}

🧬 GenetiSearch: A Domain-Agnostic Genetic Algorithm Solver
A modular, fully customizable Genetic Algorithm framework for solving optimization problems in any domain.

🔹 Overview
GenetiSearch is a data-agnostic, domain-independent genetic algorithm (GA) solver. It allows users to evolve solutions to any problem space, from AI-driven simulations to scientific optimization.

Unlike traditional GA implementations tied to specific problems (e.g., neural networks, game AI, or control systems), GenetiSearch is designed to be modular, allowing seamless integration with any problem domain without modifying the core GA engine.

🔹 Features
✅ Fully Modular Design → Agents, Environments, and Genetic Algorithms are independent.
✅ No Inter-Module Dependencies → Ensures each component can be tested and improved separately.
✅ Domain-Agnostic → Use for robotics, AI, circuit design, DSP optimization, or simulation.
✅ Custom Gene Structures → Define genes as key-value pairs (std::unordered_map) for flexibility.
✅ Pluggable Environments → Agents interact with any problem space via message-passing.
✅ Crossover & Mutation → Customizable evolution logic based on fitness scoring.

🔹 Code Structure
bash
Copy
Edit
GenetiSearch/
│── src/
│   ├── Agents/              # Standalone agent definitions (do not include GA logic)
│   │   ├── BaseAgent.h/.cpp
│   │   ├── SensorAgent.h/.cpp
│   │   ├── GeneticAgent.h/.cpp    # Only stores genes, does not evolve them
│   │
│   ├── Environments/        # Standalone problem spaces (e.g., grid, simulations)
│   │   ├── BaseEnvironment.h/.cpp
│   │   ├── GridEnvironment.h/.cpp
│   │
│   ├── GeneticAlgorithm/    # Core GA logic (independent of agents)
│   │   ├── Population.h/.cpp      # Manages evolution
│   │   ├── Genes.h/.cpp           # Generic gene representation
│   │
│   ├── main.cpp             # Connects Agents, GA, and Environments
│
│── build/                   # Compiled executables
│── results/                 # Test output logs
│── README.md                # This file!
│── CMakeLists.txt           # Build system
│── .gitignore               # Ignored files (build outputs, logs, etc.)
🔹 How It Works
1️⃣ Define a Genetic Agent
Unlike traditional fixed-size genome models, GenetiSearch uses dynamic gene structures:

cpp
Copy
Edit
std::unordered_map<std::string, double> agentGenes = {
    {"speed", 5.0},
    {"muscle_strength", 0.8},
    {"sense_range", 3.0}
};

GeneticAgent agent(2, 2, 10, agentGenes);
2️⃣ Create a Population
The Genetic Algorithm (GA) module manages genes independently from agents:

cpp
Copy
Edit
std::vector<std::unordered_map<std::string, double>> initialGenes = {
    {{"speed", 5}, {"muscle_strength", 0.8}, {"sense_range", 3}},
    {{"speed", 3}, {"muscle_strength", 0.5}, {"sense_range", 2}}
};

Population population(initialGenes);
3️⃣ Run Evolution
GenetiSearch evolves genes over multiple generations, optimizing fitness:

cpp
Copy
Edit
auto newGenes = population.Evolve();
4️⃣ Plug It Into Any Problem
Whether you are simulating AI creatures, DSP optimizations, circuit layouts, or financial strategies, you can use GeneticAgent and Population to evolve optimal solutions.

🔹 Installation & Compilation
🔧 Prerequisites
C++17 or higher
CMake (cmake ..)
MinGW or another C++ compiler
🔨 Build & Run
sh
Copy
Edit
mkdir build && cd build
cmake ..
make
./GenetiSearch
🧪 Run Tests
sh
Copy
Edit
./build/test_GridEnvironment.exe
🔹 Future Plans
🏗 Multi-threaded evolution for large populations
🔀 More crossover & mutation strategies
🌎 Web-based UI for live evolution tracking
🧠 Integration with neural networks
📜 License
MIT License - Free to use and modify.

# Gather all .cpp files (excluding test_GA_Evolver.cpp from main build)
file(GLOB_RECURSE SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/src/GeneticAlgorithm/test_GA_Evolver.cpp") # Correct path

# Create main executable
add_executable(GenetiSearch ${SOURCES})

# Ensure test executable is built correctly
add_executable(test_GA 
    src/GeneticAlgorithm/test_GA_Evolver.cpp 
    src/GeneticAlgorithm/GA_Evolver.cpp 
    src/GeneticAlgorithm/Population.cpp 
    src/GeneticAlgorithm/BaseSpecies.cpp
)

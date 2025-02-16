/*
  test_Environment.cpp - Unit Test for BaseEnvironment
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Tests BaseEnvironment for correct entity storage and retrieval.
*/

#include "./Environments/BaseEnvironment.h"
#include <iostream>

// Dummy entity for testing
struct TestEntity {
    int id;
    TestEntity(int i) : id(i) {}
};

// Function to test BaseEnvironment
void TestBaseEnvironment() {
    std::cout << "Testing BaseEnvironment..." << std::endl;

    BaseEnvironment env;

    // Create test entities
    TestEntity entity1(1);
    TestEntity entity2(2);

    // Add entities to the environment
    env.AddEntity(&entity1);
    env.AddEntity(&entity2);

    // Retrieve entities
    const std::vector<void*>& entities = env.GetEntities();
    
    std::cout << "Number of Entities in Environment: " << entities.size() << std::endl;

    // Verify entity IDs (requires casting)
    for (size_t i = 0; i < entities.size(); ++i) {
        TestEntity* ent = static_cast<TestEntity*>(entities[i]);
        std::cout << "Entity " << i + 1 << " ID: " << ent->id << std::endl;
    }

    std::cout << "BaseEnvironment Test Completed." << std::endl;
}

// Main test runner
int main() {
    std::cout << "=== Running Environment Tests ===" << std::endl;
    TestBaseEnvironment();
    std::cout << "=== Environment Tests Complete ===" << std::endl;
    return 0;
}

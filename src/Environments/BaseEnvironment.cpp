/*
  BaseEnvironment.cpp - Implementation of Generic Environment
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.2
  Description: Processes interaction signals from entities.
*/

#include "BaseEnvironment.h"
#include <iostream>

// Adds an entity to the environment
void BaseEnvironment::AddEntity(void* entity) {
    entities.push_back(entity);
}

// Processes a signal and returns a response
std::string BaseEnvironment::ProcessSignal(const std::string& signal) {
    // Example: If sensors detect high values, return "GOOD"
    if (signal.find("SENSOR_DATA") != std::string::npos) {
        return (rand() % 2 == 0) ? "GOOD" : "BAD"; // Random response
    }
    return "NEUTRAL";
}

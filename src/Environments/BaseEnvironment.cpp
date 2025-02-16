/*
  BaseEnvironment.cpp - Implementation of BaseEnvironment
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Implements methods for storing and retrieving entities
               within a generic environment.
*/

#include "BaseEnvironment.h"

// Adds an entity to the environment
void BaseEnvironment::AddEntity(void* entity) {
    entities.push_back(entity);
}

// Returns all stored entities
const std::vector<void*>& BaseEnvironment::GetEntities() const {
    return entities;
}

/*
  BaseEnvironment.h - Abstract Environment Class
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Defines a generic environment that holds entities,
               independent of agents or genetic algorithms.
*/

#ifndef BASE_ENVIRONMENT_H
#define BASE_ENVIRONMENT_H

#include <vector>

class BaseEnvironment {
protected:
    std::vector<void*> entities; // Generic container for any object type

public:
    BaseEnvironment() = default;
    virtual ~BaseEnvironment() = default;

    // Adds a generic entity to the environment
    void AddEntity(void* entity);

    // Returns all entities in the environment
    const std::vector<void*>& GetEntities() const;
};

#endif // BASE_ENVIRONMENT_H

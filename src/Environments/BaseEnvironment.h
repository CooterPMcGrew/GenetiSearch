/*
  BaseEnvironment.h - Generic Environment for Interaction-Based Evolution
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.2
  Description: Environment processes interaction signals instead of directly
               referencing agent objects.
*/

#ifndef BASE_ENVIRONMENT_H
#define BASE_ENVIRONMENT_H

#include <vector>
#include <string>

class BaseEnvironment {
private:
    std::vector<void*> entities; // Generic storage for all environment objects

public:
    BaseEnvironment() = default;
    virtual ~BaseEnvironment() = default;

    // Adds a generic entity to the environment
    void AddEntity(void* entity);

    // Processes interaction signals and returns a response
    virtual std::string ProcessSignal(const std::string& signal);
};

#endif // BASE_ENVIRONMENT_H

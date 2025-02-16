/*
  SensorAgent.cpp - Implementation of Sensor-Based Agent with Grid Movement
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Implements an agent that moves, detects food/enemies,
               and updates fitness based on survival.
*/

#include "SensorAgent.h"
#include <cstdlib>

// Constructor initializes position and stamina
SensorAgent::SensorAgent(int start_x, int start_y, int initial_stamina) 
    : x(start_x), y(start_y), stamina(initial_stamina) {}

// Agent sends a signal to the environment to "sense" surroundings
std::string SensorAgent::SendSignal() {
    return "LOOK";  // Requests distances to food/enemies
}

// Agent receives response and updates its state
void SensorAgent::ReceiveSignal(const std::string& response) {
    if (response.find("EAT") != std::string::npos) {
        fitness += 10;
        stamina += 2;  // ✅ Regain stamina from eating food
        if (stamina > 10) stamina = 10; 
    } 
    else if (response.find("DAMAGE") != std::string::npos) {
        fitness -= 10;
        stamina -= 2;  // ✅ Lose extra stamina when touching an enemy
        if (stamina < 0) stamina = 0;  // Ensure stamina doesn't go negative
    }
    else if (response.find("FOOD_DIR:") != std::string::npos) {
        std::string direction = response.substr(9);  // Extract movement direction
        Move(direction);  // Move toward food instead of random movement
    }
}

// Moves the agent in a random direction
void SensorAgent::Move(const std::string& direction) {
    if (direction == "UP") y -= 1;
    else if (direction == "DOWN") y += 1;
    else if (direction == "LEFT") x -= 1;
    else if (direction == "RIGHT") x += 1;

    stamina -= 1;  // Movement reduces stamina
}

// Prints agent state
void SensorAgent::PrintInfo() const {
    std::cout << "Pos: (" << x << "," << y << ") | Fitness: " << fitness << " | Stamina: " << stamina << std::endl;
}
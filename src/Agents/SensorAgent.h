/*
  SensorAgent.h - Sensor-Based Agent with Grid Movement
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.2
  Description: Defines a sensor-based agent that moves in a 2D environment,
               senses food/enemies, and evolves survival strategies.
*/

#ifndef SENSOR_AGENT_H
#define SENSOR_AGENT_H

#include "BaseAgent.h"
#include <iostream>
#include <string>

class SensorAgent : public BaseAgent {
private:
    int x, y; // Position in the grid
    int stamina; // Movement energy

public:
    // ✅ Fix: Ensure constructor matches .cpp file
    SensorAgent(int start_x, int start_y, int initial_stamina);

    // ✅ Fix: Only declare Move() once
    void Move(const std::string& direction);
    void PrintInfo() const;

    // Agent senses surroundings and makes a decision
    std::string SendSignal() override;

    // Agent processes environment response
    void ReceiveSignal(const std::string& response);

    // ✅ Fix: Allow access to x and y via getter functions
    int GetX() const { return x; }
    int GetY() const { return y; }
    // ✅ Fix: Add stamina getter function in SensorAgent.h
    int GetStamina() const { return stamina; }
};

#endif // SENSOR_AGENT_H

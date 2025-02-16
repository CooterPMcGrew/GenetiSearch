/*
  SensorAgent.h - Derived Class from BaseAgent with Sensor Capabilities
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Defines an agent with sensory inputs that affect evolution.
*/

#ifndef SENSOR_AGENT_H
#define SENSOR_AGENT_H

#include "BaseAgent.h"
#include <vector>

class SensorAgent : public BaseAgent {
private:
    std::vector<double> sensors; // Sensor values

public:
    SensorAgent(int numSensors);
    void CalculateFitness() override; // Implements fitness based on sensors
    void Mutate() override;           // Implements mutation for sensor values
    void SetSensorValue(int index, double value);
    double GetSensorValue(int index) const;
};

#endif // SENSOR_AGENT_H

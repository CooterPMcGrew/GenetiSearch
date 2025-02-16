/*
  SensorAgent.cpp - Implementation of SensorAgent Class
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Implements the SensorAgent class, providing methods for
               sensor-based fitness calculation and mutation.
*/

#include "SensorAgent.h"
#include <cstdlib>
#include <iostream>

// Constructor: Initializes sensor values to random numbers
SensorAgent::SensorAgent(int numSensors) : sensors(numSensors, 0.0) {
    for (double &sensor : sensors) {
        sensor = static_cast<double>(rand() % 100) / 100.0; // Randomize sensors between 0.0 and 1.0
    }
}

// Calculate fitness based on sensor values (sum of all sensors as a placeholder)
void SensorAgent::CalculateFitness() {
    fitness = 0.0;
    for (const double &sensor : sensors) {
        fitness += sensor;
    }
}

// Mutate sensor values slightly
void SensorAgent::Mutate() {
    for (double &sensor : sensors) {
        sensor += (static_cast<double>(rand() % 20) - 10) / 100.0; // Small mutation
        if (sensor < 0.0) sensor = 0.0;
        if (sensor > 1.0) sensor = 1.0;
    }
}

// Set a specific sensor value
void SensorAgent::SetSensorValue(int index, double value) {
    if (index >= 0 && index < sensors.size()) {
        sensors[index] = value;
    }
}

// Get a specific sensor value
double SensorAgent::GetSensorValue(int index) const {
    if (index >= 0 && index < sensors.size()) {
        return sensors[index];
    }
    return 0.0; // Default return value for invalid index
}

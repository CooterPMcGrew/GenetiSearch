/*
  GridEnvironment.cpp - Implementation of 2D Grid Environment
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Implements the environment where agents move, 
               detect food/enemies, and interact via signals.
*/

#include "GridEnvironment.h"
#include <iostream>
#include <cstdlib>

// Constructor: Initializes grid and places food/enemies
GridEnvironment::GridEnvironment(int w, int h, int num_food, int num_enemies) 
    : width(w), height(h), grid(h, std::vector<char>(w, '.')) {

    // Randomly place food
    for (int i = 0; i < num_food; ++i) {
        int x = rand() % width;
        int y = rand() % height;
        grid[y][x] = 'F';
    }

    // Randomly place enemies
    for (int i = 0; i < num_enemies; ++i) {
        int x = rand() % width;
        int y = rand() % height;
        grid[y][x] = 'E';
    }
}

// Processes a signal from an agent
std::string GridEnvironment::ProcessSignal(int x, int y, const std::string& action) {
    if (action == "LOOK") {
        int closest_food_dist = width + height;
        std::string food_direction = "NONE";

        // Search in all 4 directions
        for (int dx = -5; dx <= 5; dx++) {
            for (int dy = -5; dy <= 5; dy++) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                    if (grid[ny][nx] == 'F') {
                        int dist = abs(dx) + abs(dy);
                        if (dist < closest_food_dist) {
                            closest_food_dist = dist;
                            if (abs(dx) > abs(dy)) {
                                food_direction = (dx < 0) ? "LEFT" : "RIGHT";
                            } else {
                                food_direction = (dy < 0) ? "UP" : "DOWN";
                            }
                        }
                    }
                }
            }
        }
        return "FOOD_DIR:" + food_direction;
    } 
    else if (action == "MOVE") {
        if (grid[y][x] == 'F') {
            grid[y][x] = '.';  // ✅ Remove food from the grid
            RespawnFood();  // ✅ Respawn food in a new random location
            return "EAT";
        }
        if (grid[y][x] == 'E') return "DAMAGE";
    }
    return "NEUTRAL";
}

// ✅ Function to respawn food in an empty location
void GridEnvironment::RespawnFood() {
    int x, y;
    do {
        x = rand() % width;
        y = rand() % height;
    } while (grid[y][x] != '.');  // Ensure food appears in an empty space

    grid[y][x] = 'F';
}

// Prints the grid (for debugging)
void GridEnvironment::PrintGrid() const {
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

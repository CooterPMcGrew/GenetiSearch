/*
  GridEnvironment.h - 2D Grid Environment with Food & Enemies
  Author: Cooter McGrew
  Date: 2025-02-16
  Version: 1.0
  Description: Defines a 2D grid environment where agents can move, 
               detect food/enemies, and evolve strategies.
*/

#ifndef GRID_ENVIRONMENT_H
#define GRID_ENVIRONMENT_H

#include <vector>
#include <string>

class GridEnvironment {
private:
    int width, height;  // Grid dimensions
    std::vector<std::vector<char>> grid; // 2D grid ('F' = Food, 'E' = Enemy, '.' = Empty)

public:
    GridEnvironment(int w, int h, int num_food, int num_enemies);

    // Returns a string response based on an agent's position
    std::string ProcessSignal(int x, int y, const std::string& action);

    // Displays the grid (for debugging)
    void PrintGrid() const;
    void RespawnFood();  // ✅ Add function to respawn food

};

#endif // GRID_ENVIRONMENT_H

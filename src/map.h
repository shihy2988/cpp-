#pragma once

#include <string>
#include <vector>

struct Position {
    int x;
    int y;
};

struct Player {
    int x;
    int y;
};

class Map {
public:
    Map();
    void loadLevel(const std::vector<std::string>& level);
    void print(const Player& player, const std::vector<Position>& boxes) const;
    bool isWall(int x, int y) const;
    bool isGoal(int x, int y) const;
    int rows() const;
    int cols() const;
    const std::vector<std::string>& grid() const;

private:
    std::vector<std::string> grid_;
};

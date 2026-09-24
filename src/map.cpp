#include "map.h"

#include <iostream>

Map::Map() = default;

void Map::loadLevel(const std::vector<std::string>& level) {
    grid_ = level;
}

bool Map::isWall(int x, int y) const {
    if (y < 0 || y >= rows() || x < 0 || x >= cols()) {
        return true;
    }
    return grid_[y][x] == '#';
}

bool Map::isGoal(int x, int y) const {
    if (y < 0 || y >= rows() || x < 0 || x >= cols()) {
        return false;
    }
    return grid_[y][x] == '.';
}

int Map::rows() const {
    return static_cast<int>(grid_.size());
}

int Map::cols() const {
    return rows() == 0 ? 0 : static_cast<int>(grid_[0].size());
}

const std::vector<std::string>& Map::grid() const {
    return grid_;
}

void Map::print(const Player& player, const std::vector<Position>& boxes) const {
    for (int y = 0; y < rows(); ++y) {
        for (int x = 0; x < cols(); ++x) {
            bool playerHere = (player.x == x && player.y == y);
            bool boxHere = false;

            for (const auto& box : boxes) {
                if (box.x == x && box.y == y) {
                    boxHere = true;
                    break;
                }
            }

            if (playerHere && boxHere) {
                std::cout << '@';
            } else if (playerHere) {
                std::cout << '@';
            } else if (boxHere) {
                std::cout << '$';
            } else if (isGoal(x, y)) {
                std::cout << '.';
            } else {
                std::cout << grid_[y][x];
            }
        }
        std::cout << '\n';
    }
}

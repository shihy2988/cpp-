#pragma once

#include <queue>
#include <string>
#include <vector>

#include "map.h"

class Solver {
public:
    static std::string findPath(const Map& map, const Player& start, const Position& target);
};

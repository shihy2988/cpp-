#pragma once

#include <vector>
#include "map.h"

bool tryMovePlayer(Player& player, int dx, int dy, const Map& map, std::vector<Position>& boxes);

#include "player.h"

#include <algorithm>

bool tryMovePlayer(Player& player, int dx, int dy, const Map& map, std::vector<Position>& boxes) {
    int nextX = player.x + dx;
    int nextY = player.y + dy;

    if (map.isWall(nextX, nextY)) {
        return false;
    }

    auto boxIt = std::find_if(boxes.begin(), boxes.end(), [&](const Position& box) {
        return box.x == nextX && box.y == nextY;
    });

    if (boxIt != boxes.end()) {
        int boxNextX = nextX + dx;
        int boxNextY = nextY + dy;

        if (map.isWall(boxNextX, boxNextY)) {
            return false;
        }

        for (const auto& other : boxes) {
            if (other.x == boxNextX && other.y == boxNextY) {
                return false;
            }
        }

        boxIt->x = boxNextX;
        boxIt->y = boxNextY;
    }

    player.x = nextX;
    player.y = nextY;
    return true;
}

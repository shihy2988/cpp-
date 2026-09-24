#pragma once

#include <string>
#include <vector>

#include "map.h"
#include "player.h"

class Game {
public:
    Game();
    void loadLevel(const std::vector<std::string>& level);
    void run();

private:
    Map map_;
    Player player_;
    std::vector<Position> boxes_;
    std::vector<Position> goals_;
    int steps_;

    void parseLevel(const std::vector<std::string>& level);
    bool isWin() const;
    void printBoard() const;
    bool tryMove(int dx, int dy);
};

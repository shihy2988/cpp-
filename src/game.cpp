#include "game.h"

#include <algorithm>
#include <iostream>

Game::Game() : steps_(0) {
    std::vector<std::string> level = {
        "##########",
        "#        #",
        "#   $    #",
        "#   .    #",
        "#   @    #",
        "#        #",
        "##########"
    };
    loadLevel(level);
}

void Game::loadLevel(const std::vector<std::string>& level) {
    parseLevel(level);
}

void Game::parseLevel(const std::vector<std::string>& level) {
    map_.loadLevel(level);
    boxes_.clear();
    goals_.clear();

    for (int y = 0; y < static_cast<int>(level.size()); ++y) {
        for (int x = 0; x < static_cast<int>(level[y].size()); ++x) {
            char ch = level[y][x];

            if (ch == '@' || ch == '+') {
                player_.x = x;
                player_.y = y;
                if (ch == '+') {
                    goals_.push_back({x, y});
                }
            } else if (ch == '$' || ch == '*') {
                boxes_.push_back({x, y});
                if (ch == '*') {
                    goals_.push_back({x, y});
                }
            } else if (ch == '.') {
                goals_.push_back({x, y});
            }
        }
    }
}

bool Game::isWin() const {
    if (boxes_.empty()) {
        return true;
    }

    for (const auto& box : boxes_) {
        bool onGoal = false;
        for (const auto& goal : goals_) {
            if (box.x == goal.x && box.y == goal.y) {
                onGoal = true;
                break;
            }
        }
        if (!onGoal) {
            return false;
        }
    }
    return true;
}

void Game::printBoard() const {
    std::cout << "\n";
    std::cout << "=============================\n";
    std::cout << "  Sokoban Demo\n";
    std::cout << "  步数: " << steps_ << "\n";
    std::cout << "=============================\n";
    map_.print(player_, boxes_);
    std::cout << "=============================\n";
    std::cout << "W A S D -> 移动   Q -> 退出\n";
    std::cout << "=============================\n";
}

bool Game::tryMove(int dx, int dy) {
    int nextX = player_.x + dx;
    int nextY = player_.y + dy;

    if (map_.isWall(nextX, nextY)) {
        return false;
    }

    auto boxIt = std::find_if(boxes_.begin(), boxes_.end(), [&](const Position& box) {
        return box.x == nextX && box.y == nextY;
    });

    if (boxIt != boxes_.end()) {
        int boxNextX = nextX + dx;
        int boxNextY = nextY + dy;

        if (map_.isWall(boxNextX, boxNextY)) {
            return false;
        }

        for (const auto& other : boxes_) {
            if (other.x == boxNextX && other.y == boxNextY) {
                return false;
            }
        }

        boxIt->x = boxNextX;
        boxIt->y = boxNextY;
    }

    player_.x = nextX;
    player_.y = nextY;
    ++steps_;
    return true;
}

void Game::run() {
    while (true) {
        printBoard();

        if (isWin()) {
            std::cout << "恭喜你！所有箱子都到达目标点了！\n";
            break;
        }

        std::cout << "请输入操作 (W/A/S/D/Q): ";
        char ch;
        std::cin >> ch;

        switch (ch) {
            case 'W':
            case 'w':
                tryMove(0, -1);
                break;
            case 'S':
            case 's':
                tryMove(0, 1);
                break;
            case 'A':
            case 'a':
                tryMove(-1, 0);
                break;
            case 'D':
            case 'd':
                tryMove(1, 0);
                break;
            case 'Q':
            case 'q':
                std::cout << "游戏退出。\n";
                return;
            default:
                std::cout << "无效输入。\n";
                break;
        }
    }
}

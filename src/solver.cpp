#include "solver.h"

#include <queue>
#include <vector>
#include <utility>

std::string Solver::findPath(const Map& map, const Player& start, const Position& target) {
    const int rows = map.rows();
    const int cols = map.cols();

    if (rows == 0 || cols == 0) {
        return "";
    }

    std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, 0));
    std::vector<std::vector<std::pair<int, int>>> parent(rows, std::vector<std::pair<int, int>>(cols, {-1, -1}));
    std::vector<std::vector<char>> moveDir(rows, std::vector<char>(cols, ' '));

    std::queue<std::pair<int, int>> q;
    q.push({start.y, start.x});
    visited[start.y][start.x] = 1;

    const std::vector<std::pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    bool found = false;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int cy = cur.first;
        int cx = cur.second;

        if (cx == target.x && cy == target.y) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int ny = cy + directions[i].first;
            int nx = cx + directions[i].second;

            if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) {
                continue;
            }

            if (visited[ny][nx]) {
                continue;
            }

            if (map.isWall(nx, ny)) {
                continue;
            }

            visited[ny][nx] = 1;
            parent[ny][nx] = {cx, cy};

            if (i == 0) moveDir[ny][nx] = 'R';
            else if (i == 1) moveDir[ny][nx] = 'D';
            else if (i == 2) moveDir[ny][nx] = 'L';
            else if (i == 3) moveDir[ny][nx] = 'U';

            q.push({ny, nx});
        }
    }

    if (!found) {
        return "";
    }

    std::string path;
    int x = target.x;
    int y = target.y;

    while (!(x == start.x && y == start.y)) {
        char step = moveDir[y][x];
        if (step == ' ') {
            break;
        }
        path.push_back(step);

        int px = parent[y][x].first;
        int py = parent[y][x].second;
        x = px;
        y = py;
    }

    std::reverse(path.begin(), path.end());
    return path;
}

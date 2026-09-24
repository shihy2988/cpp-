# C++ Sokoban 控制台游戏学习项目

这是一个面向 C++ 零基础入门者的推箱子练习项目，目标是：

- 理解 C++ 基础语法
- 通过推箱子游戏实践顺序/分支/循环
- 逐步掌握数组、字符串、函数、结构体
- 引入搜索与状态管理思想

## 目录结构

```text
src/
├── main.cpp
├── map.h
├── map.cpp
├── player.h
├── player.cpp
├── game.h
├── game.cpp
├── solver.h
├── solver.cpp
└── README.md
```

## 运行方式

在项目根目录执行：

```bash
g++ src/main.cpp src/map.cpp src/player.cpp src/game.cpp src/solver.cpp -std=c++17 -O2 -o sokoban
./sokoban
```

## 游戏规则

- `W/A/S/D`：上下左右移动
- `Q`：退出游戏
- `H`：提示一条最短路径（基于 BFS）
- 把所有箱子推到目标点即可胜利

## 当前版本功能

- 地图渲染
- 玩家移动
- 碰撞检测
- 推箱子逻辑
- 目标点检测
- 胜利判定
- 自动寻路提示

## 学习建议

1. 先阅读 `src/main.cpp` 和 `src/game.cpp`
2. 再理解 `map.cpp` 与 `player.cpp`
3. 最后再看搜索部分 `solver.cpp`
4. 每次修改代码都尝试自己调试，先打印变量，不要直接复制答案

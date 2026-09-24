#include <iostream>
#include "game.h"

int main() {
    std::cout << "===============================\n";
    std::cout << "      Sokoban Console Game      \n";
    std::cout << "===============================\n";

    Game game;
    game.run();

    return 0;
}

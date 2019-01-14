#include <iostream>
#include <Game.hpp>
#include "States/InitState.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Game g;
    g.Run();
    return 0;
}
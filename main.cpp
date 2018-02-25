#include "sources/engine.hpp"

int main() {
    std::srand(( unsigned int ) time( nullptr ));

    Engine gameEngine;
    gameEngine.startGame();

    return EXIT_SUCCESS;
}

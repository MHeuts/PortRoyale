//
// Created by Marijn Heuts on 14/12/2018.
//

#include <States/InitState.hpp>
#include "Game.hpp"

Game::Game() {
};

void Game::Run() {
    stateManager.push_state<InitState>(this);
    while(_running){
        String input;

        stateManager.ShowOptions();
        stateManager.HandleInput();
        stateManager.UpdateState();
    }
}

void Game::Quit() {
    _running = false;
}

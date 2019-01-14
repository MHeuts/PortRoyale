//
// Created by Marijn Heuts on 10/01/2019.
//

#include <States/AtSeaState.hpp>
#include "States/InitState.hpp"

void InitState::EnterState() {
    std::cout << "Welcome to Port Royale \n";
}

void InitState::HandleInput() {

    std::cin >> input;
    if(input == "Quit" || input == "quit"){
        _game->Quit();
    } else if (input == "Start"){
        _game->StateHandler().push_state<AtSeaState>(_game, 10);
    } else{
        std::cout << "invalid Input \n";
    }
}

void InitState::ShowOptions() {
    std::cout << "Options: \n Start\n Quit\n";
}

//
// Created by Marijn Heuts on 14/01/2019.
//

#include <States/SetSailState.hpp>

#include "States/SetSailState.hpp"

void SetSailState::ShowOptions() {
    std::cout << "Whare do you want to set Sail For: \nOptions: \n" ;
    for (int i = 0; i < 24; ++i) {
        int distance{_game->GetCurrentHarbour().GetDistance(i)};
        std::cout << i << " : " << distance << "\n";
    }
    std::cout << "Return to Harbour\n";
}

void SetSailState::HandleInput() {

    std::cin >> input;
    if(input == "Return" || input == "Return to Harbour"){
        _game->StateHandler().ReturnToPreviousState();
    } else if (isDestination(input)){
    } else{
        std::cout << "invalid Input \n";
    }
}

bool SetSailState::isDestination(String input) {
    return false;
}


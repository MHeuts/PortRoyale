//
// Created by Marijn Heuts on 14/01/2019.
//

#include <States/SetSailState.hpp>
#include <States/AtSeaState.hpp>

#include "States/SetSailState.hpp"

void SetSailState::ShowOptions() {
    std::cout << "Whare do you want to set Sail For: \nOptions: \n" ;
    for (int i = 0; i < 24; ++i) {
        Distance distance{_game->GetCurrentHarbour().GetDistance(i)};
        std::cout << distance.GetName() << " : " << distance.GetDistance() << "\n";
    }
    std::cout << "Return to Harbour\n";
}

void SetSailState::HandleInput() {

    std::cin >> input;
    if(input == "Return" || input == "Return to Harbour"){
        _game->StateHandler().ReturnToPreviousState();
    } else if (isDestination(input)){
    } else{
        _game->StateHandler().push_state<AtSeaState>(_game, 10);
//        std::cout << "invalid Input \n";
    }
}

bool SetSailState::isDestination(String input) {
//    for (int i = 0; i < 24; ++i) {
//        if(input == _game->GetCurrentHarbour().GetDistance(i).GetName()){
//            _game->StateHandler().push_state<AtSeaState>(_game, _game->GetCurrentHarbour().GetDistance(i).GetDistance());
//            return true;
//        }
//    }
    return false;
}


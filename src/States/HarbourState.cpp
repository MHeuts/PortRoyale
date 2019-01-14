//
// Created by Marijn Heuts on 14/12/2018.
//

#include <States/HarbourState.hpp>

#include "States/HarbourState.hpp"

void HarbourState::EnterState() {
    std::cout << "Welcome to " << _game->GetDestination().GetName() << "\n";
}

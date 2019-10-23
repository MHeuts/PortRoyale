//
// Created by Marijn Heuts on 23/10/2019.
//

#include <States/BuyCannonsState.hpp>

#include "States/BuyShipState.hpp"

void BuyCannonsState::EnterState() {
    std::cout << "Welcome to the Armory\nHere you can buy Cannons\n";
}

void BuyCannonsState::ShowOptions() {
    std::cout << "\nWhich cannontype do you want to buy?"
                 "\n > Small Cannons ) " << _game->GetCurrentHarbour().GetLightCannonsAvailable() << " Available" <<
                 "\n > Medium Cannons ) " << _game->GetCurrentHarbour().GetMediumCannonsAvailable() << " Available" <<
                 "\n > Heavy Cannons ) " << _game->GetCurrentHarbour().GetHeavyCannonsAvailable() << " Available" <<
                 "\n > Return \n";
}

void BuyCannonsState::HandleInput() {
    std::cin >> input;
    if(input == "Return"){
        _game->StateHandler().ReturnToPreviousState();
    }
    else if(input == "Small" || input == "Small Cannons"){

    }
    else if(input == "Medium" || input == "Medium Cannons"){

    }
    else if(input == "Heavy" || input == "Heavy Cannons"){

    }
    else {
        std::cout << input << " is invalid Input\n";
    }
}

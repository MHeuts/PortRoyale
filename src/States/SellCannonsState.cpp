//
// Created by Marijn Heuts on 23/10/2019.
//

#include <States/SellCannonsState.hpp>


void SellCannonsState::EnterState() {
    std::cout << "Welcome to the Armory\nHere you can sell your Cannons\n";
}

void SellCannonsState::ShowOptions() {
    std::cout << "Which cannontype do you want to sell?:"
                 "\n > Small Cannons ) You own " << _game->player().GetShip().GetSmallCannons() <<
              "\n > Medium Cannons ) You own " << _game->player().GetShip().GetMediumCannons() <<
              "\n > Heavy Cannons ) You own " << _game->player().GetShip().GetHeavyCannons() <<
              "\n > Return \n";
}

void SellCannonsState::HandleInput() {
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

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
                 "\n > Small Cannons ) price: 50 Gold Pieces " << _game->GetCurrentHarbour().GetLightCannonsAvailable() << " Available" <<
                 "\n > Medium Cannons ) price: 200 Gold Pieces " << _game->GetCurrentHarbour().GetMediumCannonsAvailable() << " Available" <<
                 "\n > Heavy Cannons ) price: 1000 Gold Pieces " << _game->GetCurrentHarbour().GetHeavyCannonsAvailable() << " Available" <<
                 "\n > Return \n";
}

void BuyCannonsState::HandleInput() {
    input.empty();
    std::cin >> input;

    if(input == "Return"){
        _game->StateHandler().ReturnToPreviousState();
    }
    else if(validInput(input)){
        if(_game->player().GetShip().FreeCannonSpace() == 0){
            std::cout << "You do not have enough space on your ship to install a new cannon!!!\n";
            return;
        }
        buyCannon(input);
    }
    else {
        std::cout << input << " is invalid Input\n";
        return;
    }
}

bool BuyCannonsState::validInput(String input) {
    if(input == "Small" || input == "Medium" || input == "Heavy")
        return true;
    return false;
}

void BuyCannonsState::buyCannon(String input) {
    if(input == "Small" || input == "Small Cannons"){
        price = 50;
        Size = {Light};
    }
    else if(input == "Medium" || input == "Medium Cannons"){
        price = 200;
        Size = {Normal};
    }
    else if(input == "Heavy" || input == "Heavy Cannons"){
        if(_game->player().GetShip().IsSmall()){
            std::cout << "These cannons do no fit on your small ship!";
            return;
        }
        price = 1000;
        Size = {Heavy};
    }
    if(_game->player().GoldAmount() < price){
        std::cout << "You do not have enough gold to buy this cannon!!!\n";
        return;
    }

    if(!_game->GetCurrentHarbour().CheckCannonAvailibility(Size))
        return;

    std::cout << "The " << cannonSize[Size] << " Cannon is installed on your ship";

    _game->player().SpendGold(price);
    _game->player().GetShip().AddCannon(Size);
    _game->GetCurrentHarbour().DecreaseCannonAmount(Size);
}



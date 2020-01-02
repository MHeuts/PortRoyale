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
    input.empty();
    std::cin >> input;
    if(input == "Return"){
        _game->StateHandler().ReturnToPreviousState();
    }
    else if(input == "Small" || input == "Small Cannons"){
        if( _game->player().GetShip().GetSmallCannons() > 0){
            _game->player().GetShip().RemoveCannon(Light);
            _game->player().ReceiveGold(25);

            std::cout << "You sold a small cannon for 25 gold";
        }
        else{
            std::cout << "You do not have small cannons";
        }

    }
    else if(input == "Medium" || input == "Medium Cannons"){

        if( _game->player().GetShip().GetMediumCannons() > 0){
            _game->player().GetShip().RemoveCannon(Normal);
            _game->player().ReceiveGold(100);

            std::cout << "You sold a medium cannon for 100 gold";
        }
        else{
            std::cout << "You do not have medium cannons";
        }
    }
    else if(input == "Heavy" || input == "Heavy Cannons"){
        if( _game->player().GetShip().GetHeavyCannons() > 0){
            _game->player().GetShip().RemoveCannon(Light);
            _game->player().ReceiveGold(500);

            std::cout << "You sold a heavy cannon for 25 gold";
        }
        else{
            std::cout << "You do not have heavy cannon";
        }
    }
    else {
        std::cout << input << " is invalid Input\n";
    }
}

//
// Created by Marijn Heuts on 22/10/2019.
//

#include <string.h>
#include "States/BuyShipState.hpp"

void BuyShipState::EnterState() {
    std::cout << "Welcome to the Shipyard!\n";
    _availibleFunds = _game->player().GoldAmount() + _game->player().GetShip().GetSellPrice();
    std::cout << "You have a total of " << _game->player().GoldAmount() << " Gold Pieces And you get a total of " << _game->player().GetShip().GetSellPrice() << " for your current Ship\n"
                 "Thats a Total of " << _availibleFunds << " Gold Pieces!!!!\n";
}


void BuyShipState::ShowOptions() {
    std::cout << "\nThe Available Ships you can buy are\n";
    for (int i = 0; i < _game->GetCurrentHarbour().GetAvailableShips().Size(); ++i) {
        std::cout <<  _game->GetCurrentHarbour().GetAvailableShips()[i].GetName() << ") for " << _game->GetCurrentHarbour().GetAvailableShips()[i].GetPrice() << " Gold Pices\n";
    }
    std::cout << "Return) to Harbour";
}

void BuyShipState::HandleInput() {
    std::cout << "\nWhich Ship do you want to buy?\n";
    input.empty();
    std::cin >> input;

    if(input == "Return") {
        _game->StateHandler().ReturnToPreviousState();
    }
    else if(isShip(input)){

    }
    else {
        std::cout << input << " is invalid input";
    }
}

bool BuyShipState::isShip(String input) {
    for (int i = 0; i < 5; ++i) {
        if(input == _game->GetCurrentHarbour().GetAvailableShips()[i].GetName()){
            if(_game->GetCurrentHarbour().GetAvailableShips()[i].GetPrice() > _availibleFunds ){
                std::cout << input << " is too expensive\n";
                return true;
            }
            _game->player().SpendGold(_game->GetCurrentHarbour().GetAvailableShips()[i].GetPrice() -
                                      _game->player().GetShip().GetSellPrice());
            _game->player().SetShip(_game->GetCurrentHarbour().GetAvailableShips()[i]);

            std::cout << "you are now the proud owner of a " << _game->player().GetShip().GetName() << "\n";

            _game->StateHandler().ReturnToPreviousState();
            return true;
        }
    }
    return false;
}


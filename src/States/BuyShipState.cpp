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
        std::cout << i+1 << ") " << _game->GetCurrentHarbour().GetAvailableShips()[i].GetName() << " for " << _game->GetCurrentHarbour().GetAvailableShips()[i].GetPrice() << " Gold Pices\n";
    }
    std::cout << "0) Cancel";
}

void BuyShipState::HandleInput() {
    std::cout << "\nWhich Ship do you want to buy?\n";
    String in;
    std::cin >> in;

    char *end;
    int optionNumber = std::strtol(in, &end, 10);
    if(optionNumber == 0) {
        _game->StateHandler().ReturnToPreviousState();
    }
    else if(optionNumber < 1 || optionNumber > 5) {
        std::cout << optionNumber << " is invalid input";
        _game->StateHandler().ReturnToPreviousState();
        return;
    }
    else if(_game->GetCurrentHarbour().GetAvailableShips()[optionNumber-1].GetPrice() > _availibleFunds ){
        std::cout << optionNumber << " is too expensive\n";
        return;
    }
    else {
        _game->player().SpendGold(_game->GetCurrentHarbour().GetAvailableShips()[optionNumber - 1].GetPrice() -
                                  _game->player().GetShip().GetSellPrice());
        _game->player().SetShip(_game->GetCurrentHarbour().GetAvailableShips()[optionNumber - 1]);

        std::cout << "you are now the proud owner of a " << _game->player().GetShip().GetName() << "\n";

        _game->StateHandler().ReturnToPreviousState();
    }
}


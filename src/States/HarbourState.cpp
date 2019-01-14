//
// Created by Marijn Heuts on 14/12/2018.
//

#include <States/HarbourState.hpp>

#include "States/SetSailState.hpp"
#include "States/HarbourState.hpp"

void HarbourState::EnterState() {
    std::cout << "Welcome to " << _game->GetCurrentHarbour().GetName() << "\n";
}

void HarbourState::ShowOptions() {
    std::cout << "What do you want to do:\nOptions:\n"
                 " Buy_Goods\n Sell_Goods\n Buy_Cannons\n Sell_Connons\n Buy_Ship\n Set_Sail\n Quit\n";
}

void HarbourState::HandleInput() {

    std::cin >> input;
    if(input == "Quit" || input == "quit"){
        _game->Quit();
    } else if (input == "Buy_Goods"){
        std::cout << "Market is still closed\n";
    } else if (input == "Sell_Goods"){
        std::cout << "Market is still closed\n";
    } else if (input == "Buy_Cannons"){
        std::cout << "Market is still closed\n";
    } else if (input == "Sell_Cannons"){
        std::cout << "Market is still closed\n";
    } else if (input == "Buy_Ship"){
        std::cout << "Market is still closed\n";
    } else if (input == "Set_Sail"){
        _game->StateHandler().push_state<SetSailState>(_game);
    } else if (input == "Repair"){
        repairShip();
    } else{
        std::cout << "invalid Input \n";
    }
}

void HarbourState::repairShip() {
    int cost = _game->player().GetShip().LostHitpoints();
}

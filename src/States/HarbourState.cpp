//
// Created by Marijn Heuts on 14/12/2018.
//

#include "States/SetSailState.hpp"
#include "States/HarbourState.hpp"
#include "States/BuyShipState.hpp"
#include "States/BuyCannonsState.hpp"
#include <States/SellCannonsState.hpp>

void HarbourState::EnterState() {
    std::cout << "Welcome to " << _game->GetCurrentHarbour().GetName() << "\n";
    generateHarbour();
}

void HarbourState::ShowOptions() {
    std::cout << "\nWhat do you want to do:\nOptions:\n"
                 " > Buy Goods\n"
                 " > Sell Goods\n"
                 " > Buy Cannons\n"
                 " > Sell Connons\n"
                 " > Buy Ship\n"
                 " > Repair Ship\n"
                 " > Set Sail\n"
                 " > Quit\n";
}

void HarbourState::HandleInput() {
    String input;
    std::cin >> input;
    if(input == "Quit" || input == "quit"){
        _game->Quit();
    } else if (input == "Buy Goods") {
        std::cout << "Market is still closed\n";
    } else if (input == "Sell Goods") {
        std::cout << "Market is still closed\n";
    } else if (input == "Buy Cannons") {
        _game->StateHandler().push_state<BuyCannonsState>(_game);
    } else if (input == "Sell Cannons") {
        _game->StateHandler().push_state<SellCannonsState>(_game);
    } else if (input == "Buy Ship") {
        _game->StateHandler().push_state<BuyShipState>(_game);
    } else if (input == "Repair Ship"){
        repairShip();
    } else if (input == "Set Sail") {
        _game->StateHandler().push_state<SetSailState>(_game);
    } else if (input == "repair") {
        repairShip();
    } else{
        std::cout << input << " is not a valid Input \n";
    }
}

void HarbourState::repairShip() {
    std::cout << "You can repair 10 Hit Points per Gold piece\n"
                 "You currnetly own " << _game->player().GoldAmount() << " Gold Pieces\n"
                 "Your ship has lost " << _game->player().GetShip().LostHitpoints() << "Hit Points\n"
                 "How much do you want to pay?\n";


    String in;
    std::cin >> in;

    char *end;
    int payment = std::strtol(in, &end, 10);

    _game->player().GetShip().Repair(payment*10);
    _game->player().SpendGold(payment);
    std::cout << "You repaired your ship for " << payment*10 << " hitpoints\n"
                 "Your Ship is currently at " << _game->player().GetShip().GetCurrentHitPoints() << "!!\n";
}

void HarbourState::generateHarbour() {

    for (int i = 0; i < 5; ++i) {
        _game->GetCurrentHarbour().AddToShips(i, _game->getShip(Random::GetInstance().GetRandom(13)));
    }

    setCannonStock();

    _game->GetCurrentHarbour().GeneratePrices();
}

void HarbourState::setCannonStock() {
    int light = Random::GetInstance().GetRandom(5);
    int medium = Random::GetInstance().GetRandom(3);
    int heavy = Random::GetInstance().GetRandom(2);

    _game->GetCurrentHarbour().SetCannonStock(light, medium, heavy);
}


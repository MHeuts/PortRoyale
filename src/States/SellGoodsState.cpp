//
// Created by Marijn Heuts on 23/10/2019.
//

#include <States/SellGoodsState.hpp>

void SellGoodsState::EnterState() {
    std::cout << "Welcome to the Market\nHere you can sell your Goods\n";
}

void SellGoodsState::ShowOptions() {
    std::cout << "\nWhich goods do you want to Sell?\n";

    for (int i = 0; i < 15; ++i) {
        std::cout << " > " << _game->player().getGood(i).GetName() << " ) for " <<  _game->GetCurrentHarbour().getGood(i).GetPrice() << " Gold Pieces; "
                  << _game->player().getGood(i).GetAmmount() << " in Cargo\n";
    }

    std::cout << " > Return\n";
}

void SellGoodsState::HandleInput() {
    std::cin >> input;
    if(input == "Return"){
        _game->StateHandler().ReturnToPreviousState();
    }
}


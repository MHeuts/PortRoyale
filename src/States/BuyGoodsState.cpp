//
// Created by Marijn Heuts on 23/10/2019.
//

#include <States/BuyGoodsState.hpp>

#include "States/BuyGoodsState.hpp"

void BuyGoodsState::EnterState() {
    std::cout << "Welcome to the Market\nHere you can buy Goods\n";
}

void BuyGoodsState::ShowOptions() {
    std::cout << "\nWhich goods do you want to buy?\n";

    for (int i = 0; i < 15; ++i) {
        std::cout << " > " << _game->GetCurrentHarbour().getGood(i).GetName() << " ) for " <<  _game->GetCurrentHarbour().getGood(i).GetPrice() << " Gold Pieces; "
        << _game->GetCurrentHarbour().getGood(i).GetAmmount() << " in Stock\n";
    }

    std::cout << " > Return\n";
}



void BuyGoodsState::HandleInput() {
    input.empty();
    if(_game->player().AvailableSpace() == 0){
        std::cout << "You do not have enough space on your ships Cargo Hold!!!\n";
        return;
    }
    std::cin >> input;
    if (input == "Return")
        _game->StateHandler().ReturnToPreviousState();
    else if(isGoods(input)){
        std::cout << "You succesfully bought " << input << "\n";
    }
    else{
        std::cout << input << " is invalid input\n";
    }
}

bool BuyGoodsState::isGoods(String input) {
    for (int i = 0; i < 15; ++i) {

        if(input == _game->GetCurrentHarbour().getGood(i).GetName()){
            int amount = askQuantity();
            if(amount < 0)
                return false;
            if(_game->player().AvailableSpace() < amount){
                std::cout << "you do not have enough Cargo Space!\n";
            }
            else if(_game->GetCurrentHarbour().getGood(i).GetPrice()*amount > _game->player().GoldAmount()){
                std::cout << "you do not have enough Gold for this!\n";
            }
            else if(_game->GetCurrentHarbour().getGood(i).GetAmmount() < amount){
                std::cout << "Not enough goods available!\n";
            }
            else {
                _game->player().AddCargo(input, amount);
                _game->GetCurrentHarbour().RemoveGoods(input, amount);
                _game->player().SpendGold(_game->GetCurrentHarbour().getGood(i).GetPrice()*amount);
                return true;
            }
        }
    }
    return false;
}

int BuyGoodsState::askQuantity() {
    std::cout << "In what quantitiy do you want to buy?\n";
    String in;
    std::cin >> in;

    char *end;
    return std::strtol(in, &end, 10);
}


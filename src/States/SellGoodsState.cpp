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
    input.empty();
    std::cin >> input;
    if(input == "Return"){
        _game->StateHandler().ReturnToPreviousState();
    }
    else if(isGoods(input)){
        std::cout << "You succesfully sold " << input << "\n";
    }
    else {
        std::cout << input << " is invalid input\n";
    }
}

bool SellGoodsState::isGoods(String input) {
    for (int i = 0; i < 15; ++i) {

        if(input == _game->player().getGood(i).GetName()){
            int amount = askQuantity();
            if(amount < 0)
                return false;
            if(_game->player().getGood(i).GetAmmount() < amount){
                std::cout << "you do not have enough "<< input <<" in your Cargo!\n";
            }
            else {
                _game->player().RemoveCargo(input, amount);
                _game->player().ReceiveGold(_game->GetCurrentHarbour().getGood(i).GetPrice()*amount);
                return true;
            }
        }
    }
    return false;
}

int SellGoodsState::askQuantity() {
    std::cout << "In what quantitiy do you want to sell?\n";
    String in;
    std::cin >> in;

    char *end;
    return std::strtol(in, &end, 10);
}


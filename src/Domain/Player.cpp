//
// Created by Marijn Heuts on 14/12/2018.
//

#include <Domain/Player.hpp>

#include "Domain/Player.hpp"


int Player::AvailableSpace() {
    return _ship.GetCargoSpace() - totalCargo;
}

void Player::AddCargo(String name, int amount) {

    if(AvailableSpace() < amount){
        return;
    }

    for (auto &i : Cargo) {
        if(i.GetName() == name){
            i.IncreaseAmount(amount);
            totalCargo+= amount;
            return;
        }
    }
}

void Player::RemoveCargo(String name, int amount) {

    for (auto &i : Cargo) {
        if(i.GetName() == name){
            if(i.GetAmmount() < amount)
                return;

            i.DecreaseAmount(amount);
            totalCargo -= amount;
            return;
        }
    }
}

void Player::SetGoodsName(int i, String name) {
    Cargo[i].setName(name);
}

void Player::updateGoodsAmount(int i, int ammount) {
    Cargo[i].setAmmount(ammount);
}


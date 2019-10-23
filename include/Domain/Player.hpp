//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_PLAYER_HPP
#define PORTROYALE_PLAYER_HPP

#include "Domain/Ship.hpp"
#include "Domain/Goods.hpp"

class Player {

public:
    Player() = default;
    ~Player() = default;

    Ship &GetShip() { return _ship; }

private:
    Ship _ship;
    int _gold {0};

    Vector<Goods> Cargo;

public:

    int GoldAmount() const  { return _gold; };
    int AvailableSpace();

    void SetShip(Ship ship) { _ship = ship; };
    void ReceiveGold(int gold) { _gold += gold; };
    void SpendGold(int gold) { _gold -= gold; };
    void LooseAllCargo() {};



};

#endif //PORTROYALE_PLAYER_HPP

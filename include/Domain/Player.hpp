//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_PLAYER_HPP
#define PORTROYALE_PLAYER_HPP

#include "Domain/Ship.hpp"
class Player {

public:
    Player() = default;
    ~Player() = default;

    Ship &GetShip() { return _ship; }

private:
    Ship _ship;
    int _gold {0};

public:

    int GoldAmount() const  { return _gold; };

    void SetShip(Ship ship) { _ship = ship; };
    void ReceiveGold(int gold) { _gold += gold; };
    void SpendGold(int gold) { _gold -= gold; };
    void LooseAllCargo() {};

};

#endif //PORTROYALE_PLAYER_HPP

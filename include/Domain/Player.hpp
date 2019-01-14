//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_PLAYER_HPP
#define PORTROYALE_PLAYER_HPP

#include "Domain/Ship.hpp"
class Player {
public:
    Ship &GetShip() { return _ship; }
    void SetShip(Ship ship) { _ship = ship; }
    void ReceiveGold(int gold) { _gold += gold; }
    void SpendGold(int gold) { _gold -= gold; }
    int GoldAmount() { return _gold; }
    void LooseAllCargo();
private:
    Ship _ship;
    int _gold {0};
};


#endif //PORTROYALE_PLAYER_HPP

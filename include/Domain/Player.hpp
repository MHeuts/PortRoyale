//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_PLAYER_HPP
#define PORTROYALE_PLAYER_HPP

#include "Domain/Ship.hpp"
class Player {
public:
    Ship &GetShip() { return _ship; }
    void LooseAllCargo();
private:
    Ship _ship;
    int _gold;
};


#endif //PORTROYALE_PLAYER_HPP

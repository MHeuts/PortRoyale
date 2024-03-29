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

    Goods Cargo[15];
    int totalCargo = 0;

public:

    int GoldAmount() const  { return _gold; };
    int AvailableSpace();

    Goods getGood(int i) { return Cargo[i]; }

    void SetShip(Ship ship) { _ship = ship; };
    void SetGoodsName(int i, String name);
    void ReceiveGold(int gold) { _gold += gold; };
    void SpendGold(int gold) { _gold -= gold; };
    void LooseAllCargo();

    void AddCargo(String name, int Amount);
    void RemoveCargo(String name, int amount);

private:
    void updateGoodsAmount(int i, int ammount);

};

#endif //PORTROYALE_PLAYER_HPP

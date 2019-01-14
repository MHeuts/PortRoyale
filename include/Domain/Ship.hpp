//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_SHIP_HPP
#define PORTROYALE_SHIP_HPP


#include <Helpers/String.hpp>
#include "WeightEnum.hpp"

struct Cannon{
    WeightEnum weight;
};

class Ship {
private:
    String _type;
    int _price;
    int _maxHitPoints;
    int _currentHitPoints {0};
    int _cargoSpace;
    int _cannonSpace;
    bool _isSmall;
    WeightEnum _weight;
    Cannon _cannons[50];

public:
    void GenerateValues(String type);
    int GetCurrentHitPoints() { return _currentHitPoints; }
    bool IsDestroyed() { return _currentHitPoints <= 0; }
    bool IsLog();
    bool IsLight();

    void ReceiveDamage(int Damage);
    int GetDamageOutput();

};


#endif //PORTROYALE_SHIP_HPP

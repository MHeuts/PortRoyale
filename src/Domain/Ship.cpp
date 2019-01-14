//
// Created by Marijn Heuts on 14/12/2018.
//

#include "Helpers/Random.hpp"
#include "Domain/Ship.hpp"

void Ship::ReceiveDamage(int damage) {
    _currentHitPoints -= damage;
}

int Ship::GetDamageOutput(){
    int totalDamage{0};
    for(int i=0;i<_smallCannonAmount;i++){
        totalDamage+=Random::GetInstance().GetRandom(2);
    }
    for(int i=0;i<_mediumCannonAmount;i++){
        totalDamage+=Random::GetInstance().GetRandom(4);
    }
    for(int i=0;i<_heavyCannonAmount;i++){
        totalDamage+=Random::GetInstance().GetRandom(4);
    }
    return totalDamage;
}

void Ship::AddCannon(WeightEnum weight) {
    if(TotalCannonAmount() >= _cannonSpace)
        return;

    if(weight == Light)
        ++_smallCannonAmount;
    else if (weight == Normal)
        ++_mediumCannonAmount;
    else if (weight == Heavy)
        ++_heavyCannonAmount;
}

void Ship::RemoveCannon(WeightEnum weight) {
    if(weight == Light && _smallCannonAmount > 0)
        --_smallCannonAmount;
    else if (weight == Normal && _mediumCannonAmount > 0)
        --_mediumCannonAmount;
    else if (weight == Heavy && _heavyCannonAmount > 0)
        --_heavyCannonAmount;
}

void Ship::Repair() {
    _currentHitPoints = _maxHitPoints;
}

Ship &Ship::operator=(const Ship &other) {
    if(this == &other) return *this;
    _name = other._name;
    _price = other._price;
    _cargoSpace = other._cargoSpace;
    _maxHitPoints = other._maxHitPoints;
    _currentHitPoints = other._currentHitPoints;
    _cannonSpace = other._cannonSpace;
    _isSmall = other._isSmall;
    _weight = other._weight;
    return *this;
}

Ship &Ship::operator=(Ship &&other) noexcept{
    if(this == &other) return *this;
    _name = other._name;
    _price = other._price;
    _cargoSpace = other._cargoSpace;
    _maxHitPoints = other._maxHitPoints;
    _currentHitPoints = other._currentHitPoints;
    _cannonSpace = other._cannonSpace;
    _isSmall = other._isSmall;
    _weight = other._weight;
    return *this;
}

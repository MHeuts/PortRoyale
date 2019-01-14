//
// Created by Marijn Heuts on 14/12/2018.
//

#include <Domain/Ship.hpp>
#include "Helpers/Random.hpp"
#include "Domain/Ship.hpp"

void Ship::GenerateValues(String shipType) {
    _maxHitPoints = 100;
    _currentHitPoints = _maxHitPoints;
    _cargoSpace = 200;
    _cannonSpace = 8;
    _weight = WeightEnum(Light);
    _isSmall = true;
    _name = shipType;
}

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

bool Ship::IsLog() {
    return _weight == Heavy;
}

bool Ship::IsLight() {
    return _weight == Light;
}

bool Ship::IsSmall() {
    return _isSmall;
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

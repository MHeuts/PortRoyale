//
// Created by Marijn Heuts on 14/12/2018.
//

#include <Domain/Ship.hpp>
#include <fstream>

#include "Domain/Ship.hpp"

void Ship::GenerateValues(String shipType) {

    std::ifstream stream;
    stream.open("Assets/schepen.csv");
    char line[500];
    while(stream.getline(line, 500, '\n')){
        std::cout << line << "\n";
    }

    _maxHitPoints = 100;
    _currentHitPoints = _maxHitPoints;
    _cargoSpace = 200;
    _cannonSpace = 8;
    _weight = WeightEnum(Light);
    _isSmall = true;
    _type = shipType;
}

void Ship::ReceiveDamage(int damage) {
    //_currentHitPoints -= Damage;
}

int Ship::GetDamageOutput(){
    int totalDamage{0};
    for(int i = 0; i < _cannonSpace; ++i){
        ++totalDamage;
    }
    return totalDamage;
}

bool Ship::IsLog() {
    return _weight == Heavy;
}

bool Ship::IsLight() {
    return _weight == Light;
}

//
// Created by Marijn Heuts on 14/01/2019.
//

#ifndef PORTROYALE_CANNON_HPP
#define PORTROYALE_CANNON_HPP

#include "WeightEnum.hpp"

class Cannon{
public:
    const WeightEnum GetWeight() { return weight; }

private:
    WeightEnum weight;
    int price;
    int minAmount;
    int maxAmount;
};

#endif //PORTROYALE_CANNON_HPP

//
// Created by Marijn Heuts on 23/10/2019.
//

#include "Domain/Goods.hpp"
#include "Helpers/Random.hpp"

void Goods::randomizePrice() {
    price = Random::GetInstance().GetRandom(minPrice, maxPrice);
}

void Goods::randomizeAmmount() {
    ammount = Random::GetInstance().GetRandom(minAmount, maxAmount);
}
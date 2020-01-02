//
// Created by Marijn Heuts on 14/12/2018.
//

#include <Domain/Harbour.hpp>

#include "Domain/Harbour.hpp"

void Harbour::SetDistance(int i, int distance, String name) {
    _distances[i].SetDistance(distance);
    _distances[i].SetName(name);
}

Harbour &Harbour::operator=(const Harbour &other) {
    if(this == &other) return *this;
    _name = other._name;
    for (int i = 0; i < 15; ++i) _goods[i] = other._goods[i];
    for (int j = 0; j < 24; ++j) _distances[j] = other._distances[j];
    return *this;
}

Harbour &Harbour::operator=(Harbour &&other) noexcept {
    if(this == &other) return *this;
    _name = other._name;
    for (int i = 0; i < 15; ++i) _goods[i] = other._goods[i];
    for (int j = 0; j < 24; ++j) _distances[j] = other._distances[j];
    return *this;
}

void Harbour::RandomizeGoods() {
    for (int i = 0; i < 15; ++i) {
        _goods[i].randomizeAmmount();
        _goods[i].randomizePrice();
    }
}

void Harbour::AddToShips(int i, Ship ship) {
    _availableShips.push_back(ship);
}

void Harbour::DecreaseCannonAmount(WeightEnum size) {
    switch(size) {
        case Light:
            --_availibleLightCannons;
            break;
        case Normal:
            --_availableMediumCannons;
            break;
        case Heavy:
            --_availableHeavyCannons;
            break;
        default:
            return;
    }
}

bool Harbour::CheckCannonAvailibility(WeightEnum size) {
    switch(size){
        case Light:
            if(_availibleLightCannons > 0)
                return true;
            break;
        case Normal:
            if(_availableMediumCannons > 0)
                return true;
            break;
        case Heavy:
            if(_availableMediumCannons > 0)
                return false;
            break;
        default:
            return false;
    }
    return false;
}

void Harbour::SetGoodName(int i, String name) {
    _goods[i].setName(name);
}

void Harbour::SetGoodAvailability(int i, int minAvailablity, int maxAvailability) {
    _goods[i].setAmountMinMax(minAvailablity, maxAvailability);
}

void Harbour::SetGoodPrices(int i, int minPrice, int maxPrice) {
    _goods[i].setPriceMinMax(minPrice, maxPrice);
}

void Harbour::RemoveGoods(String name, int amount) {
    for (auto &i : _goods) {
        if(i.GetName() == name){
            if(i.GetAmmount() < amount)
                return;

            i.DecreaseAmount(amount);
            return;
        }
    }
}


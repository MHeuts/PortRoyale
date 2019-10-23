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
//    for (int i = 0; i < 15; ++i) _goods[i] = other._goods[i];
    for (int j = 0; j < 24; ++j) _distances[j] = other._distances[j];
    return *this;
}

Harbour &Harbour::operator=(Harbour &&other) noexcept {
    if(this == &other) return *this;
    _name = other._name;
//    for (int i = 0; i < 15; ++i) _goods[i] = other._goods[i];
    for (int j = 0; j < 24; ++j) _distances[j] = other._distances[j];
    return *this;
}

void Harbour::GeneratePrices() {

}

void Harbour::AddToShips(int i, Ship ship) {
    _availableShips.push_back(ship);
}


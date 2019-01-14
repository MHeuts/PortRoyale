//
// Created by Marijn Heuts on 14/12/2018.
//

#include <Domain/Harbour.hpp>

#include "Domain/Harbour.hpp"

void Harbour::SetDistance(int i, int distance) {
    _distances[i] = distance;
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

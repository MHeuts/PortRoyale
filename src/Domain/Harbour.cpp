//
// Created by Marijn Heuts on 14/12/2018.
//

#include <Domain/Harbour.hpp>

#include "Domain/Harbour.hpp"

void Harbour::SetDistance(int i, int distance) {
    _distances[i] = distance;
}

Harbour::Harbour(const Harbour &other) {

}

Harbour::Harbour(Harbour &&) {

}

Harbour &Harbour::operator=(const Harbour &other) {
    return *this;
}

Harbour &Harbour::operator=(Harbour &&other) {
    return *this;
}

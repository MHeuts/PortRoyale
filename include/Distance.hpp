//
// Created by Marijn Heuts on 14/01/2019.
//

#ifndef PORTROYALE_DISTANCE_HPP
#define PORTROYALE_DISTANCE_HPP

#include "Helpers/String.hpp"

class Distance{
private:
    String _harbourName;
    int _distance;
public:
    Distance() = default;
    Distance(String name, int distance): _distance{distance}, _harbourName{name} { }
    String GetName() { return _harbourName; }
    int GetDistance() { return _distance; }
};
#endif //PORTROYALE_DISTANCE_HPP

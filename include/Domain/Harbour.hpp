//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_HARBOUR_HPP
#define PORTROYALE_HARBOUR_HPP

#include "Helpers/String.hpp"
#include "Domain/Goods.hpp"
#include "Distance.hpp"

class Harbour {
public:
    Harbour() = default;
    Harbour(const Harbour& other);
    Harbour(Harbour&&);
    Harbour&operator=(const Harbour& other);
    Harbour&operator=(Harbour&& other);
    ~Harbour() = default;
private:
    String _name;
    Goods _goods[15];
    int _distances[24];
public:
    void SetName(String name) { _name = name; }
    void SetDistance(int i, int distance);
    String GetName() { return _name; }
    int GetDistance(int i) { return _distances[i]; }
};


#endif //PORTROYALE_HARBOUR_HPP

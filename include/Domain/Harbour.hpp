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
    Harbour(const Harbour& other) : _name{other._name} {
//        for (int i = 0; i < 15; ++i) {
//            _goods[i] = other._goods[i];
//        }
        for (int j = 0; j < 24; ++j) {
            _distances[j] = other._distances[j];
        }
    }
    Harbour(Harbour&& other) noexcept : _name{other._name} {
//        for (int i = 0; i < 15; ++i) {
//            _goods[i] = std::move(other._goods[i]);
//        }
        for (int j = 0; j < 24; ++j) {
            _distances[j] = std::move(other._distances[j]);
        }
    }
    Harbour&operator=(const Harbour& other);
    Harbour&operator=(Harbour&& other) noexcept;
    ~Harbour() = default;
private:
    String _name;
    Goods _goods[15];
    Distance _distances[24];
public:
    void SetName(String name) { _name = name; }
    void SetDistance(int i, int distance, String name);
    String GetName() { return _name; }
    Distance GetDistance(int i) { return _distances[i]; }
};


#endif //PORTROYALE_HARBOUR_HPP

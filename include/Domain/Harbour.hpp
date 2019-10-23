//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_HARBOUR_HPP
#define PORTROYALE_HARBOUR_HPP

#include "Helpers/String.hpp"
#include "Helpers/Stack.hpp"
#include "Domain/Goods.hpp"
#include "Distance.hpp"
#include "Ship.hpp"

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
    Vector<Ship> _availableShips;
    int _availibleLightCannons;
    int _availableMediumCannons;
    int _availableHeavyCannons;

public:
    String GetName() const { return _name; }
    Distance GetDistance(int i) const { return _distances[i]; }

    Vector<Ship> GetAvailableShips() { return _availableShips; }

    void SetCannonStock(int light, int medium, int heavy){
        _availibleLightCannons = light;
        _availableMediumCannons = medium;
        _availableHeavyCannons = heavy;
    }

    int GetLightCannonsAvailable(){ return _availibleLightCannons; }
    int GetMediumCannonsAvailable(){ return _availableMediumCannons; }
    int GetHeavyCannonsAvailable(){ return _availableHeavyCannons; }


    void AddToShips(int i, Ship ship);
    void GeneratePrices();

    void SetName(String name) { _name = name; }
    void SetDistance(int i, int distance, String name);
};


#endif //PORTROYALE_HARBOUR_HPP

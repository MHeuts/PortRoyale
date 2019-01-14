//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_SHIP_HPP
#define PORTROYALE_SHIP_HPP


#include <Helpers/String.hpp>
#include "WeightEnum.hpp"
#include "Cannon.hpp"

class Ship {
public:
    Ship() = default;
    Ship(const Ship& other) {
        if(this != &other){
            _name = other._name;
            _price = other._price;
            _cargoSpace = other._cargoSpace;
            _maxHitPoints = other._maxHitPoints;
            _currentHitPoints = other._currentHitPoints;
            _cannonSpace = other._cannonSpace;
            _isSmall = other._isSmall;
            _weight = other._weight;
        }
    }

    Ship(Ship&&) = delete;
    Ship& operator = (const Ship& other) {
        if(this != &other){
            _name = other._name;
            _price = other._price;
            _cargoSpace = other._cargoSpace;
            _maxHitPoints = other._maxHitPoints;
            _currentHitPoints = other._currentHitPoints;
            _cannonSpace = other._cannonSpace;
            _isSmall = other._isSmall;
            _weight = other._weight;
        }

        return *this;
    }
    Ship& operator = (Ship&& other){
        if(this != &other){
            _name = other._name;
            _price = other._price;
            _cargoSpace = other._cargoSpace;
            _maxHitPoints = other._maxHitPoints;
            _currentHitPoints = other._currentHitPoints;
            _cannonSpace = other._cannonSpace;
            _isSmall = other._isSmall;
            _weight = other._weight;
        }

        return *this;
    }

private:
    String _name;
    int _price;
    int _maxHitPoints;
    int _cargoSpace;
    int _cannonSpace;
    bool _isSmall {false};
    WeightEnum _weight {Normal};

public:
    void SetName(String name) { _name = name; }
    void SetPrice(int price) { _price = price; }
    void SetHitPoints(int hitpoints) { _maxHitPoints = hitpoints;
                                        _currentHitPoints = _maxHitPoints; }
    void SetcargoSpace(int cargoSpace) { _cargoSpace = cargoSpace; }
    void SetCannonSpace(int cannonSpace) { _cannonSpace = cannonSpace; }
    void SetSmall(bool isSmall) { _isSmall = isSmall; }
    void SetWeight(WeightEnum weight) { _weight = weight; }

    const String GetName() { return _name; }

private:
    int _smallCannonAmount {0};
    int _mediumCannonAmount {0};
    int _heavyCannonAmount {0};
    int _currentHitPoints {0};

public:
    void GenerateValues(String type);
    int GetCurrentHitPoints() { return _currentHitPoints; }
    bool IsDestroyed() { return _currentHitPoints <= 0; }
    void Repair();
    int TotalCannonAmount() { return _smallCannonAmount+_mediumCannonAmount+_heavyCannonAmount; }
    int FreeCannonSpace() { return _cannonSpace - TotalCannonAmount(); }
    bool IsLog();
    bool IsLight();
    bool IsSmall();

    void AddCannon(WeightEnum weight);
    void RemoveCannon(WeightEnum weight);

    void ReceiveDamage(int Damage);
    int GetDamageOutput();

};


#endif //PORTROYALE_SHIP_HPP

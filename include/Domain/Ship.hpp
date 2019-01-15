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
    Ship(const Ship& other) :   _name{other._name},
                                _price{other._price},
                                _cargoSpace{other._cargoSpace},
                                _cannonSpace{other._cannonSpace},
                                _maxHitPoints{other._maxHitPoints},
                                _currentHitPoints{other._currentHitPoints},
                                _isSmall{other._isSmall},
                                _weight{other._weight} { }
    Ship(Ship&&) = delete;
    Ship& operator = (const Ship& other);
    Ship& operator = (Ship&& other) noexcept;
    ~Ship() = default;

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

    String GetName() const { return _name; }

private:
    int _smallCannonAmount {0};
    int _mediumCannonAmount {0};
    int _heavyCannonAmount {0};
    int _currentHitPoints {0};

public:
    int GetCurrentHitPoints() const { return _currentHitPoints; }
    int TotalCannonAmount() const { return _smallCannonAmount+_mediumCannonAmount+_heavyCannonAmount; }
    int FreeCannonSpace() const { return _cannonSpace - TotalCannonAmount(); }
    int LostHitpoints() const { return _maxHitPoints - _currentHitPoints; }

    bool IsDestroyed() const { return _currentHitPoints <= 0; }
    bool IsLog() const { return _weight == Heavy; }
    bool IsLight() const { return _weight == Light; }
    bool IsSmall() const { return _isSmall; }

    void AddCannon(WeightEnum weight);
    void RemoveCannon(WeightEnum weight);

    void Repair();

    void ReceiveDamage(int Damage);
    int GetDamageOutput();

};


#endif //PORTROYALE_SHIP_HPP

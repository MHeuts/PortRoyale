//
// Created by Marijn Heuts on 14/12/2018.
//

#include "Domain/Player.hpp"


int Player::AvailableSpace() {
    return _ship.GetCargoSpace() - Cargo.Size();
}

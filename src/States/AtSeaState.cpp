//
// Created by Marijn Heuts on 14/12/2018.
//

#include <iostream>
#include <States/AtSeaState.hpp>
#include <States/HarbourState.hpp>
#include <States/CombatState.hpp>
#include <States/InitState.hpp>


void AtSeaState::EnterState() {
    std::cout << "Welcome At Sea \n";

}

void AtSeaState::LeaveState() {

}

void AtSeaState::Update() {

    _weatherEffect(Random::GetInstance().GetRandom(20));
    if(_turnsLeft <= 0){
        std::cout << "Arrived at port\n";
        _game->StateHandler().push_state<InitState>(_game);
    }
    else {
        std::cout << "turns until in port: " << _turnsLeft <<"\n";
        _randomEncounter(Random::GetInstance().GetRandom(100));
    }
}

void AtSeaState::_randomEncounter(int encounterRate) {
    if(encounterRate <= 20){
        _game->StateHandler().push_state<CombatState>(_game);
    }
    else{
        std::cout << "No pirates in sight\n";
    }
}


void AtSeaState::_weatherEffect(int weatherStrength) {
    if(weatherStrength >= 1 && weatherStrength<= 2){
        std::cout << "No Wind\n";

    } else if ( weatherStrength >= 3 && weatherStrength <= 4 ) {
        std::cout << "Light Breeze\n";
        if(_game->player().GetShip().IsLight())
            -- _turnsLeft;

    } else if ( weatherStrength >= 5 && weatherStrength <= 7) {
        std::cout << "Week Wind\n";
        if(!_game->player().GetShip().IsLog())
            -- _turnsLeft;

    } else if ( weatherStrength >= 8 && weatherStrength <= 17 ) {
        std::cout << "Normal Wind\n";
        -- _turnsLeft;

    } else if ( weatherStrength >= 18 && weatherStrength <= 19 ) {
        std::cout << "Strong Wind\n";
        _turnsLeft -= 2;

    } else if ( weatherStrength == 20){
        std::cout << "Storm\n";
        _stormEffect(Random::GetInstance().GetRandom(100));
    }
}

void AtSeaState::_stormEffect(int stormEffect){
    if(stormEffect <= 40) {
        std::cout << "Blown off course!\n";
        ++ _turnsLeft;
    } else if (stormEffect >= 41 && stormEffect <= 80){
        std::cout << "The ship did not move!\n";
    } else{
        std::cout << "Blown towards the harbour\n";
        -- _turnsLeft;
    }
    double Damage = Random::GetInstance().GetRandom(100);
    int damage = (int)std::round(34*(Damage)/100);
    _game->player().GetShip().ReceiveDamage(damage);
}


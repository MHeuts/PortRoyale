//
// Created by Marijn Heuts on 14/12/2018.
//

#include <States/CombatState.hpp>
#include <States/AtSeaState.hpp>

void CombatState::EnterState() {
    enemyShip = _game->getShip(Random::GetInstance().GetRandom(12));
    int cannonamount = Random::GetInstance().GetRandom(enemyShip.FreeCannonSpace());
    for(int i = 0; i<cannonamount; ++i){
        int cannontype = Random::GetInstance().GetRandom(3);
        if(cannontype == 1)
            enemyShip.AddCannon(Light);
        else if(cannontype == 2)
            enemyShip.AddCannon(Normal);
        else if(cannontype == 3)
            enemyShip.AddCannon(Heavy);
    }

    std::cout << "Enemy "<< enemyShip.GetName() <<" Ahead!\n";
}

void CombatState::ShowOptions() {
    std::cout << "You have " << _game->player().GetShip().GetCurrentHitPoints() << " Hitpoints left\n";
    std::cout << "options: \n Shoot \n Flee \n Surrender \n";
}

void CombatState::HandleInput() {
    std::cin >> input;

    if(input == "Flee"){
        _flee();
    } else if (input == "Shoot"){
        _shoot();
    } else if(input == "Surrender") {
        _surrender();
    } else {
        std::cout << "Your crew did not understand what you said! \n";
    }
}

void CombatState::Update() {
    if(_combatOver){
        _game->StateHandler().ReturnToPreviousState();
    } else{
        _enemyShipTurn();
    }
}

void CombatState::_flee(){
    int fleeChanse{0};

    std::cout << "Attempting to flee.\n";
    if(_game->player().GetShip().IsLight()) {
        fleeChanse = 50;
    } else if(_game->player().GetShip().IsLog()) {
        fleeChanse = 5;
    } else {
        fleeChanse = 30;
    }


    if(enemyShip.IsLight()) {
        fleeChanse += 0;
    } else if(enemyShip.IsLog()) {
        fleeChanse += 15;
    } else {
        fleeChanse += 10;
    }
    if(Random::GetInstance().GetRandom(100) <= fleeChanse){
        std::cout << "Successfully escaped the Pirates\n";
        _game->StateHandler().ReturnToPreviousState();
    } else{
        std::cout << "Flee unsuccessful\n";
    }
}

void CombatState::_shoot(){
    std::cout << "Firing All Cannons!\n";
    int damage = _game->player().GetShip().GetDamageOutput();
    std::cout << "Doing " << damage << " points of Damage!!!\n";
    enemyShip.ReceiveDamage(damage);
}

void CombatState::_surrender(){
    std::cout << "You surrender yourself and all your goods to the pirates\n";
    _game->player().LooseAllCargo();
    _combatOver = true;
}

void CombatState::_enemyShipTurn() {
    std::cout << "Enemy Ship is firing!\n";
    int damage = enemyShip.GetDamageOutput();
    std::cout<< damage << " Points of damage!!!\n";
    _game->player().GetShip().ReceiveDamage(damage);
}
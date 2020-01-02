//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_COMBATSTATE_HPP
#define PORTROYALE_COMBATSTATE_HPP

#include <Game.hpp>
#include "Domain/Ship.hpp"
#include "BaseState.hpp"

class CombatState :public BaseState{
public:
    explicit CombatState(Game* game): _game{game}{ }

    ~CombatState() override { }
    void EnterState() override;
    void LeaveState() override {};

    void ShowOptions() override;
    void HandleInput() override;
    void Update() override;
private:
    Ship enemyShip;
    Game* _game;
    String input;
    bool _combatOver = false;

    void _enemyShipTurn();
    void _shoot();
    void _flee();
    void _surrender();

};


#endif //PORTROYALE_COMBATSTATE_HPP

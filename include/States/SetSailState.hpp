//
// Created by Marijn Heuts on 14/01/2019.
//

#ifndef PORTROYALE_SETSAILSTATE_HPP
#define PORTROYALE_SETSAILSTATE_HPP

#include "Game.hpp"
#include "BaseState.hpp"

class SetSailState: public BaseState{
public:
    explicit SetSailState(Game* game): _game{game}{ }

    ~SetSailState() override = default;
    void EnterState() override {};
    void LeaveState() override {};

    void ShowOptions() override;
    void HandleInput() override;
    void Update() override {};
private:
    Game* _game;
    bool isDestination(String input);
};
#endif //PORTROYALE_SETSAILSTATE_HPP

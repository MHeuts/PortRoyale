//
// Created by Marijn Heuts on 23/10/2019.
//

#ifndef PORTROYALE_SELLCANNONSSTATE_HPP
#define PORTROYALE_SELLCANNONSSTATE_HPP

#include "BaseState.hpp"
#include "Game.hpp"

class SellCannonsState: public BaseState{
public:
    SellCannonsState(Game* game): _game{game} { }
    ~SellCannonsState() override = default;

    void EnterState() override;
    void LeaveState() override { };

    void ShowOptions() override;
    void HandleInput() override;
    void Update() override { };


private:
    Game* _game;
};
#endif //PORTROYALE_SELLCANNONSSTATE_HPP

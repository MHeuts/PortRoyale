//
// Created by Marijn Heuts on 23/10/2019.
//

#ifndef PORTROYALE_SELLGOODSSTATE_HPP
#define PORTROYALE_SELLGOODSSTATE_HPP

#include "BaseState.hpp"
#include "Game.hpp"

class SellGoodsState: public BaseState{
public:
    SellGoodsState(Game* game): _game{game} { }
    ~SellGoodsState() override = default;

    void EnterState() override;
    void LeaveState() override { };

    void ShowOptions() override;
    void HandleInput() override;
    void Update() override { };


private:
    Game* _game;
};
#endif //PORTROYALE_SELLGOODSSTATE_HPP

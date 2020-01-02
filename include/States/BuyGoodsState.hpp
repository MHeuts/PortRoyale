//
// Created by Marijn Heuts on 23/10/2019.
//

#ifndef PORTROYALE_BUYGOODSSTATE_HPP
#define PORTROYALE_BUYGOODSSTATE_HPP

#include "BaseState.hpp"
#include "Game.hpp"

class BuyGoodsState: public BaseState{
public:
    BuyGoodsState(Game* game): _game{game} { }
    ~BuyGoodsState() override = default;

    void EnterState() override;
    void LeaveState() override { };

    void ShowOptions() override;
    void HandleInput() override;
    void Update() override { };


private:
    Game* _game;

    bool isGoods(String input);
    static int askQuantity();
};
#endif //PORTROYALE_BUYGOODSSTATE_HPP

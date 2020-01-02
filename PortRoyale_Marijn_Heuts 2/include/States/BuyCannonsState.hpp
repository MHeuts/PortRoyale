//
// Created by Marijn Heuts on 23/10/2019.
//

#ifndef PORTROYALE_BUYCANNONSSTATE_HPP
#define PORTROYALE_BUYCANNONSSTATE_HPP

#include "BaseState.hpp"
#include "Game.hpp"

class BuyCannonsState: public BaseState{
public:
    BuyCannonsState(Game* game): _game{game} { }
    ~BuyCannonsState() override = default;

    void EnterState() override;
    void LeaveState() override {};

    void ShowOptions() override;
    void HandleInput() override;
    void Update() override { };


private:
    Game* _game;

    WeightEnum Size;
    int price;
    String cannonSize[3]{
        "Small",
        "Medium",
        "Heavy"
    };

    void buyCannon(String input);
    bool validInput(String input);
};

#endif //PORTROYALE_BUYCANNONSSTATE_HPP

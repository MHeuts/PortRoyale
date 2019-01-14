//
// Created by Marijn Heuts on 10/01/2019.
//

#ifndef PORTROYALE_INITSTATE_HPP
#define PORTROYALE_INITSTATE_HPP

#include "Game.hpp"

class InitState: public BaseState{
public:
    explicit InitState(Game* game): _game{game}{ }

    ~InitState() = default;
    void EnterState() override;
    void LeaveState() override {};

    void ShowOptions() override;
    void HandleInput() override;
    void Update() override {};
private:
    Game* _game;
    String input;
};
#endif //PORTROYALE_INITSTATE_HPP

//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_HARBOURSTATE_HPP
#define PORTROYALE_HARBOURSTATE_HPP

#include "Domain/Harbour.hpp"
#include "BaseState.hpp"
#include "InitState.hpp"

class HarbourState: public BaseState {
public:

    explicit HarbourState(Game* game): _game{game}{ }

    ~HarbourState() = default;
    void EnterState() override;
    void LeaveState() override {};

    void ShowOptions() override;
    void HandleInput() override;
    void Update() override {};
private:
    Game* _game;
    String input;
};


#endif //PORTROYALE_HARBOURSTATE_HPP

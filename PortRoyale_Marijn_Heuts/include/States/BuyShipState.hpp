#ifndef PORTROYALE_BUYSHIPSTATE_HPP
#define PORTROYALE_BUYSHIPSTATE_HPP

#include "BaseState.hpp"
#include "Game.hpp"

class BuyShipState : public BaseState{
public:
    BuyShipState(Game* game): _game{game} { }
    ~BuyShipState() override = default;

    void EnterState() override;
    void LeaveState() override { };

    void ShowOptions() override;
    void HandleInput() override;
    void Update() override { };


private:
    Game* _game;

    int _availibleFunds;
};
#endif //PORTROYALE_BUYSHIPSTATE_HPP

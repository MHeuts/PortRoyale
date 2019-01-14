//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_ATSEASTATE_HPP
#define PORTROYALE_ATSEASTATE_HPP


#include "Helpers/Random.hpp"
#include "BaseState.hpp"
#include "Game.hpp"

class AtSeaState : public BaseState{
public:
    AtSeaState(Game* game, int turns): _game{game}, _turnsLeft{turns}{};

    ~AtSeaState() = default;
    void EnterState() override;
    void LeaveState() override;

    void ShowOptions() override {};
    void HandleInput() override {};
    void Update() override ;

private:
    Game* _game;
    int _turnsLeft{0};
    void _randomEncounter(int encounterRate);
    void _weatherEffect(int weatherStrength);
    void _stormEffect(int stormEffect);
};


#endif //PORTROYALE_ATSEASTATE_HPP

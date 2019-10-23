//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_BASESTATE_HPP
#define PORTROYALE_BASESTATE_HPP


#include "Helpers/String.hpp"

class BaseState {
public:
    BaseState() = default;
    virtual ~BaseState() {}

    virtual void EnterState() = 0;
    virtual void LeaveState() = 0;

    virtual void ShowOptions() = 0;
    virtual void HandleInput() = 0;
    virtual void Update() = 0;

    String input;


};


#endif //PORTROYALE_BASESTATE_HPP

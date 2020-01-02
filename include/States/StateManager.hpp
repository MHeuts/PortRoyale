//
// Created by Marijn Heuts on 08/01/2019.
//

#ifndef PORTROYALE_STATEMANAGER_HPP
#define PORTROYALE_STATEMANAGER_HPP


#include "Helpers/Stack.hpp"
#include "BaseState.hpp"
#include "Helpers/String.hpp"
#include "Helpers/Vector.hpp"

//class BaseState;

class StateManager {

public:
    StateManager() = default;


    template<class T, class ...TArgs>
    void push_state(TArgs &&...args) {
        if(_currentState != nullptr){
            _currentState->LeaveState();
            _previousState = _currentState;
        }

        _currentState = new T(std::forward<TArgs>(args)...);
        _currentState->EnterState();
    }

    bool ReturnToPreviousState(){
        if(_previousState != nullptr){
            _currentState = _previousState;
            _previousState = nullptr;
            return true;
        }
        return false;
    }

    void ShowOptions(){
        _currentState->ShowOptions();
    }

    void HandleInput(){
        _currentState->HandleInput();
    }

    void UpdateState(){
        _currentState->Update();
    }

    ~StateManager(){
        delete _currentState;
        delete _previousState;
    }

private:
    BaseState* _currentState;
    BaseState* _previousState;
    //Stack<BaseState*> _stateStack;
};


#endif //PORTROYALE_STATEMANAGER_HPP

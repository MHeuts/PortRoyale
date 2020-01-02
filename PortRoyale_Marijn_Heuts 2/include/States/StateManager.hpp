//
// Created by Marijn Heuts on 08/01/2019.
//

#ifndef PORTROYALE_STATEMANAGER_HPP
#define PORTROYALE_STATEMANAGER_HPP


#include "Helpers/Stack.hpp"
#include "BaseState.hpp"
#include "Helpers/String.hpp"
#include "Helpers/Vector.hpp"

struct state{
    BaseState *data;
    struct state *previous;

};

class StateManager {

public:
    StateManager(){

    };


    template<class T, class ...TArgs>
    void push_state(TArgs &&...args) {
        states.push_back(new T(std::forward<TArgs>(args)...));
        states[states.Size()-1]->EnterState();
    }

    bool ReturnToPreviousState(){
        BaseState *curr = nullptr;
        if(states.Size()>1){
            curr = states.pop_back();
            delete curr;
            return true;
        }
        return false;
    }

    void ShowOptions(){
        states[states.Size()-1]->ShowOptions();
    }

    void HandleInput(){
        states[states.Size()-1]->HandleInput();
    }

    void UpdateState(){
        states[states.Size()-1]->Update();
    }

    ~StateManager(){
        BaseState *curr = nullptr;
        while(states.Size() >0){
            curr = states.pop_back();
            delete curr;
        }
    }

private:
    Vector<BaseState *> states;
};


#endif //PORTROYALE_STATEMANAGER_HPP

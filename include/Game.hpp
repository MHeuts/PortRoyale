//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_GAME_HPP
#define PORTROYALE_GAME_HPP


#include <Helpers/Random.hpp>
#include "Domain/Player.hpp"
#include "States/StateManager.hpp"
#include "Domain/Harbour.hpp"

class Game {
private:
    bool _running = true;
    StateManager stateManager;
    Player _player;
    Harbour _currentHarbour;

public:
    Game();

    void Run();
    void Quit();

    StateManager &StateHandler() { return stateManager; }
    Player &player() { return  _player; }
    Ship getShip(int i) { return shipRepository[i]; }
    Harbour &GetCurrentHarbour() { return _currentHarbour; }
    Harbour getHarbour(int i) { return harbourRepository[i]; }

    void SetCurrentHarbour(Harbour harbour) { _currentHarbour = harbour; }
private:
    void setUp();
    void buildShipRepo();
    void buildHarbourRepo();
    void buildShip(char* line, int i);
    void buildHarbour(char* line, int i);
    Ship shipRepository[13];
    Harbour harbourRepository[24];

    void setHarbourDestinations();

    void buildHarbourDestinations(String line, int i);
};


#endif //PORTROYALE_GAME_HPP

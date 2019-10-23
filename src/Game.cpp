//
// Created by Marijn Heuts on 14/12/2018.
//

#include <States/InitState.hpp>
#include "Game.hpp"
#include <fstream>
#include <States/HarbourState.hpp>

Game::Game() {
};

void Game::Run() {

    setUp();

    stateManager.push_state<HarbourState>(this);

    while(_running){
        String input;

        stateManager.ShowOptions();
        stateManager.HandleInput();
        stateManager.UpdateState();

        if(_player.GetShip().IsDestroyed()){
            std::cout<< "Your Ship is destroyed and is sinking to the bottom of the ocean\n"
                        "Thank you for playing\n";
            Quit();
        }
    }
}

void Game::Quit() {
    _running = false;
}


void Game::setUp(){
    buildShipRepo();
    buildHarbourRepo();
    setHarbourDestinations();
    setHarbourGoods();

    _player.ReceiveGold(1000000);
    _player.SetShip(shipRepository[0]);

    _currentHarbour = harbourRepository[0];
}

void Game::buildShipRepo() {
    std::cout << "Loading Ships\n";
    std::ifstream stream{"Assets/schepen.csv"};
    char line[500];
    if(!stream.is_open()){
        std::cout << "Assets/schepen.csv not found\n";
        exit(1);
    }
    int linenr{-1};
    while(stream.getline(line, 500, '\n')){

        if(linenr < 0){
            linenr++;
            continue;
        }

        String linestr(line);

        buildShip((char*)linestr, linenr);

        linenr++;
    }
}

void Game::buildShip(char* line, int i){

    String items[7];

    auto size = 0;
    auto current = 0;

    char current_string[20];
    memset(current_string, 0x00, 20);

    for (size_t i = 0; i < strlen(line); i++)
    {
        if (line[i] == ';')
        {
            items[size++] = String(current_string);

            memset(current_string, 0x00, 20);
            current = 0;
            continue;
        }

        current_string[current++] = line[i];
    }

    String Special(current_string);

    shipRepository[i].SetName(items[0]);
    shipRepository[i].SetPrice(atoi((char*)items[1]));
    shipRepository[i].SetcargoSpace(atoi((char*)items[2]));
    shipRepository[i].SetCannonSpace(atoi((char*)items[3]));
    shipRepository[i].SetHitPoints(atoi((char*)items[4]));


    if(Special == "log"){
        shipRepository[i].SetWeight(Heavy);
    }
    if(Special == "klein,licht"){
        shipRepository[i].SetWeight(Light);
        shipRepository[i].SetSmall(true);
    }
    if(Special == "licht"){
        shipRepository[i].SetWeight(Light);
    }
}


void Game::buildHarbourRepo() {

    std::cout << "Loading Harbours\n";
    std::ifstream stream{"Assets/afstand_tussen_steden.csv"};
    char line[500];
    if(!stream.is_open()){
        std::cout << "Assets/afstand_tussen_steden.csv not found\n";
        exit(1);
    }
    int linenr{-4};

    String names[24];
    while(stream.getline(line, 500, '\n')){
        if(linenr < 0){
            linenr++;
            continue;
        }

        String linestr(line);

        buildHarbour((char*)linestr, linenr);

        linenr++;
    }
}


void Game::buildHarbour(char *line, int i) {
    String items[25];

    auto size = 0;
    auto current = 0;

    char current_string[20];
    memset(current_string, 0x00, 20);

    for (size_t i = 0; i < strlen(line); i++)
    {
        if (line[i] == ';')
        {
            items[size++] = String(current_string);

            memset(current_string, 0x00, 20);
            current = 0;
            continue;
        }

        current_string[current++] = line[i];
    }

    items[size] = String(current_string);

    harbourRepository[i].SetName(items[0]);

}

void Game::setHarbourDestinations() {
    std::ifstream stream{"Assets/afstand_tussen_steden.csv"};
    char line[500];
    if(!stream.is_open()){
        std::cout << "file not found\n";
        exit(1);
    }
    int linenr{-4};

    String names[24];
    while(stream.getline(line, 500, '\n')){
        if(linenr < 0){
            linenr++;
            continue;
        }

        String linestr(line);

        buildHarbourDestinations(linestr, linenr);

        linenr++;
    }

}

void Game::buildHarbourDestinations(String line, int i) {
    String items[25];

    auto size = 0;
    auto current = 0;

    char current_string[20];
    memset(current_string, 0x00, 20);

    for (size_t i = 0; i < strlen((char*)line); i++)
    {
        if (line[i] == ';')
        {
            items[size++] = String(current_string);

            memset(current_string, 0x00, 20);
            current = 0;
            continue;
        }

        current_string[current++] = line[i];
    }

    items[size] = String(current_string);

    for (int j = 1; j <= size; ++j) {
        harbourRepository[i].SetDistance(j-1, atoi((char*)items[j]), harbourRepository[j-1].GetName());
    }
}

void Game::setHarbourGoods() {
    std::ifstream stream{"Assets/goederen_hoeveelheid.csv"};
    char line[500];
    if(!stream.is_open()){
        std::cout << "file not found\n";
        exit(1);
    }
    int linenr{-4};

    String names[24];
    while(stream.getline(line, 500, '\n')){
        if(linenr < 0){
            linenr++;
            continue;
        }

        String linestr(line);

        buildHarbourGoods(linestr, linenr);

        linenr++;
    }
}

void Game::buildHarbourGoods(String linestr, int linenr) {

}


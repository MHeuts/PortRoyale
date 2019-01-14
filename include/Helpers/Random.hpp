//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_RANDOM_HPP
#define PORTROYALE_RANDOM_HPP
#include <iostream>
#include <random>
#include <ctime>


class Random {
public:

    static Random& GetInstance(){
        static Random instance;
        return instance;
    }

    Random(Random const&)          = delete;
    void operator=(Random const&)  = delete;


    int GetRandom(int lowest, int highest){

        std::uniform_int_distribution<int> distribution(lowest, highest);
        return distribution(generator);
    }

    int GetRandom(int highest){
        std::uniform_int_distribution<int> distribution(1, highest);
        return distribution(generator);
    }


private:
    std::default_random_engine generator;

    Random(){
        generator.seed(time(0));
    }
};


#endif //PORTROYALE_RANDOM_HPP

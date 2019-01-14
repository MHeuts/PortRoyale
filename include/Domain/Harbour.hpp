//
// Created by Marijn Heuts on 14/12/2018.
//

#ifndef PORTROYALE_HARBOUR_HPP
#define PORTROYALE_HARBOUR_HPP

#include "Helpers/String.hpp"
#include "Domain/Goods.hpp"

class Harbour {
private:
    String _name;
    Goods _goods[15];
    int _distances[24];
};


#endif //PORTROYALE_HARBOUR_HPP

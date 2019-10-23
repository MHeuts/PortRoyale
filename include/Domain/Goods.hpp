//
// Created by Marijn Heuts on 14/01/2019.
//

#ifndef PORTROYALE_GOODS_HPP
#define PORTROYALE_GOODS_HPP

#include "Helpers/String.hpp"

class Goods{
private:
    String _name;
    int minAmount;
    int maxAmount;
    int ammount;
    int price;
    int minPrice;
    int maxPrice;

public:
    void setName(String name){ _name = name; }
    void setAmountMinMax(int min, int max){ minAmount = min, maxAmount = max; }
    void setPriceMinMax(int min, int max){ minPrice = min, maxPrice = max; }

    void randomizePrice();
    void randomizeAmmount();

    int GetAmmount() { return ammount; }
    int GetPrice() { return price; }
};


#endif //PORTROYALE_GOODS_HPP
//
// Created by Marijn Heuts on 14/01/2019.
//

#ifndef PORTROYALE_GOODS_HPP
#define PORTROYALE_GOODS_HPP

#include "Helpers/String.hpp"

class Goods{
private:
    String _name;
    int minAmount = 0;
    int maxAmount = 0;
    int ammount = 0;
    int price = 0;
    int minPrice = 0;
    int maxPrice = 0;

public:
    void setName(String name){ _name = name; }
    void setAmountMinMax(int min, int max){ minAmount = min, maxAmount = max; }
    void setPriceMinMax(int min, int max){ minPrice = min, maxPrice = max; }
    void setAmmount(int ammount) { ammount = ammount; }

    void randomizePrice();
    void randomizeAmmount();

    void IncreaseAmount(int amount);
    void DecreaseAmount(int amount);

    String GetName() { return _name; }
    int GetAmmount() { return ammount; }
    int GetPrice() { return price; }
};


#endif //PORTROYALE_GOODS_HPP
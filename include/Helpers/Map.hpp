//
// Created by Marijn Heuts on 11/01/2019.
//

#ifndef PORTROYALE_MAP_HPP
#define PORTROYALE_MAP_HPP

template <typename TKey, TValue>
struct item{
    TKey* key_;
    TPair* value_;
    struct item *next;
};

template <typename TKey, TValue>
class Map{
private:
    int size_, maxSize;

public:
    Map(): size_{0} {

    };



};
#endif //PORTROYALE_MAP_HPP

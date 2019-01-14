//
// Created by Marijn Heuts on 09/01/2019.
//

#ifndef PORTROYALE_STACK_HPP
#define PORTROYALE_STACK_HPP

template <typename T>
struct item{
    T *data;
    struct item *next;
};


template <typename T>
class Stack {
public:
    Stack(): counter{0} {
        _head = nullptr;
    };

    Stack(const T &data): counter{0} {
        _head->data = &data;
        _head->next = nullptr;
        ++ counter;
    };

    void Push(const T &data){
        auto ptr = item<T>();
        ptr->data = &data;
        ptr->next = _head;
        _head = ptr;
        ++ counter;
    }

    ~Stack(){
    }

    const T* Peek(){
        return _head->data;
    }

    const int count(){
        return counter;
    }

    const T* Pop(){
        auto data = _head->data;
        _head = _head->next;
        -- counter;
        return data;
    }

    const bool isEmpty(){
        return counter == 0;
    }




private:
    int counter;
    item<T> *_head;
};



#endif //PORTROYALE_STACK_HPP

//
// Created by Marijn Heuts on 10/01/2019.
//

#ifndef PORTROYALE_VECTOR_HPP
#define PORTROYALE_VECTOR_HPP

template <typename T>
class Vector {
private:
    int capacity_;
    int size_;
    T* data_;


public:
    Vector(): size_{0},
                capacity_{10},
                data_{new T[capacity_]} { };

    Vector(int capacity): size_{0},
                            capacity_{capacity},
                            data_{new T[capacity]} { };

    Vector(const Vector& other): size_{other.size_},
                                     capacity_{other.capacity_},
                                     data_{new T[other.capacity_]}{
        for (int i = 0; i < size_; ++i) {
            data_[i] = other[i];
        }
    };

    Vector(Vector&& other): size_{other.size_},
                                capacity_{other.capacity_},
                                data_{new T[other.capacity_]}{

        for (int i = 0; i < size_; ++i) {
            data_[i] = other[i];
        }

        other.data_ = nullptr;
        other.size_ = other.capacity_ = 0;
    };

    ~Vector() {
        if(data_ != nullptr)
            delete[] data_;
    };

    Vector& operator = (const Vector& other) {
        if (&other == this)
            return *this;

        if(data_ != nullptr)
            delete[] data_;

        data_ = new T[other.capacity_];
        capacity_ = other.capacity_;
        size_ = other.size_;

        return *this;
    };

    Vector& operator = (Vector&& other) {
        if(&other == this)
            return *this;

        if(data_ != nullptr)
            delete[] data_;

        data_ = new T[other.capacity_];
        capacity_ = other.capacity_;
        size_ = other.size_;

        other.data_ = nullptr;
        other.size_ = other.capacity_ = 0;

        return *this;
    };

    void push_back(const T &value) {
        if (size_ >= capacity_) increaseCapacity(2 * capacity_);
        data_[size_] = value;
        ++size_;
    };

    void push_back(T&& value){
        if (size_ >= capacity_) increaseCapacity(2 * capacity_);
        data_[size_] = value;
        ++size_;
    }

    const T& operator[](int i) const {
        return data_[i];
    };

    T& operator[](int i ) {
        return data_[i];
    }

    T pop_back(){
        if(size_ <= 0)
            return nullptr;
       T back =  data_[size_-1];
        --size_;
        return back;
    };

    T back() const {
        return data_[size_];
    };

    int Size() const {
        return size_;
    };

    bool Empty() const {
        return size_ <= 0;
    };

    void Clear() {
        delete[] data_;
        size_ = 0;
        capacity_=10;
        data_ = new T[capacity_];
    };

private:
    void increaseCapacity(int new_cap) {
        if (new_cap <= capacity_)
            return;

        T* temp_arr = new T[new_cap];

        for(int i = 0; i < capacity_; ++i) {
            temp_arr[i] = data_[i];
        }

        capacity_ = new_cap;

        delete[] data_;
        data_ = temp_arr;
    };
};


#endif //PORTROYALE_VECTOR_HPP

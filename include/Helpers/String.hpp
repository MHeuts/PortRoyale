//
// Created by Marijn Heuts on 08/01/2019.
//

#ifndef PORTROYALE_STRING_HPP
#define PORTROYALE_STRING_HPP

#include <iostream>
class String{

public:
    String() :string_{nullptr}, length_{0} { };

    String(const char* other): string_{new char[length_]}, length_{stringLength(other)} {
        strcpy(string_, other);
    };

    String(const String& other): string_{new char[length_]}, length_{other.length_} {
        strcpy(string_, other.string_);
    };

    String(String&& other) {
        other.string_ = nullptr;
    };

    ~String(){
        delete[] string_;
    };

    operator char*() const {
        return string_;
    };

    String& operator = (const char* other) {
        if(string_ != other){
            length_ = stringLength(other);
            delete[] string_;
            string_ = new char[length_];
            strcpy(string_, other);
        }
        return *this;
    };

    String& operator = (const String& other) {
        if (this != &other){
            length_ = stringLength(other);
            delete[] string_;
            string_ = new char[length_];
            strcpy(string_, other.string_);
        }
        return *this;
    };

    String& operator = (String&& other) {
        if(&other == this)
            return *this;

        delete[] string_;

        length_ = stringLength(other);

        string_ = new char[length_];
        strcpy(string_, other.string_);

        return *this;
    };

    bool operator == (const char* other) {
        if(length_ != stringLength(other))
            return false;

        for (int i = 0; i < length_; ++i) {
            if(string_[i] != other[i])
                return false;
        }
        return true;
    };

    bool operator == (const String& other) {
        if(length_ != other.length_){
            return false;
        }
        for(int i =0; i <= length_; i++){
            if(string_[i] != other[i]){
                return false;
            }
        }
        return true;
    };

    String& operator +=(const String& other) {
        auto length1 = length_ + stringLength(other);

        char* temp = new char[length1];

        for (unsigned j=0; j < length_; j++)
            temp[j] = string_[j];

        for (unsigned i=0; i < other.length_; i++)
            temp[length_+i] = other[i];

        delete[] string_;
        length_ = length1;
        string_ = temp;
        return *this;
    };

    friend std::ostream& operator <<(std::ostream& os, const String& other) {
        os << other.string_;
        return os;
    };

    friend std::istream& operator >>(std::istream& is, String& other) {
        char* temp = new char[1000];
        is >> temp;
        other = String(temp);
        delete[] temp;

        return is;
    };

private:

    size_t length_;
    char* string_;

    size_t stringLength(const char* c) {
        size_t result = 0;
        while (c[result] != '\0') {
            ++result;
        }
        return ++result;
    };
};
#endif //PORTROYALE_STRING_HPP

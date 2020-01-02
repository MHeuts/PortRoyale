//
// Created by Marijn Heuts on 08/01/2019.
//

#ifndef PORTROYALE_STRING_HPP
#define PORTROYALE_STRING_HPP

#include <cstring>
#include <iostream>
#include <Helpers/Vector.hpp>
class String{

public:
    String() :string_{new char[length_]}, length_{0} { };

    String(const char* other) : string_{new char[length_]},
                                length_{strlen(other)+1} {
        strcpy(string_, other);
    };

    String(const String& other) :   string_{new char[length_]},
                                    length_{other.length_+1} {
        if(this != &other) {
            strcpy(string_, other.string_);
        }
    };

    String(String&& other) {
        string_ = other.string_;
        length_ = other.length_;
        other.string_ = nullptr;
    };

    String& operator = (const char* other) {
        if(string_ != other){
            length_ = strlen(other) +1;
            delete[] string_;
            string_ = new char[length_];
            strcpy(string_, other);
        }
        return *this;
    };

    String& operator = (const String& other) {
        if (this != &other){
            length_ = (other.length_);
            delete[] string_;
            string_ = new char[other.length_];
            strcpy(string_, other.string_);
        }
        return *this;
    };

    String& operator = (String&& other) {
        if(this != &other){
            delete[] string_;
            length_ = other.length_;
            string_ = other.string_;

            other.string_ = nullptr;
        }

        return *this;
    };

    ~String(){
        delete[] string_;
    };

    operator char*() const {
        return string_;
    };


    bool operator == (const char* other) {
        return strcmp(string_, other) == 0;
    };

    bool operator == (const String& other) {
        return strcmp(string_, other) == 0;
    };

    String& operator +=(const String& other) {
        auto newLength = length_ + other.length_;

        char* temp = new char[newLength];

        for (unsigned j=0; j < length_; j++)
            temp[j] = string_[j];

        for (unsigned i=0; i < other.length_; i++)
            temp[length_+i] = other.string_[i];

        delete[] string_;
        length_ = newLength;
        string_ = temp;
        return *this;
    };

    String &operator += (const char* other){

        char* temp = new char[length_ + strlen(other)+1];
        for (unsigned j=0; j < length_; j++)
            temp[j] = string_[j];

        for (unsigned i=0; i < strlen(other)+1; i++)
            temp[length_+i] = other[i];

        delete[] string_;
        length_ = length_ + strlen(other)+1;
        string_ = temp;
        return *this;
    }

    String &operator += (const char other){

        char* temp = new char[length_ + 1];
        for (unsigned j=0; j < length_; j++)
            temp[j] = string_[j];

        temp[length_] = other;

        delete[] string_;
        length_ = length_ + 1;
        string_ = temp;
        return *this;
    }

    char &operator [] (int i){
        return string_[i];
    }

    friend std::ostream& operator <<(std::ostream& os, const String& other) {
        os << other.string_;
        return os;
    };

    friend std::istream& operator >>(std::istream& is, String& other) {
        Vector<char> temp;

        while(is.good()) {
            char c;
            is.get(c);
            if (c == '\0' || c == '\n') break;
            temp.push_back(c);
        }
        delete[] (other.string_);
        other.length_ = temp.Size();
        other.string_ = new char[other.length_ + 1];
        for (int i = 0; i < other.length_; i++) {
            other.string_[i] = temp[i];
        }
        other.string_[other.length_] = '\0';
        return is;
    };

    Vector<String> split(const char splitter) const {

        Vector<String> parts{};
        int index;
        String part{""};

        index = 0;
        while (index < length_) {
            if (string_[index] == splitter) {
                parts.push_back(part);
                part.empty();
            } else {
                char addition = string_[index];
                part += addition;
            }
            ++index;
        }
        parts.push_back(part);
        return parts;
    }

    void empty(){
        delete[]string_;
        length_ = 0;
        string_ = new char[length_];
    };

private:

    size_t length_;
    char* string_;

};

#endif //PORTROYALE_STRING_HPP

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
    String() :string_{nullptr}, length_{0} { };

    String(const char* other) : string_{new char[stringLength(other)]},
                                length_{stringLength(other)} {
        strcpy(string_, other);
    };

    String(const String& other) :   string_{new char[other.length_ + 1]},
                                    length_{other.length_} {
        strcpy(string_, other.string_);
    };

    String(String&& other) {
        string_ = other.string_;
        length_ = other.length_;
        other.string_ = nullptr;
    };

    String& operator = (const char* other) {
        if(string_ != other){
            length_ = strlen(other);
            delete[] string_;
            string_ = new char[length_];
            strcpy(string_, other);
        }
        return *this;
    };

    String& operator = (const String& other) {
        if (this != &other){
            length_ = stringLength(other.string_);
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

        length_ = stringLength(other.string_);

        string_ = new char[length_];
        strcpy(string_, other.string_);

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
        for(int i =0; i <= length_; i++){
            if(string_[i] != other.string_[i]){
                return false;
            }
        }
        return true;
    };

    String& operator +=(const String& other) {
        auto newLength = length_ + stringLength(other.string_);

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
        String cur{*this};
        length_ = length_ + strlen(other);
        delete[] string_;
        string_ = new char[length_+1];

        strcpy(string_, cur.string_);
        strcat(string_, other);

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
                part = "";
            } else {
                char addition[2];
                strncpy(addition, &string_[index], 1);
                addition[1] = '\0';
                part += addition;
            }
            ++index;
        }

        parts.push_back(part);
        return parts;
    }

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

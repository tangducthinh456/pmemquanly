#ifndef HOUSE_H_INCLUDED
#define HOUSE_H_INCLUDED

//class Ground;

#include "Ground.h"

class House : public Ground
{
protected:
    int numFloor;

public:
    int getNumFloor(){return numFloor;}
    void setNumFloor(int numFloor){this->numFloor = numFloor;}

    void toString()
    {
        std::cout << std::endl;
        std::cout.width(4); std::cout << std::left << "";
        std::cout.width(6); std::cout << std::left << ID;
        std::cout.width(10); std::cout << std::left << "House";
        std::cout.width(27); std::cout  << std::left << address;
        std::cout.width(18); std::cout  << std::left << price;
        std::cout.width(20); std::cout  << std::left << square;
        std::cout.width(20); std::cout  << std::left << facadeWidth;
        std::cout.width(25); std::cout  << std::left << numFloor;
        std::cout.width(25); std::cout  << std::left << "Hidden";
        std::cout.width(26); std::cout  << std::left << "Hidden";
        std::cout.width(22); std::cout  << std::left << "Hidden";
        std::cout << std::endl;
    }
};

#endif // HOUSE_H_INCLUDED

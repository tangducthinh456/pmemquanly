#ifndef GARDENHOUSE_H_INCLUDED
#define GARDENHOUSE_H_INCLUDED

#include <vector>

#include "House.h"

//class House;

class GardenHouse : public House
{
private:
    int houseSquare;
    int gardenSquare;
    std::vector<House> listAdjacentHouse;
    std::vector<std::string> listIdAdjacentHouse;

public:
    int getHouseSquare(){return houseSquare;}
    void setHouseSquare(int houseSquare){this->houseSquare = houseSquare;}

    int getGardenSquare(){return gardenSquare;}
    void setGardenSquare(int gardenSquare){this->gardenSquare = gardenSquare;}

    std::vector<House> getListAdjacentHouse(){return listAdjacentHouse;}
    void addAdjacentHouse(House house){listAdjacentHouse.push_back(house);}

    std::vector<std::string> getListIdAdjacentHouse(){return listIdAdjacentHouse;}
    void setListIdAdjacentHouse(std::vector<std::string> lis)
    {
        if (lis[0] == "N") return;
        for (int i = 0; i < lis.size(); i++) listIdAdjacentHouse.push_back(lis[i]);
    }

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
        std::cout.width(25); std::cout  << std::left << houseSquare;
        std::cout.width(26); std::cout  << std::left << gardenSquare;
        for (int i = 0; i < listIdAdjacentHouse.size(); i++) std::cout << listIdAdjacentHouse[i] << " ";
        std::cout << std::endl;
    }

};

#endif // GARDENHOUSE_H_INCLUDED

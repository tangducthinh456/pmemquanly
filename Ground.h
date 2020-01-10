#ifndef GROUND_H_INCLUDED
#define GROUND_H_INCLUDED
#include <iomanip>
#include <iostream>
#include<vector>
#include<string>

class GardenHouse;

class Ground
{
protected:
    std::string address;
    int price;
    int facadeWidth;
    int square;
    std::string ID;

private:
    std::vector<GardenHouse> listGardenHouse;
    std::vector<std::string> listIdGardenHouse;

public:
    std::string getAddress(){return address;}
    void setAddress(std::string address){this->address = address;}

    int getPrice(){return price;}
    void setPrice(int price){this->price = price;}

    int getFacadeWidth(){return facadeWidth;}
    void setFacadeWidth(int facadeWidth){this->facadeWidth = facadeWidth;}

    int getSquare(){return square;}
    void setSquare(int square){this->square = square;}

    std::string getID(){return ID;}
    void setID(std::string ID){this->ID = ID;}

    std::vector<GardenHouse> getListGardenHouse(){return listGardenHouse;}
    void addGardenHouse(GardenHouse house);//{listGardenHouse.push_back(house);}

    std::vector<std::string> getListIdGardenHouse(){return listIdGardenHouse;}
    void setListIdGardenHouse(std::vector<std::string> lis)
    {
        if (lis[0] == "N") return;
        for (int i = 0; i < lis.size(); i++) listIdGardenHouse.push_back(lis[i]);
    }

    void toString()
    {
        std::cout << std::endl;
        std::cout.width(4); std::cout << std::left << "";
        std::cout.width(6); std::cout << std::left << ID;
        std::cout.width(10); std::cout << std::left << "Ground";
        std::cout.width(27); std::cout  << std::left << address;
        std::cout.width(18); std::cout  << std::left << price;
        std::cout.width(20); std::cout  << std::left << square;
        std::cout.width(20); std::cout  << std::left << facadeWidth;
        std::cout.width(25); std::cout  << std::left << "None";
        std::cout.width(25); std::cout  << std::left << "None";
        std::cout.width(26); std::cout  << std::left << "None";
        for (int i = 0; i < listIdGardenHouse.size(); i++) std::cout << listIdGardenHouse[i] << " ";
        std::cout << std::endl;
    }

};

#endif // GROUND_H_INCLUDED

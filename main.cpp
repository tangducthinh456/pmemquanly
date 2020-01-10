#include <fstream>
#include <sstream>
#include <iterator>
#include <windows.h>
#include "GardenHouse.h"

using namespace std;

void getDataFromFileToDataStruct(vector<Ground> &listGroundInDB, vector<GardenHouse> &listGardenHouseInDB)
{
    ifstream file("management.txt");
    while(!file.eof())
    {
        string Id;
        string address;
        int price;
        int square;
        int facadeWidth;
        int numFloor;
        int houseSquare;
        int groundSquare;
        file >> Id >> address >> price >> square >> facadeWidth >> numFloor >> houseSquare >> groundSquare;
        file.ignore();

        string line;
        getline(file, line);
        stringstream id(line);
        istream_iterator<string> beg(id);
        istream_iterator<string> en;
        vector<string> vstring(beg, en);

        if (Id[0] == 'H')
        {
            GardenHouse* house = new GardenHouse;
            house->setID(Id);
            house->setAddress(address);
            house->setPrice(price);
            house->setSquare(square);
            house->setFacadeWidth(facadeWidth);
            house->setNumFloor(numFloor);
            house->setHouseSquare(houseSquare);
            house->setGardenSquare(groundSquare);
            house->setListIdAdjacentHouse(vstring);
            listGardenHouseInDB.push_back(*house);
        }
        else if (Id[0] == 'G')
        {
            Ground* ground = new Ground;
            ground->setID(Id);
            ground->setAddress(address);
            ground->setPrice(price);
            ground->setSquare(square);
            ground->setFacadeWidth(facadeWidth);
            ground->setListIdGardenHouse(vstring);
            listGroundInDB.push_back(*ground);
        }
    }
    file.close();

    for (int i = 0; i < listGroundInDB.size(); i++)
    {
        for (int j = 0; j < listGroundInDB[i].getListIdGardenHouse().size(); j++)
        {
            for (int k = 0; k < listGardenHouseInDB.size(); k++)
            {
                if (listGroundInDB[i].getListIdGardenHouse().at(j) == listGardenHouseInDB.at(k).getID())
                {
                    listGroundInDB[i].addGardenHouse(listGardenHouseInDB[k]);
                }
            }
        }
    }

    for (int i = 0; i < listGardenHouseInDB.size(); i++)
    {
        for (int j = 0; j < listGardenHouseInDB[i].getListIdAdjacentHouse().size(); j++)
        {
            for (int k = 0; k < listGardenHouseInDB.size(); k++)
            {
                if (listGardenHouseInDB[i].getListIdAdjacentHouse().at(j) == listGardenHouseInDB.at(k).getID())
                {
                    listGardenHouseInDB[i].addAdjacentHouse(listGardenHouseInDB[k]);
                }
            }
        }
    }
}

void printColumnName()
{
    cout << endl;
    cout.width(4); cout << left << "";
    cout.width(6); cout << left << "Id";
    cout.width(10); cout << left << "Type";
    cout.width(27); cout  << left << "Address";
    cout.width(18); cout  << left << "Price($)";
    cout.width(20); cout  << left << "Square(m2)";
    cout.width(20); cout  << left << "Facade width(m)";
    cout.width(25); cout  << left << "Number of floor";
    cout.width(25); cout  << left << "House square(m2)";
    cout.width(26); cout  << left << "Ground square(m2)";
    cout.width(22); cout  << left << "House contain or adjacent";
    cout << endl;
}

void printInforOfAllGroundAndHouse(vector<Ground> &listGroundInDB, vector<GardenHouse> &listGardenHouseInDB)
{
    printColumnName();
    for (int i = 0; i < listGroundInDB.size(); i++) listGroundInDB[i].toString();
    for (int i = 0; i < listGardenHouseInDB.size(); i++) listGardenHouseInDB[i].toString();
}

void searchById(string id, vector<Ground> &listGroundInDB, vector<GardenHouse> &listGardenHouseInDB)
{
    for (int i = 0; i < listGroundInDB.size(); i++)
    {
        if (listGroundInDB[i].getID() == id) listGroundInDB[i].toString();
    }

    for (int i = 0; i < listGardenHouseInDB.size(); i++)
    {
        if (listGardenHouseInDB[i].getID() == id) listGardenHouseInDB[i].toString();
    }
}

void searchByAddress(string add, vector<Ground> &listGroundInDB, vector<GardenHouse> &listGardenHouseInDB)
{
    for (int i = 0; i < listGroundInDB.size(); i++)
    {
        if (listGroundInDB[i].getAddress() == add) listGroundInDB[i].toString();
    }

    for (int i = 0; i < listGardenHouseInDB.size(); i++)
    {
        if (listGardenHouseInDB[i].getAddress() == add) listGardenHouseInDB[i].toString();
    }
}

void searchByPrice(int price, vector<Ground> &listGroundInDB, vector<GardenHouse> &listGardenHouseInDB)
{
    for (int i = 0; i < listGroundInDB.size(); i++)
    {
        if (listGroundInDB[i].getPrice() == price) listGroundInDB[i].toString();
    }

    for (int i = 0; i < listGardenHouseInDB.size(); i++)
    {
        if (listGardenHouseInDB[i].getPrice() == price) listGardenHouseInDB[i].toString();
    }
}

void searchByFacadeWidth(int fw, vector<Ground> &listGroundInDB, vector<GardenHouse> &listGardenHouseInDB)
{
    for (int i = 0; i < listGroundInDB.size(); i++)
    {
        if (listGroundInDB[i].getFacadeWidth() == fw) listGroundInDB[i].toString();
    }

    for (int i = 0; i < listGardenHouseInDB.size(); i++)
    {
        if (listGardenHouseInDB[i].getFacadeWidth() == fw) listGardenHouseInDB[i].toString();
    }
}

void searchBySquare(int square, vector<Ground> &listGroundInDB, vector<GardenHouse> &listGardenHouseInDB)
{
    for (int i = 0; i < listGroundInDB.size(); i++)
    {
        if (listGroundInDB[i].getSquare() == square) listGroundInDB[i].toString();
    }

    for (int i = 0; i < listGardenHouseInDB.size(); i++)
    {
        if (listGardenHouseInDB[i].getSquare() == square) listGardenHouseInDB[i].toString();
    }
}

void searchByNumberOfFloor(int num, vector<Ground> &listGroundInDB, vector<GardenHouse> &listGardenHouseInDB)
{
    for (int i = 0; i < listGardenHouseInDB.size(); i++)
    {
        if (listGardenHouseInDB[i].getNumFloor() == num) listGardenHouseInDB[i].toString();
    }
}

void searchByHouseSquare(int hs, vector<Ground> &listGroundInDB, vector<GardenHouse> &listGardenHouseInDB)
{
    for (int i = 0; i < listGardenHouseInDB.size(); i++)
    {
        if (listGardenHouseInDB[i].getHouseSquare() == hs) listGardenHouseInDB[i].toString();
    }
}

void searchByGardenSquare(int gs, vector<Ground> &listGroundInDB, vector<GardenHouse> &listGardenHouseInDB)
{
    for (int i = 0; i < listGardenHouseInDB.size(); i++)
    {
        if (listGardenHouseInDB[i].getGardenSquare() == gs) listGardenHouseInDB[i].toString();
    }
}

void searchAdjacentHouse(string id, vector<Ground> &listGroundInDB, vector<GardenHouse> &listGardenHouseInDB)
{
    printColumnName();
    GardenHouse house;
    for (int i = 0; i < listGardenHouseInDB.size(); i++)
    {
        if (listGardenHouseInDB[i].getID() == id)
        {
            house = listGardenHouseInDB[i];
            break;
        }
    }
    for (int i = 0; i < house.getListIdAdjacentHouse().size(); i++)
        searchById(house.getListIdAdjacentHouse()[i], listGroundInDB, listGardenHouseInDB);
}

int main()
{
    vector<Ground> listGroundInDB;
    vector<GardenHouse> listGardenHouseInDB;

    getDataFromFileToDataStruct(listGroundInDB, listGardenHouseInDB);

    cout.width(30); cout << left << "";

    string s = "Welcome to my project real estate management software!";

    for (int i = 0; i < s.length(); i++)
    {
        Sleep(50);
        cout <<s[i];
    }
    cout << endl;
    Sleep(3000);

    int choice;

    do
    {
        cout << "________________________________________________________________" << endl << endl;
        Sleep(500);
        cout << "1.Display information of all ground and house" << endl << endl;
        cout << "2.Search by" << endl << endl;
        cout << "0.Exit" << endl << endl;
        cout <<"---------------------------------------------------------------"<< endl << endl;
        cout << "Enter your choice : "; cin >> choice;

        system("cls");

        switch(choice)
        {
        case 1:

            printColumnName();
            printInforOfAllGroundAndHouse(listGroundInDB, listGardenHouseInDB);
            system("pause");
            break;
        case 2:
            int choice2;

            do
            {
                cout << "________________________________________________________________" << endl << endl;
                Sleep(500);
                cout << "1.Search by id" << endl << endl;
                cout << "2.Search by address" << endl << endl;
                cout << "3.Search by price" << endl << endl;
                cout << "4.Search by square" << endl << endl;
                cout << "5.Search by facade width" << endl << endl;
                cout << "6.Search by number of floor" << endl << endl;
                cout << "7.Search by house square" << endl << endl;
                cout << "8.Search by garden square" << endl << endl;
                cout << "9.Search adjacent house" << endl << endl;
                cout << "0.Back" << endl << endl;
                cout <<"---------------------------------------------------------------"<< endl << endl;
                cout << "Enter your choice : "; cin >> choice2;

            system("cls");
            switch (choice2)
            {
            case 1:
            {
                string id;
                cout << "Enter id : ";
                cin >> id;
                system("cls");
                printColumnName();
                searchById(id, listGroundInDB, listGardenHouseInDB);
                system("pause");
                break;
            }
            case 2:
            {
                string address;
                cout << "Enter address : ";
                cin >> address;
                system("cls");
                printColumnName();
                searchByAddress(address, listGroundInDB, listGardenHouseInDB);
                system("pause");
                break;
            }
            case 4:
            {
                int s;
                cout << "Enter square : ";
                cin >> s;
                system("cls");
                printColumnName();
                searchBySquare(s, listGroundInDB, listGardenHouseInDB);
                system("pause");
                break;
            }
            case 3:
            {
                int price;
                cout << "Enter price : ";
                cin >> price;
                system("cls");
                printColumnName();
                searchByPrice(price, listGroundInDB, listGardenHouseInDB);
                system("pause");
                break;
            }
            case 5:
            {
                int fw;
                cout << "Enter facade width : ";
                cin >> fw;
                system("cls");
                printColumnName();
                searchByFacadeWidth(fw, listGroundInDB, listGardenHouseInDB);
                system("pause");
                break;
            }
            case 6:
            {
                int num;
                cout << "Enter number of floor : ";
                cin >> num;
                system("cls");
                printColumnName();
                searchByNumberOfFloor(num, listGroundInDB, listGardenHouseInDB);
                system("pause");
                break;
            }
            case 7:
            {
                int hs;
                cout << "Enter house square : ";
                cin >> hs;
                system("cls");
                printColumnName();
                searchByHouseSquare(hs, listGroundInDB, listGardenHouseInDB);
                system("pause");
                break;
            }
            case 8:
            {
                int gs;
                cout << "Enter garden square : ";
                cin >> gs;
                system("cls");
                printColumnName();
                searchByGardenSquare(gs, listGroundInDB, listGardenHouseInDB);
                system("pause");
                break;
            }
            case 9:
            {
                string id;
                cout << "Enter id : ";
                cin >> id;
                system("cls");
                printColumnName();
                searchAdjacentHouse(id, listGroundInDB, listGardenHouseInDB);
                system("pause");
                break;
            }
            default:
                break;
            }
            system("cls");
            } while (choice2 != 0);

        default :
            break;
        }
        system("cls");
    } while (choice != 0);
    return 0;
}

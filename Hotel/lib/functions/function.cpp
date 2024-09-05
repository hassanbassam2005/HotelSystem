#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include "../hashtable/hash.cpp"
#include "../ErrorHandling/Error.h"

struct DataContainer
{
    HashTable Table;
    HashTable TablePrice;
    DataContainer() : Table(100), TablePrice(100) {}
    std::vector<std::string> RoomsType;
    int numberOfRooms = 0;
    int price = 0;
    ~DataContainer()
    {
        delete& price;
    }
};  

class Employee  : public DataContainer
{
private:
    DataContainer& data;
public:
    Employee(DataContainer& Data) : data(Data){}
    void TypeOfRooms()
    {
        int numberOfTypes = 0;
        std::cout << "How many types you have in the hotel: \n";
        std::cin >> numberOfTypes;
        while (!ValidInteger(&numberOfTypes));
        std::cin.ignore();
        std::cout << "Enter the types of the rooms:\n";
        std::string type;
        for (int i = 0; i < numberOfTypes; ++i)
        {
            std::getline(std::cin, type);
            while (!ValidString(&type));
            data.RoomsType.push_back(type);
        }
    }

    void RoomsNumber()
    {
        std::cout << "Enter the number of each type:\n";
        for (const auto& type : RoomsType)
        {
            int count;
            std::cout << "Number of " << type << " rooms: ";
            std::cin >> count;
            while (!ValidInteger(&count));
            data.Table.insert(type, count);
            data.TablePrice.insert(type, count);
        }
    }

    void RemoveRoom()
    {
        std::string Type;
        std::cout << "enter you want to remove: " << std::endl;
        std::getline(std::cin, Type);
        while (!ValidString(&Type));
        data.Table.remove(Type);
        data.TablePrice.remove(Type);
    }

    void RoomPrice()
    {
        int priceOfType = 0;
        std::cout << "enter th price of each type:\n";
        for (const auto& Type : data.RoomsType)
        {
            std::cout << Type << " price: ";
            std::cin >> price;
            while (!ValidInteger(&priceOfType));
            data.TablePrice.insert(Type, price);
        }
        for (const auto& Type : data.RoomsType)
        {
            std::cout << "The price of the " << Type << " is " << data.TablePrice.search(Type) << "$\n";
        }
    }

    ~Employee() 
    {
        delete &data;
    }
};


class User : public DataContainer
{
private:
    DataContainer& Data;
public:
    User(DataContainer& data) : Data(data) {}
    void RoomSearch()
    {
        std::string userType;
        std::cout << "enter the type to be searched and to be booked ";
        std::getline(std::cin, userType);
        while (!ValidString(&userType));
        if ((bool)Data.Table.search(userType))
        {
            std::cout << "the number of Rooms is " << Data.Table.search(userType) << std::endl;
        }
        else
        {
            std::cout << "there is no room\n";
        }
    }

    void RoomBook()
    {
        std::string Type;
        std::cout << "enter type to book it:\n";
        std::cin >> Type;
        while (!ValidString(&Type));
        std::cout << "Enter number of rooms you want to book: \n";
        std::cin >> numberOfRooms;
        while (!ValidInteger(&numberOfRooms));
        int numberOfRemain = Data.Table.search(Type) - numberOfRooms;
        if (numberOfRemain == 0)
        {
            std::cout << "there is no room remain\n";
        }
        else if (numberOfRemain < 0)
        {
            std::cout << "cant book this type of room\n";
        }
        else
        {
            std::cout << "The room booked succefully\n";
            std::cout << "The number of the remaining room is: " << numberOfRemain << std::endl;
            Data.Table.insert(Type, numberOfRemain);
            if ((bool)Data.Table.search(Type))
            {
                int NumberOfPrice = Data.numberOfRooms * price;
                Data.TablePrice.insert(Type, NumberOfPrice);
                std::cout << "the price of " << Type << " is " << Data.TablePrice.search(Type) << "$" << std::endl;
            }
        }

    }

    void cancleRoom()
    {
        std::string Type;
        std::cout << "enter the type of the booked room:\n";
        std::getline(std::cin, Type);
        while (!ValidString(&Type));
        if ((bool)RoomBook)
        {
            int roomNumber = Data.Table.search(Type) + numberOfRooms;
            int oldPrice = 0;
            std::cout << "cancled successful" << std::endl;
            Data.Table.insert(Type, roomNumber);
            Data.TablePrice.insert(Type, oldPrice);
            std::cout << "the price is " << Data.TablePrice.search(Type) << std::endl;
        }
        else
        {
            std::cout << "there is no room booked\n";
        }
    }
    
    ~User()
    {
        delete& Data;
    }
};




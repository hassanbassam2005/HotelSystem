#include "functions/function.cpp"
#include "enums/enums.h"
#include "Login/login.cpp"
#include "Register/register.cpp"
#include "printing/printing.h"

bool exists(std::string filename);
std::string input_name(std::string filename);

int main()
{
	DataContainer* data = new DataContainer;
	bool loggedIn = false;
	bool loggedInEmployee = false;
	bool loggedInUser = false;
	Version();

	do
	{
		MainMenu();
		std::string userInput;
		std::getline(std::cin, userInput);
		Selection selection = Hash(userInput);

		switch (selection)
		{
		case Selection::LOGINEMPLOYEE:
			if (!exists("Employee.txt"))
			{
				std::cout << "please register first\n";
				RegisterEmployee();
			}
			else
			{
				loggedIn = isLoggedInEmployee();
				loggedInEmployee = true;

			}
			break;
		case Selection::REGISTEREMPLOYEE:
			RegisterEmployee();
			break;
		case Selection::LOGINUSER:
			if (!exists("User.txt"))
			{
				std::cout << "please register first\n";
				RegisterUser();
			}
			else
			{
				loggedIn = isLoggedInUser();
				loggedInUser = true;
			}
			break;
		case Selection::REGISTERUSER:
			RegisterUser();
			break;
		default:
			Error();
		}
	} while (!loggedIn);

	if (loggedInEmployee)
	{
		std::string name = input_name("Employee.txt");
		Employee emp(*data); 
		while (loggedInEmployee)
		{
			std::cout << "welcome " << name << "\nplease write .Help if you want help in menu\n";
			std::string userInput;
			std::getline(std::cin, userInput);
			EmployeeSelection mainselection = Employeehash(userInput);
			switch (mainselection)
			{
			case EmployeeSelection::HELP:
				system("cls");
				printHelpEmployee();
				break;
			case EmployeeSelection::ROOMTYPE:
				emp.TypeOfRooms();
				break;
			case EmployeeSelection::ROOMNUMBER:
				emp.RoomsNumber();
				break;
			case EmployeeSelection::ROOMPRICE:
				emp.RoomPrice();
				break;
			case EmployeeSelection::REMOVEROOM:
				emp.RemoveRoom();
				break;
			case EmployeeSelection::GOTOUSER:
				loggedInUser = true;
				break;
			default:
				Error();
			}
			if (loggedInUser)
			{
				break;
			}
		}
	}

	system("cls");

	if (loggedInUser)
	{
		User use(*data);
		std::string name = input_name("User.txt");
		std::cout << "welcome " << name << "\nplease write .Help if you want help in menu\n";
		while (loggedInUser)
		{
			std::string userInput;
			std::getline(std::cin, userInput);
			UserSelection mainselection = Userhash(userInput);
			switch (mainselection)
			{
			case UserSelection::HELP:
				printHelpUser();
				break;
			case UserSelection::ROOMSEARCH:
				use.RoomSearch();
				break;
			case UserSelection::ROOMBOOK:
				use.RoomBook();
				break;
			case UserSelection::ROOMCANCLE:
				use.cancleRoom();
				break;
			default:
				Error();
			}
		}
	}
}

bool exists(std::string filename)
{
	std::ifstream file(filename);
	return file.good();
}

std::string input_name(std::string filename)
{
	std::string name;
	std::ifstream input(filename);
	input >> name;
	input.close();
	return name;
}
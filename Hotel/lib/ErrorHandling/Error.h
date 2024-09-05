#pragma once
#include <type_traits>
#include <iostream>
bool ValidInteger(int* num)
{
	while (true)
	{
		std::cin >> *num;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cerr << "Please enter a valid integer " << std::endl;
			return false;
		}
		return true;
	}
}

bool ValidString(std::string* strings)
{
	while (true)
	{
		std::getline(std::cin ,*strings);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cerr << "Please enter a valid string " << std::endl;
			return false;
		}
		return true;
	}
}


#include "PhoneBook.hpp"

int main()
{
	PhoneBook PhoneBook;
	std::string input;

	while (1)
	{
		std::cout << std::setw(0) << "> ";
		std::getline(std::cin, input);

		if (input == "SEARCH")
			PhoneBook.display();
		if (input == "ADD")
			PhoneBook.add();
		if (input == "EXIT")
			return (0);
	}
}

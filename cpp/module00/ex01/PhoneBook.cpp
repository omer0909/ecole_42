#include "PhoneBook.hpp"

void PhoneBook::display(void)
{
	if (contacts[0].is_filled())
	{
		std::cout << "     index|first name| last name|  nickname" << std::endl;
	}
	else
	{
		std::cout << "Phone book is empty." << std::endl;
		return;
	}
	for (int i = 0; i < 8 && contacts[i].is_filled(); i++)
	{
		std::cout << std::setw(10) << i;
		contacts[i].display();
	}
	std::cout << "Contact index? ";
	std::string input;
	std::getline(std::cin, input);
	int index = -1;
	if (input.length() == 1)
		index = input[0] - '0';
	if (index >= 0 && index < 8 && contacts[index].is_filled())
		contacts[index].show_all();
	else
		std::cout << input << ": Wrong entry!" << std::endl;
}

void PhoneBook::add()
{
	for (int i = 6; i >= 0; i--)
		contacts[i + 1] = contacts[i];
	contacts[0].get_data();
}

PhoneBook::PhoneBook()
{
}

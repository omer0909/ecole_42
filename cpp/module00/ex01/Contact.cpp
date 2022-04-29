#include "Contact.hpp"

const std::string Contact::contents_infos[] = {"first name", "last name", "nickname", "phone number", "darkest secret"};

void Contact::get_data(void)
{
	std::string input;

	for (int i = 0; i < 5; i++)
	{
		while (1)
		{
			std::cout << contents_infos[i] << "? ";
			std::getline(std::cin, input);
			if (input.length())
				break;
			else
				std::cout << "Contact cannot have free space!\a" << std::endl;
		}
		contents[i] = input;
	}
}

int Contact::is_filled(void)
{
	return (contents[0].length() != 0);
}

void Contact::show_all(void)
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << contents_infos[i] << ": " << contents[i] << std::endl;
	}
}

void Contact::display(void)
{
	std::string tmp[] = {contents[0], contents[1], contents[2]};
	bool to_long;

	for (int i = 0; i < 3; i++)
	{
		
		to_long = tmp[i].length() > 10;
		if (to_long)
		{
			tmp[i] = tmp[i].substr(0, 9);
			tmp[i] += ".";
		}
		std::cout << std::setw(0) << "|";
		std::cout << std::setfill(' ') << std::setw(10) << tmp[i];
	}
	std::cout << std::setw(0) << std::endl;
}

Contact::Contact(void)
{

}

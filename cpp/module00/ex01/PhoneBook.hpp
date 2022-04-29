#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
public:
	void add();
	void display();
	PhoneBook();

private:
	Contact contacts[8];
};

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
	std::string contents[5];
	const static std::string contents_infos[];
public:
	int is_filled(void);
	void display(void);
	void show_all(void);
	void get_data(void);
	Contact(void);
};

#endif

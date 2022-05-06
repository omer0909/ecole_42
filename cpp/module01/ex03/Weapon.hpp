#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
public:
	const std::string &Weapon::getType();
	void setType(std::string type);
	Weapon();
	Weapon(std::string type);

private:
	std::string type;
};

#endif
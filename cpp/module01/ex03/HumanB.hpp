#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
	void attack();
	void setWeapon(Weapon &weapon);
	HumanB(std::string name);

private:
	Weapon *weapon;
	std::string name;
};

#endif
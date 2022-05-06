#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
	std::string getName(void);
	void setName(std::string name);
	void announce();
};

Zombie *zombieHorde(int N, std::string name);

#endif
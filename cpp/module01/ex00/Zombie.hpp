#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie(void);
	std::string getName(void);
	void announce();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
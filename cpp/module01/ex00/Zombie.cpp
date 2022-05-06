#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << getName() << ": I am going again!" << std::endl;
}

std::string Zombie::getName(void)
{
	return (name);
}

void Zombie::announce()
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
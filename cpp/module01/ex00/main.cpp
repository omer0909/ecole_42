#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("heap");
	zombie->announce();
	delete zombie;
	randomChump("stack");
	return (0);
}

#include "../inc/Bowling.hpp"
#include <iostream>

int main()
{
	Player p1;
	p1.loadData("Name1:X|7/|9-|X|8-|8/|-6|X|X|X||81");
	std::cout << std::endl;
	std::cout << p1.getName() << std::endl;


	std::cin.get();
    return 0;
}


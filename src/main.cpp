#include "../inc/Bowling.hpp"
#include <iostream>
int main()
{
	Player p1;
	p1.loadData("Edek:5/|5/|5/|5/|5/|5/|5/|5/|X|/5||X");
	//p1.loadData("Name1:X|7/|9-|X|8-|8/|-6|X|X|X||81"); //102
	//p1.loadData("Edek:5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5"); //105
	std::cout << std::endl;
	std::cout <<"player name: " << p1.getName() << std::endl;
	std::cout <<"player points: "<<p1.getPoints() <<std::endl;
	std::cout <<"game status: "<<p1.getStatus() << std::endl;
	std::cout << std::endl;

	std::cin.get();
    return 0;
}


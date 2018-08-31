#pragma once
#include "Player.hpp"
#include <vector>

class Alley {
private:
	int id_;
	std::vector<Player> players_;
public:
	void display();

};
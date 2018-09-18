#include "../inc/Alley.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

Alley::Alley(int id, int maxPlayers) {
	id_ = id;
	maxPlayers_ = maxPlayers;
}


void Alley::display() {
	std::cout << "### Lane " << id_ << ": ";
	
	std::vector<int> st;  //checks the lowest game status of players               
	for (auto& x : players_)
		st.push_back(x.getStatus());
	
	std::min(st.begin(), st.end());
		
}

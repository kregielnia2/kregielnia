#pragma once
#include "Player.hpp"
#include <vector>

class Alley {
private:
	enum GameStatus { none, no_game, in_progress, finished };
	int id_;                       //Bowling alley/lane unique ID
	unsigned int maxPlayers_;      //Maximum players allowed to using this alley
	std::vector<Player> players_;  //Players using this alley

public:
	Alley(int id, int maxPlayers = 4);
	void display();                      //shows current status of games in this alley
	bool addPlayer(std::string input);   //adds player, returns false if input is in bad format
	bool daletePlayer(std::string name, int score = -1); //deletes player via name and (optional) score;
	bool resetAlley();                                   //deletes all players

	std::string getPlayer(std::string name, int score = -1); //returns data from selected player
	std::string getData();                                   //returns data from all players
};
#pragma once
#include "Validator.hpp"

class Player {
private:
	enum GameStatus {none, no_game, in_progress, finished};
	Validator validate;
	std::string data_;      //stores game data
	std::string name_;      //stores player name
	int points_ = 0;        //stores player points
	int status_ = none;     //stores game status based on frames in data:
private:
	void setName();         //sets name based on loaded data_
	void setScore();        //sets score based on loaded data_
	void setGameStatus();   //sets GameStatus based on string format from data_ (requires name_)
public: 
	bool loadData(const std::string& data);   //loads validated data
	
	int getPoints();
	int getStatus();
	std::string getName();
	std::string getData();
};
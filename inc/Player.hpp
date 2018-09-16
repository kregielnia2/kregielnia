#pragma once
#include <string>

class Player {
private:
	enum GameStatus {none, no_game, in_progress, finished};
	std::string data_;      //stores game data
	std::string name_;      //stores player name
	int points_ = 0;        //stores player points
	int status_ = none;     //stores game status based on frames in data:
private:
	void setName();         //sets name based on loaded data_
	void setScore();        //sets score based on loaded data_
	void setGameStatus();   //sets GameStatus based on string format from data_ (requires name_)
public:
	bool validateInput(const std::string& str);   //validates data input
	bool loadData(const std::string& data);       //loads validated data
	
	int getPoints();
	int getStatus();
	std::string getName();
	std::string getData();
};
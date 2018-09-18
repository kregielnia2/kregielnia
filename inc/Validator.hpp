#pragma once
#include <string>

struct Validator {            //validates data input 
	size_t i = 0;             //loop elements
	int bonusMoves = 0;       //bonus move from spare or strikes
	int name_size = 0;        //actual Player name size
	int bonusFrame = 0;       //place where bonus frame indicator starts "||"
	size_t maxMoves = 0;      //max moves without bonuses from spare or strikes
	bool operator() (const std::string& str); //(functor)
};
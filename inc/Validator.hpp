#pragma once
#include <string>

struct Validator {            //validates data input 
	size_t i = 0;             //loop elements
	int bonusMoves = 0;       //bonus move from spare or strikes
	int name_size = 0;
	int bonusFrame = 0;       //place where bonus frame indicator starts "||"
	bool operator() (const std::string& str); //(functor)
};
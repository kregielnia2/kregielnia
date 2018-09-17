#include "../inc/Player.hpp"
#include <cctype>
#include <algorithm>
#include <iostream>

//converts "string element to int" based on ASCI
int stringToInt(const std::string &str, size_t element) {
	return str.at(element) - 48;
}

void Player::setGameStatus(){
	int separators = std::count( (data_.begin() + name_.size() + 1), data_.end(), '|');
	if (separators == 11)
		status_ = finished;
	else if (separators < 11)
		status_ = in_progress;
	else
		status_ = no_game;
}

bool Player::validateInput(const std::string& str) {
	int name_size = 0;
	{
		bool colonFlag = false;
		//calculates name size
		for (size_t i = 0; i < str.size(); i++) {
			if (str.at(i) != ':')
				name_size++;
			else {
				colonFlag = true;
				break;
		}}
		//in string there is not a colon - name separator
		if (colonFlag == false)
			return false;
		}
	//data starting past name_ is too long or overall to short
	if ((str.size() - (name_size + 1)) > 33 || str.size() < 3)
		return false;
	{
		int separators = std::count((str.begin() + name_size + 1), str.end(), '|');
		//if too many separators
		if (separators > 11)
			return false;
		//if last frame separator is not dual
		if (separators == 10)
			return false;
	}
	//searches position of bonus frame separator
	size_t bonusFrame = str.find("||");

	//there are more bonus frame separators than one
	if (str.find("||", bonusFrame + 1) != std::string::npos)
		return false;

	//counting allowed moves in format
	{
		int elementsInFrame = 0;  //are there more elements in frame than allowed
		bool xInFrame = false;    //was X in the current frame
		
		int bonusMoves = 0;       //bonus move from spare or strikes
		int maxMoves = 20;        //max moves without bonuses from spare or strikes

		size_t i = name_size + 1; //starting after name and separator char ':'	
		while (i < str.size()) {

			//if there is unrecognized character
			if (!(isdigit(str.at(i)) ||
				str.at(i) == 'X' ||
				str.at(i) == '/' ||
				str.at(i) == '-' ||
				str.at(i) == '|'))
				return false;
			else 
				elementsInFrame++;

			//if there is no X and only one element in the frame
			if (xInFrame == false && str.at(i) == '|' && str.at(i - 2) == '|')
				return false;

			//calculating bonus moves
			//and elements in frame
			switch (str.at(i)){
			case 'X':
				if (bonusMoves < 2)
					bonusMoves++;
				xInFrame = true;
				break;
			case '/':
				if (bonusMoves == 0)
					bonusMoves++;
				break;
			case '|':
				elementsInFrame = 0;
				xInFrame = false;
				break;	
			}
			//if there is another elemenet in frame with X
			if (xInFrame && elementsInFrame > 1)
				return false;
			//if there are more than 2 elements in frame without X
			if (elementsInFrame > 2)
				return false;		
					
			i++;
		}
		//if there are to much bonus moves
		if (i > bonusFrame + bonusMoves + 2)
			return false;
		else if (i != bonusFrame + bonusMoves + 2)  //THIS FIX NEEDS TO BE MOVED TO setGameStatus
			status_ = in_progress;
	}
	return true;
}

bool Player::loadData(const std::string & data){
	if (!data.empty())
		if (validateInput(data)) {   //validates if data is correct
			data_ = data;            //loading data to object
			setName();               //setting name based on loaded data
			setGameStatus();         //setting GameStatus (requires name_)
			setScore();              //setting score based on loaded data
			return true;
		}
	return false;
}

void Player::setName() {
	size_t frontLoop = 0;

	std::string temp = "";
	while (data_.at(frontLoop) != ':') {
		temp += data_.at(frontLoop);
		frontLoop++;
	}
	name_ = temp;
}


void Player::setScore() {
	int previousPoints = 0;
	for (size_t i = name_.size() + 1; i < data_.size(); i++) {
		
		if (isdigit(data_.at(i))) {
			points_ += stringToInt(data_, i);
			previousPoints = stringToInt(data_, i);
		}		
		else switch (data_[i]){
		case 'X': points_ += 10; break;
		case '/': points_ += (10 - previousPoints); break;
		case '-': break;
		default: break;
		}
}	}

std::string Player::getName(){
	return name_;
}

int Player::getStatus(){
	return status_;
}

int Player::getPoints(){
	return points_;
}

std::string Player::getData(){
	return data_;
}

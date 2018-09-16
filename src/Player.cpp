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
	{//scope
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
	if ((str.size() - name_size + 1) > 33 || str.size() < 3)
		return false;
	{//scope
		int separators = std::count((str.begin() + name_size + 1), str.end(), '|');
		//if too many separators
		if (separators > 11)
			return false;
		//if last frame separator is not dual
		if (separators == 10)
			return false;
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

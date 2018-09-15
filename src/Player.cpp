#include "../inc/Player.hpp"
#include <cctype>
#include <string>
#include <iostream>

//converts "string element to int" based on ASCI
int seti(const std::string &str, size_t element) {
	return str.at(element) - 48;
}

//TO DO
bool Player::validateInput(const std::string& str) {
	return true;
}

//TO DO
bool Player::loadData(const std::string & data){
	if (!data.empty())
		if (validateInput(data)) {   //validates if data is correct
			data_ = data;            //loading data to object
			setName();               //setting name based on loaded data
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
	name_ = temp;                   //sets loaded name as class varialbe
}



void Player::setScore() {
	
	int previousPoints = 0;
	for (size_t i = name_.size() + 1; i < data_.size(); i++) {
		
		if (isdigit(data_.at(i))) {
			points_ += seti(data_, i);
			previousPoints = seti(data_, i);
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

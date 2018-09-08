#include "../inc/Player.hpp"
#include <cctype>
#include <string>

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
        temp.push_back(data_.at(frontLoop));
		frontLoop++;
	}
    name_ = temp;                   //sets loaded name as class varialbe
}



void Player::setScore() {
	size_t backLoop = data_.size()-1;
	//adding all digits from string starting backwards ending on name position
	while (backLoop > name_.size()) {
		if (isdigit(data_.at(backLoop)))
			points_ += seti(data_, backLoop);
        else if(data_.at(backLoop)=='/') points_ += (10 - seti(data_, backLoop-1));
        else if(data_.at(backLoop)=='X') points_ += 10;
        if(data_.at(backLoop-2)=='X'||backLoop-2)=='/') points_ += seti(data_, backLoop);
        if(data_.at(backLoop-3)=='X'){
            if(data_.at(backLoop)=='/') points_ += (10 - seti(data_, backLoop-1));
            else points_ += seti(data_, backLoop);
        }

		backLoop--;
		}
}

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

#include "../inc/Validator.hpp"
#include <cctype>
#include <algorithm>

bool Validator::operator() (const std::string& str) {	
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
	bonusFrame = str.find("||");

	//there are more bonus frame separators than one
	if (str.find("||", bonusFrame + 1) != std::string::npos)
		return false;

	//counting allowed moves in format
	{
		int elementsInFrame = 0;  //are there more elements in frame than allowed
		bool xInFrame = false;    //was X in the current frame
		maxMoves = 20;            //max moves without bonuses from spare or strikes

		i = name_size + 1;        //starting after name and separator char ':'	
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
			switch (str.at(i)) {
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
			//if there is another elemenet in frame with X before bonus frame
			if (xInFrame && elementsInFrame > 1 && i < bonusFrame)
				return false;
			
			//if there is spare '\' without number or with strike 'X'
			if (str.at(i) == '/' && std::isdigit(str.at(i-1)) == 0)
				return false;

			//if there are more than 2 elements in frame without X
			if (elementsInFrame > 2)
				return false;

			//there cannot be spare in bonus move/s
			if (i > bonusFrame && str.at(i) == '/')
				return false;

			i++;
		}
		//if there is a separator "||" but there are to much bonus moves
		if (bonusFrame > 0 && str.size() > bonusFrame + bonusMoves + 2)
			return false;

	}
	return true;
}
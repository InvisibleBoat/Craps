#include "Bet.h"

Bet::Bet() {
    
	owner = 0;
	money = 0;
	location = 0;
}

Bet::Bet(int newOwner, int newMoney, int newLocation) {

	owner = newOwner;
	money = newMoney;
	location = newLocation;
	
}

int Bet::getOwner() {
	return owner;
}

int Bet::getMoney() {
	return money;
}

int Bet::getLocation() {
	return location;
}

string Bet::toString() {
    stringstream ss;
    
    ss << getOwner() << "\t" << getMoney() << "\t" << getLocation();
    
    return ss.str();
}
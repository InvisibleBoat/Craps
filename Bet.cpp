#include Bet_H

Bet::Bet(int newOwner, int newMoney, int newLocation){

	owner = newOwner;
	money = newMoney;
	location = newLocation;
	
}
int Bet::getOwner(){
	return owner;
}
int Bet::getMoney(){
	return money;
}
int Bet::getLocation(){
	return location;
}

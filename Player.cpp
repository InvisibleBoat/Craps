#include "Player.h"

Player::Player(){
    
	name = "default name";
	balance = 0;
	
}

Player::Player(string newName, int newBalance){

	name = newName;
	balance = newBalance;
	
}

string Player::getName(){
	return name;
}

int  Player::getBalance(){
	return balance;
}
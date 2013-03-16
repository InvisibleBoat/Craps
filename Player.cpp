#include "Player.h"

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
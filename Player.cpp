#include "Player.h"

Player::Player() {
    
	name = "default name";
	balance = 0;
	
}

Player::Player(string newName, int newBalance) {

	name = newName;
	balance = newBalance;
	
}

string Player::getName() {
	return name;
}

int  Player::getBalance() {
	return balance;
}

void Player::addMoney(int bet) {
	balance = balance + bet;
}

bool Player::hasFunds(int i) {
    return (i > 0 && i <= balance);
}

string Player::toString() {
    
    stringstream ss;
    
    ss << getName() << "\t" << getBalance();
    
    return ss.str();
}
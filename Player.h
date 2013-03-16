#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <sstream>

using namespace std;

class Player {
    
	private:
		string name;
		int balance;
		
	public:
        Player();
		Player(string newName, int newBalance);
		string getName();
		int getBalance();
		void addMoney(int bet);
        bool hasFunds(int i);
        string toString();
	
};

#endif
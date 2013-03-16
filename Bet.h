#ifndef BET_H
#define BET_H

#include <string>
#include <sstream>

using namespace std;

class Bet {
    
    private:
        int owner;
		int money;
		int location;
	
	public:
        Bet();
		Bet(int newOwner, int newMoney, int newLocation);
		int getOwner();
		int getMoney();
		int getLocation();
        string toString();
	
};

#endif
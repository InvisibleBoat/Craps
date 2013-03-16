#ifdef BET_H
#define BET_H

class Bet {
    
    private:
		int money;
		int location;
	
	public:
		Bet(int newOwner, int newMoney, int newLocation);
		int getOwner();
		int getMoney();
		int getLocation();
	
	
};

#endif
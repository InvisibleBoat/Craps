        
#include "Dealer.h"

Dealer::Dealer() {
    players.push_back(new Player);
    dice.first = dice.second = 1;
    running = true;
    srand((int)time(NULL));
}

void Dealer::run() {
    
    while(running) {
        handleInput();
        roll();
        evaluateBets();
    }
}

void Dealer::roll() {
    dice.first = rand() % 6 + 1;
    dice.second = rand() % 6 + 1;
	
    cout << "Roll:\t" << dice.first << "\t" << dice.second << endl;
}

void Dealer::evaluateBets() {
    
    for(int i = 0; i < bets.size(); i++) {
        // TODO: Evaluate each bet
		b = bets[i];
		
		if(on == 0){
			//Easy Win on Pass
			if(b.getLocation()==0 and (dice.frist + dice.second) == 7 or (dice.frist + dice.second) == 11 ){
				players[b.getOwner()].addMoney(b.getMoney());
				bets.remove(i);
				i--;
			}
			//Set on to 4,5,6,8,9, or 10
			else if(b.getLocation()==0 and ((dice.frist + dice.second) != 2) and ((dice.frist + dice.second) != 3) and ((dice.frist + dice.second) != 12)
				on = dice.frist + dice.second;
			//Craps out pass
			else{
				bets.remove(i);
				i--;
			}
				
		}
		else{
			
			if(b.getLocation()==0 and (dice.frist + dice.second) == 7){
			
			
			}
		}
    }
}

void Dealer::handleInput() {
    
    string s = "";
    
    while(s != "roll") {
        getline(cin, s);
        
        if(s == "quit") {
            
        }
    }
}
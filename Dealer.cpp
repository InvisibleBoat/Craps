        
#include "Dealer.h"

Dealer::Dealer() {
    players.push_back(new Player("Tyler", 1000));
    players.push_back(new Player("Robert", 1000));
    dice.first = dice.second = 1;
    running = true;
    srand((int)time(NULL));
    on = 0;
}

void Dealer::run() {
    
    while(running) {
        handleInput();
        roll();
        evaluateBets();
    }
}

void Dealer::roll() {
    
    if(running) {
        dice.first = rand() % 6 + 1;
        dice.second = rand() % 6 + 1;
    
        cout << "Roll:\t" << dice.first << "\t" << dice.second << endl;
    }
}

void Dealer::evaluateBets() {
    
    int sum = dice.first + dice.second;
    
    for(int i = 0; i < bets.size(); i++) {
        // TODO: Evaluate each bet
		Bet b = *bets[i];
		
		if(!on){
			//Easy Win on Pass
			if(b.getLocation() == 0 and (sum == 7 or sum == 11)){
				players[b.getOwner()]->addMoney(2 * b.getMoney());
				bets.erase(bets.begin() + i);
				i--;
			}
			//Craps out pass
			else if(!(b.getLocation()==0 and sum != 2 and sum!= 3 and sum != 12)){
				bets.erase(bets.begin() + i);
				i--;
            }
		}
		else{
			//Craps seven
			if(b.getLocation() == 0 and sum == 7){
				bets.erase(bets.begin() + i);
				i--;
			}
			else if(b.getLocation()==0 and sum == on){
				players[b.getOwner()]->addMoney(2 * b.getMoney());
				bets.erase(bets.begin() + i);
				i--;
			}
		}
    }
    
    if(!on and sum != 2 and sum!= 3 and sum != 12)
        on = dice.first + dice.second;
    else if(on && (sum == 7 or sum == on))
        on = 0;
}

void Dealer::handleInput() {
    
    char s[100];
    char *cmd;
    char *prm;
    
    while(strcmp(s, "roll") && running) {
        cin.getline(s, 100);
        cmd = strtok(s, " ");
        
        if(!strcmp(cmd,"quit")) {
            running = false;
        }
        else if(!strcmp(cmd,"bet")) {
            
            // read player index
            prm = strtok(NULL, " ");
            int pIdx = (strcmp(prm, "")) ? atoi(prm) : -1;
            
            // read bet value
            prm = strtok(NULL, " ");
            int value = (strcmp(prm, "")) ? atoi(prm) : -1;
            
            // read bet location
            int loc = -1;
            prm = strtok(NULL, " ");
            if(!strcmp(prm, "pass") && !on) {
                loc = 0;
            }
            else if(!strcmp(prm, "come")) {
                loc = 1;
            }
            
            // create bet if valid
            if(pIdx >= 0  && pIdx < players.size() && value > 0 && value <= players[pIdx]->getBalance() && loc >= 0) {
                bets.push_back(new Bet(pIdx, value, loc));
                players[pIdx]->addMoney(-value);
            }
            else {
                cout << "Invalid bet." << endl;
            }
        }
        else if(!strcmp(cmd,"board")) {
            for(int i = 0; i < bets.size(); i++) {
                cout << bets[i]->getOwner() << "\t" << bets[i]->getMoney()
                     << "\t" << bets[i]->getLocation() << endl;
            }
        }
        else if(!strcmp(cmd,"players")) {
            for(int i = 0; i < players.size(); i++) {
                cout << players[i]->getName() << "\t" << players[i]->getBalance() << endl;
            }
        }
        
    }
}
        
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
    
    if(running) {
        dice.first = rand() % 6 + 1;
        dice.second = rand() % 6 + 1;
    
        cout << "Roll:\t" << dice.first << "\t" << dice.second << endl;
    }
}

void Dealer::evaluateBets() {
    
    for(int i = 0; i < bets.size(); i++) {
        // TODO: Evaluate each bet
		b = bets[i];
		sum = dice.frist + dice.second;
		
		if(on == 0){
			//Easy Win on Pass
			if(b.getLocation()==0 and sum == 7 or sum == 11 ){
				players[b.getOwner()].addMoney(b.getMoney());
				bets.remove(i);
				i--;
			}
			//Set on to 4,5,6,8,9, or 10
			else if(b.getLocation()==0 and sum != 2 and sum!= 3 and sum != 12)
				on = dice.frist + dice.second;
			//Craps out pass
			else{
				bets.remove(i);
				i--;
			}
		}
		else{
			//Craps seven
			if(b.getLocation()==0 and sum == 7){
				on = 0;
				bets.clear();
			}
			else if(b.getLocation()==0 and sum == on){
				players[b.getOwner()].addMoney(b.getMoney());
				bets.remove(i);
				i--;
			}
		}
    }
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
            
            prm = strtok(NULL, " ");
            int pIdx = (strcmp(prm, "")) ? atoi(prm) : -1;
            
            prm = strtok(NULL, " ");
            int value = (strcmp(prm, "")) ? atoi(prm) : -1;
            
            int loc = -1;
            prm = strtok(NULL, " ");
            if(!strcmp(prm, "pass")) {
                loc = 1;                                            // ADJUST THIS
            }
            else if(!strcmp(prm, "come")) {
                loc = 2;                                            // ADJUST THIS
            }
            
            if(pIdx >= 0 && value > 0 && loc > 0) {
                bets.push_back(new Bet(pIdx, value, loc));
            }
        }
        else if(!strcmp(cmd,"board")) {
            for(int i = 0; i < bets.size(); i++) {
                cout << bets[i]->getOwner() << "\t" << bets[i]->getMoney()
                     << "\t" << bets[i]->getLocation() << endl;
            }
        }
    }
}
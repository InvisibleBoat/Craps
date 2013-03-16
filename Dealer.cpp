        
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
        if(bets.size()) {
            dice.first = rand() % 6 + 1;
            dice.second = rand() % 6 + 1;
        
            cout << "Roll:\t" << dice.first << "\t" << dice.second << endl;
        }
        else {
            cout << "At least one bet must be placed to roll." << endl;
        }
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
    
    while(strcmp(s, "roll") && running) {
        cin.getline(s, 100);
        cmd = strtok(s, " ");
        
        if(!strcmp(cmd,"quit")) {
            quit();
        }
        else if(!strcmp(cmd,"bet")) {
            addBet(strtok(NULL, ""));
        }
        else if(!strcmp(cmd,"board")) {
            viewBoard();
        }
        else if(!strcmp(cmd,"players")) {
            viewPlayers();
        }
        else if(!strcmp(cmd,"addPlayer")) {
            addPlayer(strtok(NULL, ""));
        }
    }
}

void Dealer::quit() {
    running = false;
}

void Dealer::addBet(char *c) {
    
    // read player index
    char *prm = strtok(c, " ");
    int pIdx = (strcmp(prm, "")) ? atoi(prm) : -1;
    
    // read bet value
    prm = strtok(NULL, " ");
    int value = (strcmp(prm, "")) ? atoi(prm) : -1;
    
    // read bet location
    int loc = LOC_INVALID;
    prm = strtok(NULL, " ");
    if(!strcmp(prm, "pass") && !on) {
        loc = LOC_PASS;
    }
    else if(!strcmp(prm, "come")) {
        loc = LOC_COME;
    }
    
    // create bet if valid
    if(!isValidPlayer(pIdx)) {
        cout << "Invalid bet: Player does not exist" << endl;
    }
    else if(!(players[pIdx]->hasFunds(value))) {
        cout << "Invalid bet: Insufficient Funds" << endl;
    }
    else if(loc == LOC_INVALID) {
        cout << "Invalid bet: Invalid board location" << endl;
    }
    else {
        bets.push_back(new Bet(pIdx, value, loc));
        players[pIdx]->addMoney(-value);
    }
}

void Dealer::viewBoard() {
    
    cout << "ON:\t" << on << endl;
    
    for(int i = 0; i < bets.size(); i++) {
        cout << bets[i]->toString() << endl;
    }
}

void Dealer::viewPlayers() {
    for(int i = 0; i < players.size(); i++) {
        cout << players[i]->toString() << endl;
    }
}

void Dealer::addPlayer(char *c) {
    // read player index
    char* prm = strtok(c, " ");
    char* name = prm;
    
    // read bet value
    prm = strtok(NULL, " ");
    int bal = (prm) ? atoi(prm) : 0;
    
    if(name && bal > 0)
        players.push_back(new Player(name, bal));
}

bool Dealer::isValidPlayer(int i) {
    return (i >= 0  && i < players.size());
}


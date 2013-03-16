        
#include "Dealer.h"

Dealer::Dealer() {
    players.push_back(new Player);
    dice.first = dice.second = 1;
    running = true;
    srand(clock());
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
    }
}

void Dealer::handleInput() {
    
    string s = "";
    
    while(s != "roll") {
        s = cin.getline();
        
        
    }
}
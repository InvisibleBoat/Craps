
#ifndef DEALER_H
#define DEALER_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <cstring>

#include "Player.h"
#include "Bet.h"

#define LOC_INVALID     -1
#define LOC_PASS        0  
#define LOC_COME        1

using namespace std;

class Dealer {
    
    private:
        vector<Player*> players;
        vector<Bet*>    bets;
        pair<int, int>  dice;
        bool            running;
		int on;
    
        // User command methods
        void quit();
        void addBet(char *c);
        void viewBoard();
        void viewPlayers();
        void addPlayer(char *c);
    
        // Private utility methods
        void roll();
        void evaluateBets();
        void handleInput();
        bool isValidPlayer(int i);
    
    
    public:
        Dealer();
        void run();
};

#endif
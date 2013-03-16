
#ifndef DEALER_H
#define DEALER_H

#include <vector>
#include <cstdlib>
#include <iostream>

#include "Player.h"
#include "Bet.h"

using namespace std;

class Dealer {
    
    private:
        vector<Player>  players;
        vector<Bet>     bets;
        pair<int, int>  dice;
        bool            running;
    
    public:
        Dealer();
        void run();
        void roll();
        void evaluateBets();
        void handleInput();
};

#endif
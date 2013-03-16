
#include "Dealer.h"

void Dealer::run() {
    
}

void Dealer::roll() {
    dice.first = rand() % 6 + 1;
    dice.second = rand() % 6 + 1;
}

void Dealer::evaluateBets() {
    
    for(int i = 0; i < bets.size(); i++) {
        // TODO: Evaluate each bet
    }
}

void Dealer::handleInput();
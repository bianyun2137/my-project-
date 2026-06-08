#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <iostream>
using namespace std;

class Player {
private:
    int cardCount;
    Card hand[10];

public:
    Player();

    void addcard(Card c);
    int getTotal();
    void showHand(string who);
};

#endif
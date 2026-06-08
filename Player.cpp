#include "Player.h"

Player::Player() {
    cardCount = 0;
}

void Player::addcard(Card c) {
    if (cardCount < 10) {
        hand[cardCount++] = c;
    }
}

int Player::getTotal() {
    int total = 0;
    int aceCount = 0;

    for (int i = 0; i < cardCount; i++) {
        total += hand[i].getpoint();

        if (hand[i].isAce()) {
            aceCount++;
        }
    }

    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }

    return total;
}

void Player::showHand(string who) {
    cout << who << "目前手牌: ";

    for (int i = 0; i < cardCount; i++) {
        cout << hand[i].getname() << " ";
    }

    cout << "總點數 = " << getTotal() << endl;
}
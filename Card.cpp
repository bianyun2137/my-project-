#include "Card.h"

Card::Card(int p, string n) {
    point = p;
    name = n;
}

int Card::getpoint() {
    return point;
}

string Card::getname() {
    return name;
}

bool Card::isAce() {
    return name == "A";
}
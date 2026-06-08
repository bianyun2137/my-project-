#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
private:
    int point;
    string name;

public:
    Card(int p = 0, string n = "");

    int getpoint();
    string getname();
    bool isAce();
};

#endif
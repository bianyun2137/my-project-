#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"

using namespace std;

Card getCard() {
    int p = rand() % 13 + 1;

    string name;
    int point;

    if (p == 1) {
        name = "A";
        point = 11;
    }
    else if (p == 11) {
        name = "J";
        point = 10;
    }
    else if (p == 12) {
        name = "Q";
        point = 10;
    }
    else if (p == 13) {
        name = "K";
        point = 10;
    }
    else {
        name = to_string(p);
        point = p;
    }

    return Card(point, name);
}

int main() {
    srand(time(0));

    Player player;
    Player computer;

    player.addcard(getCard());
    player.addcard(getCard());

    computer.addcard(getCard());
    computer.addcard(getCard());

    player.showHand("玩家");
    computer.showHand("電腦");

    string choice;

    while (true) {

        if (player.getTotal() > 21) {
            cout << "玩家爆牌，電腦勝！" << endl;
            return 0;
        }

        cout << "要牌(yes)或停牌(no)? ";
        cin >> choice;

        if (choice == "yes") {
            player.addcard(getCard());
            player.showHand("玩家");
        }
        else {
            break;
        }
    }

    while (computer.getTotal() < 17) {
        computer.addcard(getCard());
    }

    computer.showHand("電腦");

    if (computer.getTotal() > 21) {
        cout << "電腦爆牌，玩家勝！" << endl;
    }
    else if (player.getTotal() > computer.getTotal()) {
        cout << "玩家勝！" << endl;
    }
    else if (player.getTotal() < computer.getTotal()) {
        cout << "電腦勝！" << endl;
    }
    else {
        cout << "平手！" << endl;
    }

    return 0;
}
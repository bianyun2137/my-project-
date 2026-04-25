#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Card {
private:
	int point;
	string name;
public:
	Card(int p=0, string n="") : point(p), name(n) {}
	int getpoint() {
		return point;
	}
	string getname() {
		return name;
	}
	bool isAce() { return name == "A"; }
};
class Player {
private:
	int cardCount=0;
	Card hand[10];
public:
	void addcard(Card c) {
		if (cardCount < 10) {
			hand[cardCount++] = c;
		}
	}
		int getTotal() {
			int total = 0;
			int aceCount = 0;
			for (int i = 0; i < cardCount; i++) {
				total += hand[i].getpoint();
				if (hand[i].isAce()) aceCount++;
			}
			while (total > 21 && aceCount > 0) {
				total -= 10;
				aceCount--;
			}
			return total;
		}
		void showHand(string who) {
			cout << who << "目前手牌: ";
			for (int i = 0; i < cardCount; i++) {
				cout << hand[i].getname() << " ";
			}
			cout << "總點數 = " << getTotal() << endl;
		}
};
	Card getCard() {
		int p = rand() % 13 + 1;
		string name;
		int point;
		if (p == 1) {
			name = "A"; point = 11;
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
	Player player, computer;
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

#include <iostream>

using namespace std;

class Count369Game {
	int numMax;
	int num369(int num);
public:
	void setMax(int num) {
		numMax = num;
	}
	void runGame();
};

void Count369Game::runGame() {
	for (int i = 1; i <= 200; i++) {
		if (num369(i) < 0) {
			for (int j = num369(i); j < 0; j++) {
				cout << "!";
			}
			cout << ", ";
		}
		else {
			cout << i << ", ";
		}
	}
}

int Count369Game::num369(int num) {
	int temp = num;
	int count = 0;
	while (temp != 0) {
		if (temp % 10 == 3) {
			count--;
		}
		temp = temp / 10;
	}
	if (count == 0) {
		return num;
	}
	else {
		return count;
	}
}

int main() {
	Count369Game myGame;
	myGame.setMax(200);
	myGame.runGame();
}

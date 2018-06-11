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
	// 1부터 200까지 탐색
	for (int i = 1; i <= 200; i++) {
		// num369(i)가 0보다 작다는것은 3,6,9가 num에 포함되어 있다는 뜻이다.
		if (num369(i) < 0) {
			// 따라서 그 숫자만큼 !를 출력한다.
			for (int j = num369(i); j < 0; j++) {
				cout << "!";
			}
			cout << ", ";
		}
		//  num369(i)가 0보다 크다는것은 3,6,9가 num에 포함되어 있지않다 뜻이다.
		else {
			cout << i << ", ";
		}
	}
}

int Count369Game::num369(int num) {
	// num에 3,6,9가 들어있는지 판단하기 위해 temp라는 변수를 만들고 num값을 대입시킨다.
	int temp = num;
	// num에 3,6,9가 몇개들어가 있는지 확인하기위한 count변수
	int count = 0;
	// temp가 0이되면 반복문을 종료한다.
	while (temp != 0) {
		// 만약 temp를 10으로 나눈 나머지가 3이면 
		// 일의 자리가 3,6,9중 하나라는 뜻이다.
		if (temp % 10 == 3) {
			//count를 하나 줄여준다.
			//1증가가 아니라 1감소를 한 이유는 runGame()함수를 보면 알수 있다.
			count--;
		}
		//temp를 10으로 나누어 일의자리를 버린다.
		temp = temp / 10;
	}
	// 만약 반복문을 다 종료했는데 count가 0이라는 것은 해당 num에 3,6,9가 포함되어 있지 않다는 뜻이다.
	// 따라서 num그대로 리턴해준다.
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

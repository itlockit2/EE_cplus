#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Player {
	string name;
public:
	//생성자 함수
	Player(string name);
	//기본생성자 함수
	Player() {}
	string getName() const;
	void setName(const string name);
};

//Player() 함수 작성
Player::Player(string name) {
	this->name = name;
}
//getName() 함수 작성
string Player::getName() const {
	return name;
}

//setName() 함수 작성
void Player::setName(const string name) {
	this->name = name;
}

class DiceGame {
	//주사위 수
	const int DICE_NUMBER = 3;
	// Player수
	const int PLAYER_NUMBER = 2;
	// 게임수
	static int nCount;
	Player player[2];
	int iRandom[3];
public:
	//생성자 함수
	DiceGame();
	//iRandom[] 배열의 수가 모두 일치하면 true 리턴
	bool isMatch();
	//게임시작 함수
	void start();
};

//DiceGame() 함수 작성
DiceGame::DiceGame() {
	cout << "Start Game" << endl;
	// player의 이름을 저장할수 있는 변수를 선언한다.
	string player1Name;
	string player2Name;
	cout << "Type the 1 st Player Name > ";
	// cin을 통해 이름을 입력받는다.
	cin >> player1Name;
	cout << "Type the 2 st Player Name > ";
	cin >> player2Name;
	// 입력받은 이름을 통해 객체를 생성한다.
	Player p1(player1Name);
	Player p2(player2Name);
	// 멤버변수 객체배열 Player player[2] 에 생성한 객체를 대입시킨다.
	player[0] = p1;
	player[1] = p2;
}
//isMatch() 함수 작성
bool DiceGame::isMatch() {
	// iRandom의 모든값이 같으면 true를 리턴
	return (iRandom[0] == iRandom[1] && iRandom[1] == iRandom[2]);
}
//start() 함수 작성, 문제의 출력 예와 같이 실행 되는 함수
void DiceGame::start() {
	//problem1 참고
	srand((unsigned int)time(NULL));
	 while (true) {
		// 게임을 할때마다 nCount는 1증가하여야 한다.
		nCount++;
		// 난수 발생
		for (int i = 0; i < 3; i++) {
			iRandom[i] = rand() % 6 + 1;
		}
		// player1 난수 출력
		cout << player[0].getName() << "\t";
		for (int i = 0; i < 3; i++) {
			cout << iRandom[i] << "\t";
		}
		// 게임 종료 판단
		if (isMatch()) {
			cout << player[0].getName() << " Win in Game #" << nCount;
			break;
		}
		cout << endl;
		// 난수 발생
		for (int i = 0; i < 3; i++) {
			iRandom[i] = rand() % 6 + 1;
		}
		// player2 난수 출력
		cout << player[1].getName() << "\t";
		for (int i = 0; i < 3; i++) {
			cout << iRandom[i] << "\t";
		}
		// 게임 종료 판단
		if (isMatch()) {
			cout << player[1].getName() << " Win in Game #" << nCount;
			break;
		}
		cout << endl;

	}
	
}
int DiceGame::nCount = 0;

int main() {
	DiceGame game;
	game.start();
}

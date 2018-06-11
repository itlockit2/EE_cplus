#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Player {
	string name;
public:
	//������ �Լ�
	Player(string name);
	//�⺻������ �Լ�
	Player() {}
	string getName() const;
	void setName(const string name);
};

//Player() �Լ� �ۼ�
Player::Player(string name) {
	this->name = name;
}
//getName() �Լ� �ۼ�
string Player::getName() const {
	return name;
}

//setName() �Լ� �ۼ�
void Player::setName(const string name) {
	this->name = name;
}

class DiceGame {
	//�ֻ��� ��
	const int DICE_NUMBER = 3;
	// Player��
	const int PLAYER_NUMBER = 2;
	// ���Ӽ�
	static int nCount;
	Player player[2];
	int iRandom[3];
public:
	//������ �Լ�
	DiceGame();
	//iRandom[] �迭�� ���� ��� ��ġ�ϸ� true ����
	bool isMatch();
	//���ӽ��� �Լ�
	void start();
};

//DiceGame() �Լ� �ۼ�
DiceGame::DiceGame() {
	cout << "Start Game" << endl;
	string player1Name;
	string player2Name;
	cout << "Type the 1 st Player Name > ";
	cin >> player1Name;
	cout << "Type the 2 st Player Name > ";
	cin >> player2Name;
	Player p1(player1Name);
	Player p2(player2Name);
	player[0] = p1;
	player[1] = p2;
}
//isMatch() �Լ� �ۼ�
bool DiceGame::isMatch() {
	return (iRandom[0] == iRandom[1] && iRandom[1] == iRandom[2]);
}
//start() �Լ� �ۼ�, ������ ��� ���� ���� ���� �Ǵ� �Լ�
void DiceGame::start() {
	srand((unsigned int)time(NULL));
	 while (true) {
		nCount++;
		// ���� �߻�
		for (int i = 0; i < 3; i++) {
			iRandom[i] = rand() % 6 + 1;
		}
		// player1 ���� ���
		cout << player[0].getName() << "\t";
		for (int i = 0; i < 3; i++) {
			cout << iRandom[i] << "\t";
		}
		// ���� ���� �Ǵ�
		if (isMatch()) {
			cout << player[0].getName() << " Win in Game #" << nCount;
			break;
		}
		cout << endl;
		// ���� �߻�
		for (int i = 0; i < 3; i++) {
			iRandom[i] = rand() % 6 + 1;
		}
		// player2 ���� ���
		cout << player[1].getName() << "\t";
		for (int i = 0; i < 3; i++) {
			cout << iRandom[i] << "\t";
		}
		// ���� ���� �Ǵ�
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
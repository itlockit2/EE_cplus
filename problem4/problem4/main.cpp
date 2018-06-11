#include <iostream>
#include <string>

using namespace std;

class LoopAdder {
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") {
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두수를 입력하세요 >>";
	cin >> x >> y;
}
void LoopAdder::write() {
	cout << x << "에서" << y << "까지의 합 = " << sum << "입니다" << endl;
}

void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}

// ForLoopAdder 클래스 작성
class ForLoopAdder : public LoopAdder{
public:
	string name;
	int x, y, sum;
	// 초기화 배열을 통해 sum값을 0으로 초기화 시켜준다.
	ForLoopAdder(string name) : sum(0) {
		this->name = name;
	}
	// x부터 y까지의 합을 sum에 저장하고 return한다.
	int calculate() {
		for (int i = x; i <= y; i++) {
			sum += i;
		}
		return sum;
	}
	void read() {
		cout << name << ":" << endl;
		cout << "처음 수에서 두번째 수까지 더합니다. 두수를 입력하세요 >>";
		cin >> x >> y;
	}
	void write() {
		cout << x << "에서" << y << "까지의 합 = " << sum << "입니다" << endl;
	}
	void run() {
		read();
		sum = calculate();
		write();
	}
};
// WhileLoopAdder 클래스 작성
class WhileLoopAdder : public LoopAdder {
public:
	string name;
	int x, y, sum;
	WhileLoopAdder(string name) : sum(0) {
		this->name = name;
	}
	int calculate() {
		int i = x;
		while (i <= y)
		{
			sum += (i*i);
			i++;
		}
		return sum;
	}
	void read() {
		cout << name << ":" << endl;
		cout << "처음 수에서 두번째 수까지 더합니다. 두수를 입력하세요 >>";
		cin >> x >> y;
	}
	void write() {
		cout << x << "에서" << y << "까지의 합 = " << sum << "입니다" << endl;
	}
	void run() {
		read();
		sum = calculate();
		write();
	}
};
// DoWhileLoopAdder 클래스 작성
class DoWhileLoopAdder : public LoopAdder {
public:
	string name;
	int x, y, sum;
	DoWhileLoopAdder(string name) : sum(0) {
		this->name = name;
	}
	int calculate() {
		int i = x;
		do {
			if (i % 3 == 0) {
				sum += i;
			}
			i++;
		} while (i <= y);
		return sum;
	}
	void read() {
		cout << name << ":" << endl;
		cout << "처음 수에서 두번째 수까지 더합니다. 두수를 입력하세요 >>";
		cin >> x >> y;
	}
	void write() {
		cout << x << "에서" << y << "까지의 합 = " << sum << "입니다" << endl;
	}
	void run() {
		read();
		sum = calculate();
		write();
	}
};
int main() {
	ForLoopAdder forLoop("For Loop");
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do While Loop");

	forLoop.run();
	whileLoop.run();
	doWhileLoop.run();
}

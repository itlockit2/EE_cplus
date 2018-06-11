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
	cout << "ó�� ������ �ι�° ������ ���մϴ�. �μ��� �Է��ϼ��� >>";
	cin >> x >> y;
}
void LoopAdder::write() {
	cout << x << "����" << y << "������ �� = " << sum << "�Դϴ�" << endl;
}

void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}

// ForLoopAdder Ŭ���� �ۼ�
class ForLoopAdder : public LoopAdder{
public:
	string name;
	int x, y, sum;
	ForLoopAdder(string name) : sum(0) {
		this->name = name;
	}
	int calculate() {
		for (int i = x; i <= y; i++) {
			sum += i;
		}
		return sum;
	}
	void read() {
		cout << name << ":" << endl;
		cout << "ó�� ������ �ι�° ������ ���մϴ�. �μ��� �Է��ϼ��� >>";
		cin >> x >> y;
	}
	void write() {
		cout << x << "����" << y << "������ �� = " << sum << "�Դϴ�" << endl;
	}
	void run() {
		read();
		sum = calculate();
		write();
	}
};
// WhileLoopAdder Ŭ���� �ۼ�
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
		cout << "ó�� ������ �ι�° ������ ���մϴ�. �μ��� �Է��ϼ��� >>";
		cin >> x >> y;
	}
	void write() {
		cout << x << "����" << y << "������ �� = " << sum << "�Դϴ�" << endl;
	}
	void run() {
		read();
		sum = calculate();
		write();
	}
};
// DoWhileLoopAdder Ŭ���� �ۼ�
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
		cout << "ó�� ������ �ι�° ������ ���մϴ�. �μ��� �Է��ϼ��� >>";
		cin >> x >> y;
	}
	void write() {
		cout << x << "����" << y << "������ �� = " << sum << "�Դϴ�" << endl;
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

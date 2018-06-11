#include <iostream>
#include <fstream>

using namespace std;

class MyVector {
	int nSize; // ������ ũ��
	int *pnVector; // ���� ���� ������ 
protected:
	MyVector(int nSize = 10) {
		this->nSize = nSize;
		pnVector = new int[nSize];
	}
	~MyVector() {
		delete[] pnVector;
	}
	void put(int nIndex, int nValue) {
		pnVector[nIndex] = nValue;
	}
	int get(int nIndex) {
		return pnVector[nIndex];
	}
	int getSize() {
		return nSize;
	}
};

class MyStack : public MyVector {
	// top�� ������ push�� ��ġ(���� �ֱٿ� �ԷµǾ��� �ڷ��� ��ġ)
	// top�� ���� ���ÿ� ��� �ִ� �ڷ��� ������ ����
	int top;
public:
	MyStack(int nSize);
	void push(int n);
	int pop();
	int getTop();
	int getStackSize();
};

// ������ �ۼ�, top�� 0���� �ʱ�ȭ
MyStack::MyStack(int nSize) :MyVector(nSize) {
	top = 0;
}
// push()�Լ� �ۼ�, full stack ���� ó��("full stack error" ���)
void MyStack::push(int n) {
	if (top == getSize()) {
		cout << "full stack error" << endl;
		return;
	}
	put(top, n);
	top++;
}
// pop()�Լ� �ۼ�, empty stack ���� ó��("empty stack error" ���)
int MyStack::pop() {
	if (top == 0) {
		cout << "empty stack error" << endl;
		return -1;
	}
	top--;
	int result = get(top);
	return result;
}
// getTop() �Լ� �ۼ�, ������ ���� ũ�� ����
int MyStack::getTop() {
	return top;
}
// getStackSize()�Լ� �ۼ�, ������ ��ü ũ�� ����
int MyStack::getStackSize() {
	return getSize();
}
int main() {
	MyStack stack(10);
	cout << "type the 5 integer number: ";
	int iNumber;
	for (int i = 0; i<5; i++) {
		cin >> iNumber;
		stack.push(iNumber);
	}
	cout << "stack total size: " << stack.getStackSize() << endl;
	cout << "stack current size: " << stack.getTop() << endl;

	ofstream fout;
	fout.open("stack.txt");
	// ������ �ܼ� ��� �� �ؽ�Ʈ ���� ����
	cout << "stack pop :";
	fout << "stack pop :";
	for (int i = 0; i<5; i++) {
		int number = stack.pop();
		fout << number << " ";
		cout << number << " ";
	}
	cout << endl;
	cout << "stack current size: " << stack.getTop() << endl;
}
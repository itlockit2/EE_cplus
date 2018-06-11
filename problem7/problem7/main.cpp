#include <iostream>
#include <fstream>

using namespace std;

class MyVector {
	int nSize; // 벡터의 크기
	int *pnVector; // 정수 벡터 포인터 
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
	// top은 다음에 push할 위치(가장 최근에 입력되었던 자료의 위치)
	// top은 현재 스택에 들어 있는 자료의 개수와 동일
	int top;
public:
	MyStack(int nSize);
	void push(int n);
	int pop();
	int getTop();
	int getStackSize();
};

// 생성자 작성, top을 0으로 초기화
MyStack::MyStack(int nSize) :MyVector(nSize) {
	top = 0;
}
// push()함수 작성, full stack 예외 처리("full stack error" 출력)
void MyStack::push(int n) {
	if (top == getSize()) {
		cout << "full stack error" << endl;
		return;
	}
	put(top, n);
	top++;
}
// pop()함수 작성, empty stack 예외 처리("empty stack error" 출력)
int MyStack::pop() {
	if (top == 0) {
		cout << "empty stack error" << endl;
		return -1;
	}
	top--;
	int result = get(top);
	return result;
}
// getTop() 함수 작성, 스택의 현재 크기 리턴
int MyStack::getTop() {
	return top;
}
// getStackSize()함수 작성, 스택의 전체 크기 리턴
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
	// 나머지 콘솔 출력 및 텍스트 파일 저장
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
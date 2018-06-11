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
	// pnVector행렬 index에 nValue값을 대입한다.
	void put(int nIndex, int nValue) {
		pnVector[nIndex] = nValue;
	}
	// pnVector행렬에서 index에 있는 값을 가져온다.
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
// MyVector생성자를 호출해서 pnVector를 nSize로 초기화시켜준다.
MyStack::MyStack(int nSize) :MyVector(nSize) {
	top = 0;
}
// push()함수 작성, full stack 예외 처리("full stack error" 출력)
void MyStack::push(int n) {
	// top이 nSize와 같으면 배열이 찾다는 뜻이므로 에러 출력
	if (top == getSize()) {
		cout << "full stack error" << endl;
		return;
	}
	// 그게 아니라면 배열에 값을 넣어주고 top을 1 증가
	put(top, n);
	top++;
}
// pop()함수 작성, empty stack 예외 처리("empty stack error" 출력)
int MyStack::pop() {
	// top이 0이라면 배열이 비어있다는 뜻이므로 에러 출력
	if (top == 0) {
		cout << "empty stack error" << endl;
		return -1;
	}
	// 아니라면 top을 1 감소하고 값을뺀다.
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
	// 파일에 값을 입력
	fout << "stack pop :";
	for (int i = 0; i<5; i++) {
		int number = stack.pop();
		// 파일에 값을 입력
		fout << number << " ";
		// 콘솔에 값을 
		cout << number << " ";
	}
	cout << endl;
	cout << "stack current size: " << stack.getTop() << endl;
}

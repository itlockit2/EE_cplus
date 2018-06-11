#include <iostream>

using namespace std;

class Matrix {
public:
	int nRows; // 행렬의 행의 개수 
	int nCols; // 행렬의 열의 개수
	int **ppnData; // 2차원 행렬 포인터 
	
	Matrix(int rows, int cols); //생성자
	Matrix(const Matrix& obj); //복사 생성자
	~Matrix(); // 소멸자
	Matrix operator+(const Matrix& obj);
	Matrix operator*(const Matrix& obj);
	Matrix operator=(const Matrix& obj);

	friend istream& operator>>(istream &in, Matrix& obj);
	friend ostream& operator<<(ostream &out, Matrix& obj);
};

// 생성자 함수 작성, 2차원 행렬의 동적 메모리 할당하여 구현하고, 2차원 배열 초기화
Matrix::Matrix(int rows, int cols) {
	this->nRows = rows;
	this->nCols = cols;
	// 나머지는 문제대로 구현
	// 2차원 행렬 동적 메모리 할당 
	ppnData = new int*[nRows];
	for (int i = 0; i<nRows; i++) {
		ppnData[i] = new int[nCols];
	}
	// 2차원 행렬을 0으로 초기화 시켜준다.
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			ppnData[i][j] = 0;
		}
	}
}
// 복사 생성자 함수 작성, 2차원 행렬의 동적 메모리 할당하여 구현
Matrix::Matrix(const Matrix& obj) {
	this->nRows = obj.nRows;
	this->nCols = obj.nCols;
	// 기본생성자 부분 참고
	ppnData = new int*[nRows];
	for (int i = 0; i<nRows; i++) {
		ppnData[i] = new int[nCols];
	}
	// 매개변수로 받은 행렬에 있는 값들을 this로 옮겨준다.
	for (int i = 0; i < obj.nRows; i++) {
		for (int j = 0; j < obj.nCols; j++) {
			this->ppnData[i][j] = obj.ppnData[i][j];
		}
	}
}
// 소멸자 함수, 동적 메모리 반납
Matrix::~Matrix() {
	for (int i = 0; i<nRows; i++)
		delete[] ppnData[i];
	delete[] ppnData;
}

// + 연산자 함수 작성  
 Matrix Matrix::operator+(const Matrix& obj) {
	// 결과값을 담을 객체를 하나 선언한다.
	Matrix result(obj.nRows,obj.nCols);
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			// 결과값을 담을 객체에 더한값을 넣어준다.
			result.ppnData[i][j] = this->ppnData[i][j] + obj.ppnData[i][j];
		}
	}
	 // 결과 객체를 리턴
	return result;
}

// * 연산자 함수 작성 
 Matrix Matrix::operator*(const Matrix& obj) {
	 Matrix result(this->nRows, obj.nCols);
	 // 3 * 2 행렬과 2 * 3 행렬을 곱셈연산 한다면 
	 // 3 * 3 행렬이 생성된다. 따라서 row는 앞에있는 행렬의 row값 cols는 뒤에있는 행렬의 cols값이다.
	 for (int row = 0; row < this->nRows; row++) {
		 for (int col = 0; col < obj.nCols; col++) { 
			 // inner 연산은 앞에있는 행렬의 cols 값이나 뒤에있는 행렬의 row값이다.
			 // 하지만 곱셈연산을 하기위해서는 두 값이 같아야 하므로
			 // 어떠한 값을 사용해도 상관이없다.
			 for (int inner = 0; inner < obj.nRows; inner++) {
				 result.ppnData[row][col] = result.ppnData[row][col] + this->ppnData[row][inner] * obj.ppnData[inner][col];
			 }
		 }
	 }
	 // 해당 알고리즘이 이해가 안된다면 손으로 직접 행렬을 만들어서 해보는것을 추천
	 return result;
 }
// = 연산자 함수 작성 
Matrix Matrix::operator=(const Matrix& obj) {
	for (int i = 0; i < obj.nRows; i++) {
		for (int j = 0; j < obj.nCols; j++) {
			this->ppnData[i][j] = obj.ppnData[i][j];
		}
	}
	return *this;
 }
// >> 연산자 함수 작성, 행과 열의 개수 
// 및 행렬의 원소 값을 사용자로부터 입력 받음
istream& operator>>(istream &in, Matrix& obj) {
	cout << "type the row and col size: ";
	in >> obj.nRows;
	in >> obj.nCols;
	cout << "type the elements: ";
	for (int i = 0; i < obj.nRows; i++) {
		for (int j = 0; j < obj.nCols; j++) {
			int number;
			in >> number;
			obj.ppnData[i][j] = number;
		}
	}
	return in;
}

// << 연산자 함수 작성
ostream& operator<<(ostream &out, Matrix& obj) {
	for (int i = 0; i < obj.nRows; i++) {
		for (int j = 0; j < obj.nCols; j++) {
			out << obj.ppnData[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

int main() {
	Matrix a(2, 2);
	Matrix b(2, 2);
	Matrix c(2, 2);
	cin >> a; cin >> b;
	while (true) {
		cout << endl;
		cout << "1.Addition" << endl;
		cout << "2.Multiplication" << endl;
		cout << "3.Program exit" << endl;

		int nMenu;
		// 사용자로부터 메뉴 번호 입력
		cin >> nMenu;
		// switch문 작성 
		switch (nMenu)
		{
			cout << nMenu;
		case 1:
			c = a + b;
			cout << "a + b =" << endl;
			cout << c;
			break;
		case 2:
			c = (a * b);
			cout << "a * b =" << endl;
			cout << c;
			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
		// 1번 선택하면 c=a+b, 2번 선택하면 c=a*b
		// 3번 선택하면 프로그램 종료, 잘못된 메뉴를 선택하면 에러 메세지 출력
	}
	}

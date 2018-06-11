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
	ppnData = new int*[nRows];
	for (int i = 0; i<nRows; i++) {
		ppnData[i] = new int[nCols];
	}
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
	Matrix result(obj.nRows,obj.nCols);
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			result.ppnData[i][j] = this->ppnData[i][j] + obj.ppnData[i][j];
		}
	}
	return result;
}

// * 연산자 함수 작성 
 Matrix Matrix::operator*(const Matrix& obj) {
	 Matrix result(this->nRows, obj.nCols);
	 for (int row = 0; row < this->nRows; row++) {
		 for (int col = 0; col < obj.nCols; col++) {  
			 for (int inner = 0; inner < obj.nRows; inner++) {
				 result.ppnData[row][col] = result.ppnData[row][col] + this->ppnData[row][inner] * obj.ppnData[inner][col];
			 }
		 }
	 }
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

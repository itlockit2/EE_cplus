#include <iostream>

using namespace std;

class Matrix {
public:
	int nRows; // ����� ���� ���� 
	int nCols; // ����� ���� ����
	int **ppnData; // 2���� ��� ������ 
	
	Matrix(int rows, int cols); //������
	Matrix(const Matrix& obj); //���� ������
	~Matrix(); // �Ҹ���
	Matrix operator+(const Matrix& obj);
	Matrix operator*(const Matrix& obj);
	Matrix operator=(const Matrix& obj);

	friend istream& operator>>(istream &in, Matrix& obj);
	friend ostream& operator<<(ostream &out, Matrix& obj);
};

// ������ �Լ� �ۼ�, 2���� ����� ���� �޸� �Ҵ��Ͽ� �����ϰ�, 2���� �迭 �ʱ�ȭ
Matrix::Matrix(int rows, int cols) {
	this->nRows = rows;
	this->nCols = cols;
	// �������� ������� ����
	// 2���� ��� ���� �޸� �Ҵ� 
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
// ���� ������ �Լ� �ۼ�, 2���� ����� ���� �޸� �Ҵ��Ͽ� ����
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
// �Ҹ��� �Լ�, ���� �޸� �ݳ�
Matrix::~Matrix() {
	for (int i = 0; i<nRows; i++)
		delete[] ppnData[i];
	delete[] ppnData;
}

// + ������ �Լ� �ۼ�  
 Matrix Matrix::operator+(const Matrix& obj) {
	Matrix result(obj.nRows,obj.nCols);
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			result.ppnData[i][j] = this->ppnData[i][j] + obj.ppnData[i][j];
		}
	}
	return result;
}

// * ������ �Լ� �ۼ� 
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
// = ������ �Լ� �ۼ� 
Matrix Matrix::operator=(const Matrix& obj) {
	for (int i = 0; i < obj.nRows; i++) {
		for (int j = 0; j < obj.nCols; j++) {
			this->ppnData[i][j] = obj.ppnData[i][j];
		}
	}
	return *this;
 }
// >> ������ �Լ� �ۼ�, ��� ���� ���� 
// �� ����� ���� ���� ����ڷκ��� �Է� ����
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

// << ������ �Լ� �ۼ�
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
		// ����ڷκ��� �޴� ��ȣ �Է�
		cin >> nMenu;
		// switch�� �ۼ� 
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
		// 1�� �����ϸ� c=a+b, 2�� �����ϸ� c=a*b
		// 3�� �����ϸ� ���α׷� ����, �߸��� �޴��� �����ϸ� ���� �޼��� ���
	}
	}

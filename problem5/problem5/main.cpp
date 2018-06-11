#include <iostream>

using namespace std;

int findGCD(int x, int y);
int findLCM(int x, int y);
void swap(int &x, int &y);

class Rational {
	int numerator, denominator;
public:
	Rational(int n = 1, int d = 1);
	int getNumerator();
	int getDenominator();
	// �� �������� ��, ��, ����� ���ϴ� �Լ��� �����Լ��� ����
	friend Rational operator*(Rational &r1, Rational &r2);
	friend Rational operator+(Rational &r1, Rational &r2);
	friend ostream& operator<<(ostream&os, Rational &r);
};
// Rational Ŭ���� ������ �Լ� Rational(int n =1, int d = 1)�ۼ�
Rational::Rational(int n, int d) {
	numerator = n;
	denominator = d;
}
// Rational Ŭ���� ��� �Լ� getNumerator() �ۼ�
int Rational::getNumerator() {
	return numerator;
}
// Rational Ŭ���� ��� �Լ� getDenominator() �ۼ�
int Rational::getDenominator() {
	return denominator;
}
// operator*() �Լ� �ۼ�
Rational operator*(Rational &r1, Rational &r2) {
	int resultNumerator = r1.getNumerator() * r2.getNumerator();
	int resultDenominator = r1.getDenominator() * r2.getDenominator();
	int resultGCD = findGCD(resultNumerator, resultDenominator);
	resultNumerator = resultNumerator / resultGCD;
	resultDenominator = resultDenominator / resultGCD;
	return Rational(resultNumerator, resultDenominator);
}
// operator+() �Լ� �ۼ�
Rational operator+(Rational &r1, Rational &r2) {
	int resultNumerator = r1.getNumerator() * r2.getDenominator() + r1.getDenominator() * r2.getNumerator();
	int resultDenominator = r1.getDenominator() * r2.getDenominator();
	int resultGCD = findGCD(resultNumerator, resultDenominator);
	resultNumerator = resultNumerator / resultGCD;
	resultDenominator = resultDenominator / resultGCD;
	return Rational(resultNumerator, resultDenominator);
}
// operator<<() �Լ� �ۼ�
ostream& operator<<(ostream&os, Rational &r) {
	os << r.getNumerator() << " / " << r.getDenominator();
	return os;
}
// �� ���� �ִ������� ���ϴ� �����Լ� findGCD()�Լ� �ۼ� 
// x�� y���� ���� �� �̸� �μ��� swap�ϴ� swap()�Լ� ȣ��
int findGCD(int x, int y) {
	while (y != 0) {
		if (x < y) {
			swap(x, y);
		}
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}
// �� ���� �ּҰ������ ���ϴ� �����Լ� findLCM()�Լ� �ۼ�
int findLCM(int x, int y) {
	return (x * y) / findGCD(x, y);
}
// �� ���� swap�ϴ� �����Լ� swap()�Լ� �ۼ�
void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int main() {
	int n1, d1; // ù ��° �������� ���ڿ� �и� �� ����
	int n2, d2; // �� ��° �������� ���ڿ� �и� �� ����
				
	// �ΰ��� �������� ����ڷκ��� �Է� �޴� �ڵ� �ۼ�
	cout << "ù ��° �������� ���ڿ� �и��� �Է��ϼ���>> ";
	cin >> n1;
	cin >> d1;
	cout << "�� ��° �������� ���ڿ� �и��� �Է��ϼ���>> ";
	cin >> n2;
	cin >> d2;
	// �� ������ �հ� ���� ����� ���м��� ����ϴ� �ڵ� �ۼ�
	Rational r1(n1, d1);
	Rational r2(n2, d2);
	Rational r3 = r1 + r2;
	Rational r4 = r1 * r2;
	cout << "r1 = " << r1.getNumerator() << " / " << r1.getDenominator() << endl;
	cout << "r2 = " << r2.getNumerator() << " / " << r2.getDenominator() << endl;
	cout << "r1 + r2 = " << r3 << endl;
	cout << "r1 * r2 = " << r4 << endl;
}

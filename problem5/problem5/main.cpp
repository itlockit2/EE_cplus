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
	// 두 유리수의 곱, 합, 출력을 구하는 함수를 전역함수로 구현
	friend Rational operator*(Rational &r1, Rational &r2);
	friend Rational operator+(Rational &r1, Rational &r2);
	friend ostream& operator<<(ostream&os, Rational &r);
};
// Rational 클래스 생성자 함수 Rational(int n =1, int d = 1)작성
Rational::Rational(int n, int d) {
	numerator = n;
	denominator = d;
}
// Rational 클래스 멤버 함수 getNumerator() 작성
int Rational::getNumerator() {
	return numerator;
}
// Rational 클래스 멤버 함수 getDenominator() 작성
int Rational::getDenominator() {
	return denominator;
}
// operator*() 함수 작성
Rational operator*(Rational &r1, Rational &r2) {
	int resultNumerator = r1.getNumerator() * r2.getNumerator();
	int resultDenominator = r1.getDenominator() * r2.getDenominator();
	int resultGCD = findGCD(resultNumerator, resultDenominator);
	resultNumerator = resultNumerator / resultGCD;
	resultDenominator = resultDenominator / resultGCD;
	return Rational(resultNumerator, resultDenominator);
}
// operator+() 함수 작성
Rational operator+(Rational &r1, Rational &r2) {
	int resultNumerator = r1.getNumerator() * r2.getDenominator() + r1.getDenominator() * r2.getNumerator();
	int resultDenominator = r1.getDenominator() * r2.getDenominator();
	int resultGCD = findGCD(resultNumerator, resultDenominator);
	resultNumerator = resultNumerator / resultGCD;
	resultDenominator = resultDenominator / resultGCD;
	return Rational(resultNumerator, resultDenominator);
}
// operator<<() 함수 작성
ostream& operator<<(ostream&os, Rational &r) {
	os << r.getNumerator() << " / " << r.getDenominator();
	return os;
}
// 두 수의 최대공약수를 구하는 전역함수 findGCD()함수 작성 
// x가 y보다 작은 수 이면 두수를 swap하는 swap()함수 호출
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
// 두 수의 최소공배수를 구하는 전역함수 findLCM()함수 작성
int findLCM(int x, int y) {
	return (x * y) / findGCD(x, y);
}
// 두 수를 swap하는 전역함수 swap()함수 작성
void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int main() {
	int n1, d1; // 첫 번째 유리수의 분자와 분모 값 저장
	int n2, d2; // 두 번째 유리수의 분자와 분모 값 저장
				
	// 두개의 유리수를 사용자로부터 입력 받는 코드 작성
	cout << "첫 번째 유리수의 분자와 분모값을 입력하세요>> ";
	cin >> n1;
	cin >> d1;
	cout << "두 번째 유리수의 분자와 분모값을 입력하세요>> ";
	cin >> n2;
	cin >> d2;
	// 두 유리수 합과 곱의 결과를 기약분수로 출력하는 코드 작성
	Rational r1(n1, d1);
	Rational r2(n2, d2);
	Rational r3 = r1 + r2;
	Rational r4 = r1 * r2;
	cout << "r1 = " << r1.getNumerator() << " / " << r1.getDenominator() << endl;
	cout << "r2 = " << r2.getNumerator() << " / " << r2.getDenominator() << endl;
	cout << "r1 + r2 = " << r3 << endl;
	cout << "r1 * r2 = " << r4 << endl;
}

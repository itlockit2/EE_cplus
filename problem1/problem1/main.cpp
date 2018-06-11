#include <iostream>
#include <ctime>

using namespace std;

//������ ��ǥ���� ����
const int pointNum = 10;
//2���� x,y��ǥ
const int pointDim = 2;

//�Ǽ����� ���� ��ǥ 10���� �����ϰ� ���� 10�� 2���� ����
void getRandomData(double randomData[][pointDim]) {
	srand((unsigned int)time(NULL));
	for(int i = 0 ; i < pointNum ; i++){
		for (int j = 0; j < pointDim; j++) {
			randomData[i][j] = (double)rand()/RAND_MAX * (10);
		}
	}
}
//�����ϰ� ������ ��ǥ 10���� ���
void printRandomData(double randomData[][pointDim]) {
	cout << "Randomly generated Points" << endl;
	for(int i = 0 ; i < pointNum; i++){
	for (int j = 0; j < pointDim; j++) {
		cout << randomData[i][j] << " ";
	}
	cout << endl;
	}
}
//�� ��ǥ (x1,y1)�� (x2,y2)������ �Ÿ��� ���
double calculateDistance(double x1, double y1, double x2, double y2) {
	return (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
}

int main() {
	double randomData[pointNum][pointDim] = { 0.0 };
	int minIndex = 0;
	double minDistance = DBL_MAX;

	getRandomData(randomData);
	printRandomData(randomData);

	cout << "Enter the calue of the point(double) x , y " << endl;
	double pointX, pointY;
	//����ڷκ��� ��ǥ�� �Է�
	cin >> pointX;
	cin >> pointY;
	//�Է¹��� ��ǥ�� �Ÿ��� ���� ����� ��ǥ�� �ε���, ��ǥ��, �Ÿ��� ���
		for (int j = 0; j < pointNum; j++) {
			double distance = calculateDistance(randomData[j][0], randomData[j][1], pointX, pointY);
			if (distance < minDistance) {
				minIndex = j;
				minDistance = distance;
			}
		}
	//Display result(�ε���, ��ǥ��, �Ÿ��� ���)
		cout << "The Nearest Index is " << minIndex << endl;
		cout << "The Nearest point is " << randomData[minIndex][0] << "," << randomData[minIndex][1] << endl;
		cout << "Distance is " << minDistance << endl;
}
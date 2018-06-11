#include <iostream>
#include <ctime>

using namespace std;

//생성할 좌표점의 개수
const int pointNum = 10;
//2차원 x,y좌표
const int pointDim = 2;

//실수값을 갖는 좌표 10개를 랜덤하게 생성 10행 2열에 저장
void getRandomData(double randomData[][pointDim]) {
	srand((unsigned int)time(NULL));
	for(int i = 0 ; i < pointNum ; i++){
		for (int j = 0; j < pointDim; j++) {
			randomData[i][j] = (double)rand()/RAND_MAX * (10);
		}
	}
}
//랜덤하게 생성된 좌표 10개를 출력
void printRandomData(double randomData[][pointDim]) {
	cout << "Randomly generated Points" << endl;
	for(int i = 0 ; i < pointNum; i++){
	for (int j = 0; j < pointDim; j++) {
		cout << randomData[i][j] << " ";
	}
	cout << endl;
	}
}
//두 좌표 (x1,y1)과 (x2,y2)사이의 거리를 계산
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
	//사용자로부터 좌표를 입력
	cin >> pointX;
	cin >> pointY;
	//입력받은 좌표와 거리가 가장 가까운 좌표의 인덱스, 좌표값, 거리를 계산
		for (int j = 0; j < pointNum; j++) {
			double distance = calculateDistance(randomData[j][0], randomData[j][1], pointX, pointY);
			if (distance < minDistance) {
				minIndex = j;
				minDistance = distance;
			}
		}
	//Display result(인덱스, 좌표값, 거리를 출력)
		cout << "The Nearest Index is " << minIndex << endl;
		cout << "The Nearest point is " << randomData[minIndex][0] << "," << randomData[minIndex][1] << endl;
		cout << "Distance is " << minDistance << endl;
}
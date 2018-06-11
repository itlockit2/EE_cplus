#include <iostream>
#include <ctime>

using namespace std;

//생성할 좌표점의 개수
const int pointNum = 10;
//2차원 x,y좌표
const int pointDim = 2;

//실수값을 갖는 좌표 10개를 랜덤하게 생성 10행 2열에 저장
void getRandomData(double randomData[][pointDim]) {
	//srand 설정을 해줘야 값이 난수로 설정된다.
	srand((unsigned int)time(NULL));
	for(int i = 0 ; i < pointNum ; i++){
		for (int j = 0; j < pointDim; j++) {
			// rand()의 출력값은 1~32767 까지의 값을 갖는다.
			// 따라서 rand의 값을 rand의 최대값 즉 32767로 나눈다면
			// rand는 0.0000305185 부터 1 까지의 값이 나오게된다.
			// 그값에 10을 곱한다면  0.0003051850 부터 10까지의 값이 나오게된다.
			randomData[i][j] = (double)rand()/RAND_MAX * (10);
		}
	}
}
//랜덤하게 생성된 좌표 10개를 출력
void printRandomData(double randomData[][pointDim]) {
	cout << "Randomly generated Points" << endl;
	// 0 , 1, 2 ... 9
	for(int i = 0 ; i < pointNum; i++){
		// 0 , 1
		for (int j = 0; j < pointDim; j++) {
			cout << randomData[i][j] << " ";
		}
	cout << endl;
	}
}
//두 좌표 (x1,y1)과 (x2,y2)사이의 거리를 계산
double calculateDistance(double x1, double y1, double x2, double y2) {
	// sqrt를 이용하여 해당값의 루트를 씌운다.
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int main() {
	double randomData[pointNum][pointDim] = { 0.0 };
	int minIndex = 0;
	// 최소거리값은 double이 가질수 있는 최대값으로 초기화 시켜줘야한다.
	// or randomData[0][0], randomData[0][1]의 거리로 초기화 시켜줘도 무관하다.
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
			// randomData와 사용자의 X,Y좌표와의 거리를 구한다.
			double distance = calculateDistance(randomData[j][0], randomData[j][1], pointX, pointY);
			//만약 구한 거리가 최소거리보다 작다면
			if (distance < minDistance) {
				// minIndex에 해당 인덱스를 저장하고
				minIndex = j;
				// minDistance에 구한 거리를 넣어준다.
				minDistance = distance;
			}
		}
	//Display result(인덱스, 좌표값, 거리를 출력)
		cout << "The Nearest Index is " << minIndex << endl;
		cout << "The Nearest point is " << randomData[minIndex][0] << "," << randomData[minIndex][1] << endl;
		cout << "Distance is " << minDistance << endl;
}

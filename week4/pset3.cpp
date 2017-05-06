#include <iostream>
using namespace std;

int LookForSeat (int StartSattion,int EndStation, int SeatNum, int TrainMap[][20]);
bool LookForFragSeat (int StartSattion,int EndStation, int SeatNum, int TrainMap[][20]);
void WrightFragSeat (int StartSattion, int EndStation, int CarrerNum, int SeatNum, int TrainMap[][20]);

int main() {
	int TrainMap[50][20] = {0};
	int SeatNum = 0;
	int StationNum = 0;
	int StartSattion = 0;
	int EndStation = 0;
	int CarrerNum = 0;
	cin >> SeatNum >> StationNum;
	while (cin >> StartSattion >> EndStation) {
		CarrerNum += 1;
		int seat = LookForSeat(StartSattion, EndStation, SeatNum, TrainMap);
		if (seat != -1) {
			for (int i = StartSattion; i < EndStation; ++i)/*檢查若為題目情況一則直接寫入 TrainMap */
			{
				TrainMap[seat][i] = CarrerNum;
			}
		}
		else {
			
			if (LookForFragSeat(StartSattion, EndStation, SeatNum, TrainMap) == true) {
				WrightFragSeat(StartSattion, EndStation, CarrerNum, SeatNum, TrainMap);
			}
		} 
	}
	for (int i = 0; i < SeatNum; ++i) {
		cout << TrainMap[i][0];
		for (int j = 1; j < StationNum; ++j) {
			cout << " " << TrainMap[i][j];
		}
		cout << "\n";
	}
	return 0;
}

int LookForSeat (int StartSattion, int EndStation, int SeatNum, int TrainMap[][20]) {/*查找空位*/
	int seat = -1;
	for(int i = 0; i < SeatNum; i ++) {
		for(int j = StartSattion; j < EndStation; j ++) {
			if (TrainMap[i][j] != 0) {
				break;
			}
			else if (j >= EndStation - 1) {
				return i;
			}
		}
	}
	return -1;
}

bool LookForFragSeat (int StartSattion, int EndStation, int SeatNum, int TrainMap[][20]) {/*查找碎片化空位*/
	for (int i = StartSattion; i <  EndStation; i++) {
		for (int j = 0; j < SeatNum; j++) {
			if (TrainMap[j][i] == 0) {
				break;
			}
			if (j == SeatNum -1) {
				return false;
			}
		}
	}
	return true;
}

void WrightFragSeat (int StartSattion, int EndStation, int CarrerNum,int SeatNum, int TrainMap[][20]) {/*寫入碎片化空位*/
	for (int i = StartSattion; i <  EndStation; ++i) {
		for (int j = 0; j < SeatNum; ++j) {
			if (TrainMap[j][i] == 0) {
				TrainMap[j][i] = CarrerNum;
				break;
			}
		}
	}
} 
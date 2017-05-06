#include <iostream>
using namespace std;

void setTransactions(int** trans, int* itemCnt, int m) {
	for (int i = 0; i < m; ++i)
	{
		cin >> itemCnt[i];
		trans[i] = new int[itemCnt[i]];
		for (int j = 0; j < itemCnt[i]; ++j)
		{
			cin >> trans[i][j];
		}
	}
}

bool Judge(int** trans, int* itemCnt, int m, int n) {
	for (int j = 0; j < itemCnt[m]; ++j)
	{
		if (trans[m][j] == (n + 1))
		{
			return 1;
		}
	}
	return 0;
}


int main() {

	int objectNum = 0;
	int validCount = 0;
	int iterNum = 0;
	int located = 0 ;
	int transNum = 0;
	float supportThr;

	const int n = 20;
	const int m = 500;

	while (cin >> objectNum >> transNum >> supportThr) {
		bool test[n];
		bool transValid[m];


		// trans & itemCnt init
		int** trans = new int*[transNum];
		int* itemCnt = new int[transNum];

		setTransactions(trans, itemCnt, transNum);


		cin >> iterNum;

		// take testing data
		for (int j = 0; j < iterNum; j++) {
			cin >> located;
			test[located - 1] = true;
		}


		// compute support set with test data
		for (int i = 0; i < transNum; i++) {
			transValid[i] = false;
			bool sign = true;
			for (int j = 0; j < objectNum; j++) {
				if (test[j] == 1 && Judge(trans, itemCnt, i, j) == 0)
					sign = false;
			}
			if (sign == true) {
				transValid[i] = true;
				validCount++;
			}
		}
		cout << "*validCount " << validCount << "\n";

		// calculate confidence with threshold of suppport

		int maxIndex = -1;
		int maxCount = -1;
		for (int i = 0; i < objectNum; i++) {
			if (test[i] == 1)
				continue;
			int count = 0;
			for (int j = 0; j < transNum; j++) {
				if (transValid[j] == 1 && Judge(trans, itemCnt, j, i) == 1)
					count++;
			}
			cout << "*" << count << "*\n";
			if ( count > supportThr * transNum && count > maxCount)
			{
				maxCount = count;
				maxIndex = i;
			}
		}
		cout << "*count " << maxCount << "\n";
		if (maxCount != -1) {
			cout << (maxIndex + 1) << " " << maxCount << " " << validCount ;
		}


	}
	return 0;
}

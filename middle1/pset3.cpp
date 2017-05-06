
#include <iostream>
#include <cmath>

int Score[3] = {0};

void ThreeWay(int Array[][20], int x, int y);
void Judge (int Array[][20], int x1, int y1,int type);

using namespace std;
int main()
{
	int CheckerBoard[20][20] = {0};
	CheckerBoard[2][2] = 3;
	CheckerBoard[6][2] = 3;
	CheckerBoard[4][4] = 3;
	CheckerBoard[2][6] = 3;
	CheckerBoard[6][6] = 3;

	int Num;
	int tempx;
	int tempy;
	cin >> Num;
	for (int i = 0; i < Num; ++i)
	{
		cin >> tempx >> tempy;
		CheckerBoard[tempx - 1][tempy - 1] = 1;
	}
	for (int i = 0; i < Num; ++i)
	{
		cin >> tempx >> tempy;
		CheckerBoard[tempx - 1][tempy - 1] = 2;
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << CheckerBoard[i][j] << " ";
		}
		cout << "\n";
	}


	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (CheckerBoard[i][j] != 0)
			{
				cout << "i:" << i + 1<<" "<< "j:" << j + 1 << endl;
				ThreeWay (CheckerBoard, i, j);
			}
		}
	}
	cout << Score[1] <<" "<< Score[2];
	return 0;
}

void ThreeWay(int Array[][20], int x, int y) {

	if (Array[x][y] == Array[x + 4][y] || Array[x + 4][y] == 3)
	{
		cout << " * \n";
		Judge (Array, x, y, 1);
		
	}
	if (Array[x][y] == Array[x][y + 4] || Array[x][y+ 4] == 3)
	{
		cout << " ** \n";
		Judge (Array, x, y, 2);
		
	}
	if (Array[x][y] == Array[x + 4][y + 4] || Array[x + 4][y + 4] == 3)
	{
		cout << " *** \n";
		Judge (Array, x, y, 3);
		
	}
} //notice deal with type 3 連線

void Judge (int Array[][20], int x1, int y1,int type) {
	if (type == 1)
	{
		bool Flag = true;	
		for (int i = 1; i < 5; ++i)
		{
			if (Array[x1 + i][y1] == Array[x1 + i - 1][y1] || Array[x1 + i - 1][y1] == 3 || Array[x1 + i][y1] == 3)
			;
			else {
				Flag = false;
				break;
			}
		}
		if (Flag == true)
		{
			if (Array[x1][y1] != 3)
			{
				Score[Array[x1][y1]]++;
				cout << "Score:" <<Score[Array[x1][y1]] << endl;
			}
			else{
				Score[Array[x1 + 1][y1]]++;
				cout << "Score:" <<Score[Array[x1 + 1][y1]] << endl;
			}
			
		}
	}
	else if (type == 2)
	{
		bool Flag = true;	
		for (int i = 1; i < 5; ++i)
		{
			if (Array[x1][y1 + i] == Array[x1][y1 + i - 1] || Array[x1][y1 + i - 1] == 3 || Array[x1][y1 + i] == 3)
			;
			else {
				Flag = false;
				break;
			}
		}
		if (Flag == true)
		{
			if (Array[x1][y1] != 3)
			{
				Score[Array[x1][y1]]++;
				cout << "Score:" <<Score[Array[x1][y1]] << endl;
			}
			else{
				Score[Array[x1][y1 + 1]]++;
				cout << "Score:" <<Score[Array[x1][y1 + 1]] << endl;
			}
				
		}
	}
	else if (type == 3)
	{
		bool Flag = true;	
		for (int i = 1; i < 5; ++i)
		{
			if (Array[x1 + i][y1 + i] == Array[x1 + i - 1][y1 + i - 1] || Array[x1 + i - 1][y1 + i - 1] == 3 || Array[x1 + i][y1 + i] == 3)
			;
			else {
				Flag = false;
				break;
			}
		}
		if (Flag == true)
		{
			if (Array[x1][y1] != 3)
			{
				Score[Array[x1][y1]]++;
				cout << "Score:" <<Score[Array[x1][y1]] << endl;
			}
			else{
				Score[Array[x1 + 1][y1 + 1]]++;
				cout << "Score:" <<Score[Array[x1 + 1][y1 + 1]] << endl;
			}
		}
	}
}

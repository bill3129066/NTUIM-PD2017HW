#include <iostream>
#include <cmath>
using namespace std;

int Add (int Array[][30], int Len, int Num);
int sum (int Array[][30], int Inix, int Iniy, int Len);

int main()
{
	int Len;
	int Array[30][30] = {0};
	cin >> Len;
	for (int i = 0; i < Len; ++i)
	{
		for (int j = 0; j < Len; ++j)
		{
			cin >> Array[i][j];
		}
	}
	int count = 0;
	for (int i = 1; i <= Len; ++i)
	{
		count = count + Add (Array, Len, i);
	}
		cout << count << " ";
		cout << sum (Array, 0, 0, Len);





	return 0;
}

int Add (int Array[][30], int Len, int Num) {
	int count = 0;
	for (int i = 0; i <= Len - Num; ++i)
	{
		for (int j = 0; j <= Len - Num; ++j)
		{
			//cout << sum (Array, i, j, Num) <<" ";
			/*if (Len == Num)
			{
				return sum (Array, i, j, Num);
			}*/
			if (sum (Array, i, j, Num) == 0)
			{
				count++;
			}
		}
	}
	return count;
}

int sum (int Array[][30], int Inix, int Iniy, int Len) {
	int sum = 0;
	for (int i = Inix; i < Inix + Len; ++i)
	{
		for (int j = Iniy; j < Iniy + Len; ++j)
		{
			sum = sum + Array[i][j];
		}
	}
	return sum;
}

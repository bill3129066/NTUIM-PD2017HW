#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int  Num = 0;
	cin >> Num;
	int Array[1000000][2] = {0};
	const int Len = Num;
	int temp = 0;
	for (int i = 0; i < Len; ++i)
	{
		cin >> temp;
		Array[temp][0] = 1;
	}
	for (int i = 2; i <= 1000; ++i)
	{
		if (Array[i][0] == 1)
		{
			if (Array[i * i][0] == 1)
			{
				Array[i * i][1] = 1;
			}
		}
	}
	bool flag = false; 
	for (int i = 2; i <= 100000; ++i)
	{

		if (Array[i][1] == 1 && flag == false)
		{
			printf("%i", i);
			flag = true;
		}
		else if (Array[i][1] == 1 && flag == true)
		{
			printf(" %i", i);
		}

	}
	return 0;
}
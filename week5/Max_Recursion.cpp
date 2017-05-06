#include <iostream>
using namespace std;

int Compare(int Array[], int len);
int main()
{
	int len = 0;
	int Array[20];
	cin >> len;
	for (int i = 0; i < len; ++i)
	{
		cin >> Array[i];
	}
	cout << Compare(Array, len);
	return 0;
}
int Compare(int Array[], int len)
{
	if (len == 1)
		return Array[0];
	else if (Compare (Array, len -1) > Array[len-1])
		return Compare (Array, len -1);
	else
		return Array[len - 1];
}
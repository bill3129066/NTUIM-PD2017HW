#include <iostream>
using namespace std;

int combiRec(int n, int m, int** com)
{
	if (n < m) //若 m > n 則代表出錯，按照上題題意要輸出 -1
		return -1;
	else if (n == m) //我們知道 C n 取 m 會等於 1，所以 return 1
		return 1;
	else if (m == 1) //我們知道 C n 取 1 會等於 n，所以 return n
		return n;
	else
	{
		if (com[n - 1][m - 1] == -1) //檢查我們的動態陣列中是否有存以前算過的紀錄，若沒有則遞迴計算並記錄進動態陣列
		{
			int res = combiRec(n - 1, m, com) + combiRec(n - 1, m - 1, com);
			com[n - 1][m - 1] = res;
			return res;
		}
		else //做有紀錄，則直接輸出動態陣列中的紀錄，不重複計算
			return com[n - 1][m - 1];
	}
}

int main() {
int n = 0, m = 0; cin >> n >> m;

// declare an n by m dynamic array
// and initialize all elements in it to -1
int** com = new int*[n];
for (int i = 0; i < n; ++i)
{
	com[i] = new int[m];
	for (int j = 0; j < m && j <= i; ++j)
	{
		com[i][j] = -1;
	}
}

cout << combiRec(n, m, com) << "\n";
for (int i = 0; i < n; ++i)
{
	for (int j = 0; j < m && j <= i; ++j)
	{
		cout << com[i][j] << " ";
	}
	cout << "\n";
}
return 0; }
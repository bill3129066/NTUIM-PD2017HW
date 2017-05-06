#include <iostream>
using namespace std;

int combiRec(int n, int m, int** com) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m && j <= i; ++j)
		{
			if (i == j) 
				com[i][j] = 1;
			else if (j == 0) 
				com[i][j] = i + 1;
			else
				com[i][j] = com[i - 1][j] + com[i - 1][j - 1];
		}
	}
	return com[n - 1][m - 1];
}

int main() {
	int n = 0, m = 0;
	cin >> n >> m;
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
	return 0;
}
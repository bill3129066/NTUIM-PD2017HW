#include <iostream>
#include <cstring>
#include <iomanip>
#include <string.h>
using namespace std;
/* 把輸入的字母變成 lowercase */
void strFormatting(char* p)
{
	long long int n = strlen(p);

	for (long long int i = 0; i < n; ++i)
	{
		p[i] = tolower(p[i]);
	}
}
/* 把輸入的數字變成 long long int */
double numFormatting(char* p)
{
	long long int n = strlen(p);
	double ans = 1.0;
	double temp = 0.0;
	bool negative = false;
	bool firstNum = true;
	if (p[0] == '-' || p[0] == '(')
	{
		negative = true;
	}
	for (long long int i = 0; i < n; ++i)
	{
		if (p[i] == '1' || p[i] == '2' || p[i] == '3' || p[i] == '4' || p[i] == '5' || p[i] == '6' || p[i] == '7' || p[i] == '8' || p[i] == '9')
		{
			if (firstNum == true)
			{
				temp = p[i] - '0';
				ans = temp;
				firstNum = false;
			}
			else
			{
				temp = p[i] - '0';
				ans = ans * 10 + temp;
			}
		}
		else if (p[i] == '0')
		{
			ans = ans * 10;
		}
		else if (p[i] == '.')
		{
			if (i + 2 < n && p[i + 2] != ')')
			{
				temp = p[i + 1] - '0';
				ans = ans + (temp / 10);
				temp = p[i + 2] - '0';
				ans = ans + (temp / 100);
			}
			else
			{
				temp = p[i + 1] - '0';
				ans = ans + (temp / 10);

			}
			break;
		}
	}
	if (negative == true)
	{
		ans = 0 - ans;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	long long int typeNum = 0;
	long long int transNum = 0;
	char type[10][20];
	char transRecord[1000][20];
	double transAmount[1000] = {0};
	/* 輸入資料 */
	cin >> typeNum >> transNum;
	for (long long int i = 0; i < typeNum; ++i)
	{
		cin >> type[i];
	}
	char tempAmount[20];
	for (long long int i = 0; i < transNum; ++i)
	{
		cin >> transRecord[i] >> tempAmount;
		strFormatting(transRecord[i]);
		transAmount[i] = numFormatting(tempAmount);
	}

	/*
	double max = transAmount[0];
	double min = transAmount[0];
	double ans = 0;
	for (long long int i = 0; i < transNum; ++i)
	{
		ans = ans + transAmount[i];
		if (transAmount[i] > max)
		{
			max = transAmount[i];
		}
		if (transAmount[i] < min)
		{
			min = transAmount[i];
		}
	}
	cout << fixed  <<  setprecision(2) << max << " " << fixed  <<  setprecision(2) << min << " " << fixed  <<  setprecision(2) << ans; */

	double* a = new double[typeNum];
	for (int i = 0; i < typeNum; ++i)
	{
		a[i] = 0;
	}
	for (int i = 0; i < transNum; ++i)
	{
		for (int j = 0; j < typeNum; ++j)
		{
			if (strcmp (transRecord[i], type[j]) == 0)
			{
				a[j] += transAmount[i];
			}
		}
	}
	cout << fixed  <<  setprecision(2) << a[0];
	for (int i = 1; i < typeNum; ++i)
	{
		cout << " " << fixed  <<  setprecision(2) << a[i];
	}
	return 0;
}
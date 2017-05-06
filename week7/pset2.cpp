#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

void strFormatting(char* p)
{
	int n = strlen(p);
	for (int i = 1; i < n; ++i)
	{
		if (p[i - 1] == " ")
		{
			toupper(p[i]);
		}
		else
			tolower(p[i]);
	}
}

int main ()
{
	char str1[] = "apple banana";
	strFormatting(str1);
	cout << str1;
	return 0;
}
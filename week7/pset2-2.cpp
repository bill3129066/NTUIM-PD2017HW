#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

void strFormatting(char* p)
{
	int n = strlen(p);
	if (p[0] != ' ')
	{
		p[0] = toupper(p[0]);
	}
	for (int i = 1; i < n; ++i)
	{
		if (p[i - 1] == ' ')
		{
			p[i] = toupper(p[i]);
		}
		else
			p[i] = tolower(p[i]);
	}
}

int main ()
{
	char str1[] = "apple banana";
	strFormatting(str1);
	cout << str1;
	return 0;
}
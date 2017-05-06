#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

int main() {
	char a[100] = "this is a book";
	char* p = strstr(a, "is");
	char* b = &a[0];
		cout << p - b;
	while (p != nullptr)
	{
		strcpy(p, "IS");
		p = strstr(p, "is");
	}
	
	return 0;
}
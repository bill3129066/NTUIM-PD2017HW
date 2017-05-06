#include <iostream> 
#include <stdio.h>
using namespace std;

int MiddleSquare(int n);

int main()
{
	int mun;
	int times;
	int a = scanf("%i %i", &mun, &times);
	/*cin >> mun >> times;*/
	for(int i = 0; i < times - 1; i++){
		mun = MiddleSquare(mun);
		printf("%04i ", mun);
	}
	mun = MiddleSquare(mun);
		printf("%04i", mun);
}
int MiddleSquare(int n){
	n = n % 1000;
	n = n / 10;
	n = n * n;
	return n;
}

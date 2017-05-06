#include <iostream> 
using namespace std;

int main()
{
	int NonNegativeNum = 0;
	cout << "Please enter Non-negative Munber: ";
	cin >> NonNegativeNum;//輸入非負數
	while(NonNegativeNum < 0)//檢查是否為負數
	{
		cout << "Entered wrong number\nPlease enter Non-negative Munber: ";
		cin >> NonNegativeNum;
	}
	int Judge = NonNegativeNum % 2;//判斷機偶數
	if(Judge = 1)
		cout << "1";
	if(Judge = 0)
		cout << "2";
return 0; 
}



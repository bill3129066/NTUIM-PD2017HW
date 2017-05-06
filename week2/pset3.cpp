#include <iostream> 
using namespace std;

int power(int h, int Num);

int main() {
	int Num = 0;//輸入數字
	int time = 0;
	
	//計算輸出了幾個 Prime Number
	cin >> Num;
	for (int i = 1; i <= Num; i++) {
		int Judge = 1;
		if (Num % i == 0) {//判斷是分數
				if (i < 2)
					Judge = 0;
				for (int j = 2; j < i; j++) {//判斷是否為質數
					if(i % j == 0){
						Judge = 0;
					}
				}
				if (Judge == 1) {
					
					if (time > 0)
					{
						cout <<" * ";
					}
					cout << i;
					int poder = power(i, Num);
					if(poder > 1)
						cout<<" ^ "<<poder;
					time++;
				}
			
		}
					
	}
return 0;
}
int power(int h,int Num){
	int i = 1;
	int k = h;
	h *= k;
	while(Num % h == 0){
		h *= k;
		i ++;
	}
return i;
}
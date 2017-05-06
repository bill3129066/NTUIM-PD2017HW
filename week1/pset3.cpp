#include <iostream> 
using namespace std;

int main(){
        int num = 0;
        cin >> num;
        num = num % 1000;
        num = num / 10;
        num = num * num;//把輸入數字中間兩數平方

        int NumCopy = num;
        int digit = 10;
        int count = 0;
        while(NumCopy > 0){
                NumCopy/=10;
                count++;
        }//記錄有幾位數
        
        count = 4 - count;
        while(count > 0){
                count--;
                cout << "0";
        }//幫不足四位數補上零

        cout << num;

        return 0;
 }
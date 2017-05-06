#include <iostream>
#include <cstring>
using namespace std;

void reverse(char p[]);
void print(char* p);

int main() {
  char s[100] = "12345";
  reverse(&s[1]); // 把 array s 的第二個 address 傳入 reverse，所以 reverse 只會收到 2345 的字串
  print(s); // 印出 s[0] 也就是 1 以及被反轉的 2345 也就是 5432，綜合起來就是 15432
  return 0;
}
void  reverse(char p[]) {
  int n = strlen(p); // 取得存在 array 陣列裡面的字傳的長度
  char* temp = new char[n];
  for (int i = 0; i < n; i++)
    temp[i] = p[n - i - 1]; // 把傳入的 2345 順序反過來存入 temp
  for (int i = 0; i < n; i++)
    p[i] = temp[i]; 
  delete [] temp; // 手動清除緩存
}
void print(char* p) {
  cout << p << "\n";
}


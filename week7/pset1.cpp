#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

int main()
{
  char name[4][10] = {"John", "Mikasa", "Eren", "Armin"};
  cout << name << "\n"; // an address
  cout << name[1] << "\n";
  cin >> name[2];
  cout << name[2][0] << "\n";
  char* p = name[0];
  cout << p << "\n";
  p = name[1];
  cout << p + 1 << "\n";
  return 0;
}
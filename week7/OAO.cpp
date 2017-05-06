#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
	int num = 0;
	while (cin >> num) {
		long double n = 0.3086;
		double m = 0.444;
		long  double total = 0;
		long  double temp = 1;
		total = total + m;
		//cout << total << " " << n << " " << m;
		for (int i = 1; i < num; ++i)
		{
			temp = 1;
			temp = temp * m;
			for (int j = 0; j < i - 1; ++j)
			{
				temp = temp * n;
			}
			total = total + temp;
			//cout << temp << endl;
			cout << "Answer: " << setprecision(16) << total - 0.444 << "\n";
		}
	}
	return 0;
}
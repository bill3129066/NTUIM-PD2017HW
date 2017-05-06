#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

double sort(int array[], int arrayLen) //sorting & calculate median
{
	int temp = 0;
	int* tmepArray = new int[arrayLen];
	for (int i = 0; i < arrayLen; ++i)
	{
		tmepArray[i] = array[i];
	}
	for (int i = 0; i < arrayLen; ++i)
	{
		for (int j = i + 1; j < arrayLen; ++j)
		{
			int minIndex = i;
			if (tmepArray[j] < tmepArray[minIndex])
			{
				minIndex = j;
			}
			temp = tmepArray[i];
			tmepArray[i] = tmepArray[minIndex];
			tmepArray[minIndex] = temp;
		}
	}
	double medain = 0;
	(arrayLen % 2) == 0 ? medain = static_cast<double>(tmepArray[arrayLen / 2] + tmepArray[(arrayLen / 2) - 1]) / 2 : medain = tmepArray[(arrayLen / 2)];
	return medain;
}

int main(int argc, char const *argv[])
{
	/*int num = 0;
	int len = 0;
	int times = 0; // cin how many times

	cin >> num >> len;
	char* str = new char[num * 20];
	num % len != 0 ? times = (num / len) + 1 : times = num / len;
	char* temp = new char[len * 20];
	for (int i = 0; i < times; ++i)
	{
		cin >> temp;
		strcat(str, temp);
		strcat(str, ",");
	}

	char tempNum[20]; // splitting & trans into int
	int wordCnt = 0;
	char* start = strtok(str, ",");
	int* numArray = new int[num];
	while (start != nullptr)
	{
		strcpy(tempNum, start);
		numArray[wordCnt] = atoi(tempNum);
		wordCnt++;
		start = strtok(nullptr, ",");
	}*/

	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	int num = n;
	int* numArray = new int[num];
	numArray[0] = (a + b * d) % c;
	for (int i = 1; i < num; ++i)
	{
		numArray[i] = (a + b * numArray[i - 1]) % c;
	}









	double medain = sort(numArray, num); //calculate medain


	int zeroCnt = 0;
	int negZeroCnt = 0;
	int run = 1;
    bool flag =true; // determine 0 run
    for (int i = 0; i < num; ++i) // run test
    {
        if (numArray[i] == medain) numArray[i] = 0;
        else if (numArray[i] > medain) {
            numArray[i] = 1;
            zeroCnt++;
        }
        else {
            numArray[i] = -1;
            negZeroCnt++;
        }
        if (i != 0)
        {
        	flag = false;
            if (numArray[i] == 1)
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (numArray[j] != 0)
                    {
                        if (numArray[j] == -1)
                        {
                            run++;
                        }
                        break;
                    }
                }
            }
            else if (numArray[i] == -1)
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (numArray[j] != 0)
                    {
                        if (numArray[j] == 1)
                        {
                            run++;
                        }
                        break;
                    }
 
                }
            }
        }
 
    }
    if(flag == true) run = 0;

	cout << zeroCnt << " " << negZeroCnt << " " << run;
	delete [] numArray;

	return 0;
}
#include <iostream>
using namespace std;

bool JudgeDistance(int i, int j);
int Benefit(int Target);

int TownNum = 0;
int StationNum = 0;
int Distance = 0;
int TownMap[500][4] = { 0 };
int MaxCoverTown[50] = { 0 };

int main()
{
    int Answer = 0;
    cin >> TownNum >> StationNum >> Distance;
    for (int i = 1; i <= TownNum; ++i) {
        cin >> TownMap[i][0] >> TownMap[i][1] >> TownMap[i][2];
    }
    for (int i = 1; i <= StationNum; ++i) {

        int MaxCover = 0;
        int MaxTown = 9999;
        for (int j = 1; j <= TownNum; ++j) {
            if (MaxCover < Benefit(j)) {
                MaxTown = j;
                MaxCover = Benefit(j);
                MaxCoverTown[j] = 1;
            }
        }
        int test = 0;
        for (int q = 1; q <= TownNum; ++q) {
            if (TownMap[q][3] == 0) {
                test = 1;
            }
        }
        if (test == 0) {
            for (int q = 1; q <= TownNum; ++q) {
                if (MaxCoverTown[q] == 0) {
                    MaxTown = q;
                    MaxCoverTown[q] = 1;
                }
            }
        }

        Answer += MaxCover;
        for (int i = 1; i <= TownNum; ++i) {
            if (JudgeDistance(MaxTown, i) == true)
                TownMap[i][3] = 1;
        }
        cout << MaxTown << " ";
    }
    cout << Answer;
    return 0;
}
bool JudgeDistance(int i, int j)
{
    int X2 = TownMap[i][0] - TownMap[j][0];
    X2 *= X2;
    int Y2 = TownMap[i][1] - TownMap[j][1];
    Y2 *= Y2;
    if (Distance * Distance >= X2 + Y2)
        return true;
    else
        return false;
}
int Benefit(int Target)
{
    int CoverNum = 0;
    for (int i = 1; i <= TownNum; ++i) {
        if (TownMap[i][3] == 0) {
            if (JudgeDistance(Target, i) == true) {
                CoverNum += TownMap[i][2];
            }
        }
    }
    return CoverNum;
}
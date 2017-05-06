#include <iostream>
using namespace std;

int PresentTimes (int Array[][30],int ArrayLen, int Compare[], int CompareLen);

int main()
{
	int Categories = 0;
	int Num = 0;
	double Threshold = 0;
	while (cin >> Categories >> Num >> Threshold) {

		int Array[600][30] = {0};
		const int Len = Num;

		int PurchaseNum = 0;
		int temp = 0;

		int Purchase[30] = {0};

		int WholeDeal = 0;
		int PartDeal = 0;
		int MaxPartDeal = 0;
		int Ans = -1;

		for (int i = 0; i < Len; ++i)/*製作商品資料地圖*/
		 {
		 	cin >> PurchaseNum;
		 	for (int j = 0; j < PurchaseNum; ++j)
		 	{
		 		cin >> temp;
		 		Array[i][temp - 1] = 1;
		 	}
		 }
		 cin >> PurchaseNum;/*傳入購買的物品*/
  		for (int j = 0; j < PurchaseNum; ++j)
		 	{
		 		cin >> Purchase[j];
		 	}
		 WholeDeal = PresentTimes (Array, Len, Purchase, PurchaseNum);/*計算總購買次數*/
		 for (int i = 0; i < Categories; ++i)
		 {
		 	bool flag = true;
		 	for (int j = 0; j < PurchaseNum; ++j)/*避免推薦同樣商品*/
	 		{
	 			if (i == Purchase[j] - 1)
	 			{
	 				flag = false;
	 				break;
	 			}
	 		}	
			if (Threshold && flag == true)
		 	{
		 		Purchase[PurchaseNum] = i + 1;
		 		PartDeal = PresentTimes (Array, Len, Purchase, PurchaseNum + 1);/*計算 confidence */
		 		if (PartDeal > MaxPartDeal && PartDeal > Threshold * Len)
		 		{
		 			MaxPartDeal = PartDeal;
		 			Ans = i + 1;
		 		}
		 	}		
		 	
		 }
		 if (MaxPartDeal > 0)
		 {
		 	cout << Ans << " " << MaxPartDeal << " " << WholeDeal;
		 }
		 
	}
}

int PresentTimes (int Array[][30],int ArrayLen, int Compare[], int CompareLen) 
{
	int count = 0;
	for (int i = 0; i < ArrayLen; ++i)
	{
		bool Flag = true;
		for (int j = 0; j < CompareLen; ++j)
		{
			if (Array[i][Compare[j] -1] == 0)
			{
				Flag = false;
				break;
			}
		}
		if (Flag == true)
		{
			count++;
		}
	}
	return count;
}
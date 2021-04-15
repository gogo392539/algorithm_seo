// Practice_01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

void fn_Remainder1();	//10430번
void fn_Remainder2();	//4375번

void fn_Aliquot();		//1037 : 약수

using namespace std;

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);

	//fn_Remainder1();
	//fn_Remainder2();
	fn_Aliquot();

}


//10430 : 나머지
void fn_Remainder1() 
{
	int nA = 0;
	int nB = 0;
	int nC = 0;
	int nResult1 = 0;
	int nResult2 = 0;
	int nResult3 = 0;
	int nResult4 = 0;

	cout << "10430번" << "\n";
	cin >> nA >> nB >> nC;

	nResult1 = (nA + nB) % nC;
	nResult2 = ((nA % nC) + (nB % nC)) % nC;
	nResult3 = (nA * nB) % nC;
	nResult4 = ((nA % nC) * (nB % nC)) % nC;


	cout << nResult1 << "\n";
	cout << nResult2 << "\n";
	cout << nResult3 << "\n";
	cout << nResult4 << "\n";
}

//4375 : 나머지
void fn_Remainder2() 
{
	int nN = 0;
	int nData = 0;
	int nIdx = 0;

	cout << "4375번" << "\n";

	while (cin >> nN) {
		nIdx = 0;
		for (int i = 1; ; i++) {
			nData = nData * 10 + 1;
			nData %= nN;

			if (nData == 0) {
				cout << i << "\n";
				break;
			}

		}
	}
}

//1037 : 약수
void fn_Aliquot() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nCount = 0;
	int nTmp = 0;
	int nMax = 0;
	int nMin = 0;
	vector<int> vData;

	cout << "1037 번\n";

	cin >> nCount;

	for (int i = 0; i < nCount; i++) {
		nTmp = 0;
		cin >> nTmp;
		vData.push_back(nTmp);
	}

	sort(vData.begin(), vData.end());

	cout << vData.front() * vData.back() << "\n";
}
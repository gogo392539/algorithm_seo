// one_dimensional_ordering_2577.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//백준 2577번 문제
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nData1 = 0;
	int nData2 = 0;
	int nData3 = 0;
	int nMulData = 0;
	string strMulData;

	strMulData.clear();

	cin >> nData1;
	cin >> nData2;
	cin >> nData3;

	nMulData = nData1 * nData2 * nData3;

	strMulData = to_string(nMulData);

	for (int k = 0; k < 10; k++) {
		int nCount = 0;
		for (int i = 0; i < strMulData.size(); i++) {
			int nTmpData = strMulData.at(i) - '0';
			if (nTmpData == k) {
				nCount++;
			}
		}
		cout << nCount << "\n";
	}


	return 0;
}

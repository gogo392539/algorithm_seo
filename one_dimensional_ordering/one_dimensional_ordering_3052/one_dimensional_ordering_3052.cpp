// one_dimensional_ordering_3052.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int nCount = 0;
	int narData[10] = { 0, };
	int narData2[10] = { 0, };
	int narData3[42] = { 0, };

	for (int i = 0; i < 10; i++) {
		cin >> narData[i];
	}

	for (int i = 0; i < 10; i++) {
		narData3[(narData[i] % 42)] = 1;
	}

	for (int i = 0; i < 42; i++) {
		if (narData3[i] == 1) {
			nCount++;
		}
	}

	cout << nCount << "\n";

	return 0;
}

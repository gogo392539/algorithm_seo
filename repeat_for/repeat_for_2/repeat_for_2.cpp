// repeat_for_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

//백준 10951번 문제
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (!cin.eof()) {
		int nNum1 = 0;
		int nNum2 = 0;

		cin >> nNum1 >> nNum2;

		if (nNum1 == 0 && nNum2 == 0) {
			break;
		}

		cout << nNum1 + nNum2 << "\n";

	}

	
	return 0;
}


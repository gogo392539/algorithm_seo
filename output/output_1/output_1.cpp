// output_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;


//백준 1008번
int main()
{
	double dNum1 = 0;
	double dNum2 = 0;
	double dResult = 0;

	cin >> dNum1 >> dNum2;

	if (dNum1 <= 0) {
		return -1;
	}

	if (dNum2 >= 10) {
		return -1;
	}

	dResult = double(dNum1 / dNum2);

	cout.unsetf(ios::fixed);
	cout.precision(33);
	cout << dResult << endl;

	return 0;
}
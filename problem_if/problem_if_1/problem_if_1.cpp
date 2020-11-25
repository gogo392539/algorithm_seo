// problem_if_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

//백준 2884번 문제
int main()
{
	int nHour = 0;
	int nMin = 0;
	int nHour1 = 0;
	int nMin1 = 0;
	int nTime = 0;
	int nTime1 = 0;

	cin >> nHour >> nMin;

	nTime = nHour * 60 + nMin;

	nTime -= 45;

	if (nTime < 0) {
		nTime1 = 24 * 60 + nTime;
		nTime = nTime1;
	}
	
	nHour1 = nTime / 60;
	nMin1 = nTime % 60;

	cout << nHour1 << " " << nMin1 << endl;

	return 0;
}



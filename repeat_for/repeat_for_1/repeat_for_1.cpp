// repeat_for_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

//백준 15552번 문제
int main()
{
	/*
	C 표준 stream과 C++ 표준 stream의 동기화를 끊어 속도를 향상시킨다.
	다음과 같이 설정하면 C 표준 입출력을 사용하면 안된다. ex) scanf, printf, ...등
	*/
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nCount = 0;

	cin >> nCount;

	for (int i = 0; i < nCount; i++) {
		int nNum1 = 0;
		int nNum2 = 0;

		cin >> nNum1 >> nNum2;

		cout << nNum1 + nNum2 << "\n";
	}

	return 0;
}

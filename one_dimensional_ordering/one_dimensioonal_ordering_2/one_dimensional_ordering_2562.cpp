// one_dimensioonal_ordering_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

//백준 2562번 문제
int main()
{
	int narData[9] = { 0, };
	vector<int> vData;
	vData.reserve(9);
	

	for (int i = 0; i < 9; i++) {
		cin >> narData[i];
		vData.push_back(narData[i]);
	}

	sort(vData.begin(), vData.end());

	cout << vData.back() << endl;

	for (int i = 0; i < 9; i++) {
		if (vData.back() == narData[i]) {
			cout << i + 1 << endl;
			break;
		}
	}

	return 0;
}


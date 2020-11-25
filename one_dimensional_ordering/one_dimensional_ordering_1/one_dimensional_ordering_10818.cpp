// one_dimensional_ordering_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//백준 10818번 문제
int main()
{
	int nNum = 0;
	int nInputCount = 0;
	vector<int> vData;
	vector<int>::iterator vIterator;

	cin >> nInputCount;

	vData.reserve(nInputCount);

	for (int i = 0; i < nInputCount; i++) {
		cin >> nNum;

		vData.push_back(nNum);
	}

	sort(vData.begin(), vData.end());

	cout << vData.front() << " " << vData.back() << endl;



	return 0;
}

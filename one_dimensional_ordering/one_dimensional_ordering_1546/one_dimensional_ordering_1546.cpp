// one_dimensional_ordering_1546.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int nCount = 0;
	double dMaxScore = 0;
	double dAverage = 0;
	vector<double> vScore;

	cin >> nCount;

	vScore.reserve(nCount);

	for (int i = 0; i < nCount; i++) {
		double dScore = 0;
		cin >> dScore;
		vScore.push_back(dScore);
	}

	dMaxScore = *max_element(vScore.begin(), vScore.end());

	for (int i = 0; i < nCount; i++) {
		double dTmpData = 0.0;
		dTmpData = (double)(vScore[i] / dMaxScore * 100.0);

		dAverage += dTmpData;
	}

	cout << dAverage / (double)nCount << "\n";

	return 0;
}
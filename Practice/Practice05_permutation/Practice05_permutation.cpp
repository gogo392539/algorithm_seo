// Practice05_permutation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//6603 : 로또
int fn_lotto();

//10971 : 외판원 순회 2
int fn_rounds_city();
int fn_rounds_city_calc(vector<int>& vPermutation, vector<vector<int>>& vW);

//10819 : 차이를 최대로
int fn_max_minus();
int fn_max_minus_calc(vector<int>& vPermutation);

//10974 : 모든순열
int fn_all_permutation();

//10973 : 이전순열
int fn_prev();
int fn_prev_permutation(vector<int>& vPermutation, int nLen);
int fn_prev_permutation2(vector<int>& vPermutation, int nLen);

//10972 : 다음순열
int fn_next();
int fn_next_permutation(vector<int>& vPermutation, int nLen);
int fn_next_permutation2(vector<int>& vPermutation, int nLen);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//fn_next();
	//fn_prev();
	//fn_all_permutation();
	//fn_max_minus();
	//fn_rounds_city();
	fn_lotto();

	return 0;
}

int fn_lotto()
{
	int nK = 0;

	while (true) {
		cin >> nK;

		if (nK == 0) {
			break;
		}

		vector<int> vPermutation(nK);
		vector<int> vPermutation2(nK);

		for (int i = 0; i < nK; i++) {
			cin >> vPermutation[i];

			if (i < 6) {
				vPermutation2[i] = 1;
			}
			else {
				vPermutation2[i] = 2;
			}
		}

		while (true) {
			for (int i = 0; i < nK; i++) {
				if (vPermutation2[i] == 1) {
					cout << vPermutation[i] << " ";
				}
			}
			cout << "\n";

			if (!next_permutation(vPermutation2.begin(), vPermutation2.end())) {
				break;
			}
		}
		cout << "\n";
	}


	return 0;
}


int fn_rounds_city()
{
	int nMin = 0;
	int nN = 0;
	vector<vector<int>> vW(10, vector<int>(10));
	cin >> nN;

	vector<int> vPermutation(nN);
	for (int i = 0; i < nN; i++) {
		vPermutation[i] = i;
	}

	for (int i = 0; i < nN; i++) {
		for (int j = 0; j < nN; j++) {
			cin >> vW[i][j];
		}
	}

	nMin = -1;
	while (true) {
		int nTmp = 0;
		
		nTmp = fn_rounds_city_calc(vPermutation, vW);

		if (!next_permutation(vPermutation.begin(), vPermutation.end())) {
			break;
		}

		if (nTmp < 0) {
			continue;
		}

		if (nMin == -1 || nMin > nTmp) {
			nMin = nTmp;
		}
	}

	cout << nMin << "\n";

	return 0;
}

int fn_rounds_city_calc(vector<int>& vPermutation, vector<vector<int>>& vW)
{
	int nSum = 0;
	int nIdx1 = 0;
	int nIdx2 = 0;

	for (int i = 0; i < vPermutation.size(); i++) {
		nIdx1 = i;
		nIdx2 = i + 1;

		if (nIdx2 == vPermutation.size()) {
			nIdx2 = 0;
		}

		if (vW[vPermutation[nIdx1]][vPermutation[nIdx2]] == 0) {
			return -1;
		}

		nSum += vW[vPermutation[nIdx1]][vPermutation[nIdx2]];
	}

	return nSum;
}

int fn_max_minus()
{
	int nMax = 0;
	int nN = 0;

	cin >> nN;

	vector<int> vPermutation(nN);

	for (int i = 0; i < nN; i++) {
		cin >> vPermutation[i];
	}

	sort(vPermutation.begin(), vPermutation.end());

	nMax = 0;
	while (true) {
		int nTmp = 0;

		nTmp = fn_max_minus_calc(vPermutation);
		if (nMax < nTmp) {
			nMax = nTmp;
		}

		if (!next_permutation(vPermutation.begin(), vPermutation.end())) {
			break;
		}
	}

	cout << nMax << "\n";


	return 0;
}

int fn_max_minus_calc(vector<int>& vPermutation)
{
	int nSum = 0;

	for (int i = 0; i < vPermutation.size() - 1; i++) {
		nSum += abs(vPermutation[i] - vPermutation[i + 1]);
	}

	return nSum;
}

int fn_all_permutation()
{
	int nN = 0;
	int nResult = 0;
	cin >> nN;

	vector<int> vPermutation(nN);

	for (int i = 0; i < nN; i++) {
		vPermutation[i] = i + 1;
		cout << vPermutation[i] << " ";
	}
	cout << "\n";

	while (true) {
		nResult = fn_next_permutation(vPermutation, nN);
		if (nResult < 0) {
			break;
		}

		for (int i = 0; i < nN; i++) {
			cout << vPermutation[i] << " ";
		}
		cout << "\n";
	}


	return 0;
}

int fn_prev()
{
	int nN = 0;
	int nResult = 0;

	cin >> nN;

	vector<int> vPermutation(nN);
	for (int i = 0; i < nN; i++) {
		cin >> vPermutation[i];
	}

	nResult = fn_prev_permutation(vPermutation, nN);
	//nResult = fn_prev_permutation2(vPermutation, nN);
	if (nResult < 0) {
		cout << -1 << "\n";
	}
	else {
		for (int i = 0; i < nN; i++) {
			cout << vPermutation[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}

int fn_prev_permutation(vector<int>& vPermutation, int nLen)
{
	int nIdx = -1;

	for (int i = nLen - 1; i > 0; i--) {
		if (vPermutation[i] < vPermutation[i - 1]) {
			nIdx = i - 1;
			break;
		}
	}

	if (nIdx < 0) {
		return -1;
	}

	for (int i = nLen - 1; i > nIdx; i--) {
		if (vPermutation[nIdx] > vPermutation[i]) {
			swap(vPermutation[nIdx], vPermutation[i]);
			break;
		}
	}

	reverse(vPermutation.begin() + nIdx + 1, vPermutation.end());

	return 0;
}

int fn_prev_permutation2(vector<int>& vPermutation, int nLen)
{
	bool bCheck = false;

	bCheck = prev_permutation(vPermutation.begin(), vPermutation.end());
	if (!bCheck) {
		return -1;
	}

	return 0;
}

int fn_next()
{
	int nN = 0;
	int nResult = 0;

	cin >> nN;

	vector<int> vPermutation(nN);
	for (int i = 0; i < nN; i++) {
		cin >> vPermutation[i];
	}

	nResult = fn_next_permutation(vPermutation, nN);
	//nResult = fn_next_permutation2(vPermutation, nN);
	if (nResult < 0) {
		cout << -1 << "\n";
	}
	else {
		for (int i = 0; i < nN; i++) {
			cout << vPermutation[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}

int fn_next_permutation(vector<int>& vPermutation, int nLen)
{
	int nIdx = -1;

	for (int i = nLen - 1; i > 0; i--) {
		if (vPermutation[i] > vPermutation[i - 1]) {
			nIdx = i - 1;
			break;
		}
	}

	if (nIdx < 0) {
		//cout << -1 << "\n";
		return -1;
	}

	for (int i = nLen - 1; i > nIdx; i--) {
		if (vPermutation[nIdx] < vPermutation[i]) {
			swap(vPermutation[nIdx], vPermutation[i]);
			break;
		}
	}

	reverse(vPermutation.begin() + nIdx + 1, vPermutation.end());

	return 0;
}

int fn_next_permutation2(vector<int>& vPermutation, int nLen)
{
	bool bCheck = false;
	bCheck = next_permutation(vPermutation.begin(), vPermutation.end());
	if(!bCheck) {
		return -1;
	}

	return 0;
}

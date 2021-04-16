#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fn_Brute_Force_01();	//2309 : 일곱난쟁이
int fn_Brute_Force_02();	//3085 : 봄보니
int fn_Check(vector<string>& vList);
int fn_Brute_Force_03();	//1476 : 날짜계산
int fn_Brute_Force_04();	//1107 : 리모컨
int fn_Brute_Force_05();	//14500 : 테트로미노
int fn_Calc(vector<vector<int>>& vMap, vector<string>& vBlock, int nX, int nY);
vector<string>& fn_Mirror(vector<string>& vBlock);
vector<string>& fn_Rotate(vector<string>& vBlock);


int main()
{

	fn_Brute_Force_05();
	return 0;
}


//14500 : 테트로미노
int fn_Brute_Force_05()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<vector<string>> vBlocks = {
		{"1111"},
		{"11",
		 "11"},
		{"10",
		 "10",
		 "11"},
		{"10",
		 "11",
		 "01"},
		{"111",
		 "010"}
	};

	int nN = 0;
	int nM = 0;
	int nMax = 0;
	cin >> nN >> nM;

	vector<vector<int>> vMap(nN, vector<int>(nM));

	for (int i = 0; i < nN; i++) {
		for (int j = 0; j < nM; j++) {
			cin >> vMap[i][j];
		}
	}


	for (int i = 0; i < nN; i++) {
		for (int j = 0; j < nM; j++) {
			for (auto& block : vBlocks) {
				vector<string> vTmp(block);
				for (int mir = 0; mir < 2; mir++) {
					for (int rot = 0; rot < 4; rot++) {
						int nCur = fn_Calc(vMap, vTmp, i, j);
						if (nCur != -1 && nMax < nCur) {
							nMax = nCur;
						}

						block = fn_Rotate(block);
					}
					block = fn_Mirror(block);
				}
			}
		}
	}

	cout << nMax << "\n";



	return 0;
}

int fn_Calc(vector<vector<int>>& vMap, vector<string>& vBlock, int nX, int nY)
{
	int nSum = 0;
	int nRow = vMap.size();
	int nCol = vMap[0].size();

	for (int i = 0; i < vBlock.size(); i++) {
		for (int j = 0; j < vBlock[0].size(); j++) {
			if (vBlock[i][j] == 0) {
				continue;
			}

			int nTmpX = nX + i;
			int nTmpY = nY + j;
			if (nTmpX >= 0 && nTmpX < nRow && nTmpY >= 0 && nTmpX < nCol) {
				nSum += vMap[nTmpX][nTmpY];
			}
			else {
				return -1;
			}

		}
	}

	return nSum;
}

vector<string>& fn_Mirror(vector<string>& vBlock)
{
	//좌우 대칭
	vector<string> vTmp(vBlock.size());

	for (int i = 0; i < vBlock.size(); i++) {
		string strTmp(vBlock[i]);

		reverse(strTmp.begin(), strTmp.end());
		vTmp[i] = strTmp;
	}

	return vTmp;
}

vector<string>& fn_Rotate(vector<string>& vBlock)
{
	//90도 회전
	vector<string> vTmp(vBlock[0].size());

	for (int i = 0; i < vBlock[0].size(); i++) {
		for (int j = (int)vBlock.size() - 1; j >= 0; j--) {
			vTmp[i] += vBlock[j][i];
		}
	}


	return vTmp;
}


//1107 : 리모컨 - 이해 안됨...
int fn_Brute_Force_04()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 0 - 9, +, -
	int nCurrent = 100;
	string strChannel;
	int nCount = 0;
	bool bBtnChk[10] = { 0, };




	return 0;
}


//1476 : 날짜계산
int fn_Brute_Force_03()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nE = 0;
	int nS = 0;
	int nM = 0;
	int nE1 = 0;
	int nS1 = 0;
	int nM1 = 0;

	cin >> nE >> nS >> nM;

	nE1 = 1;
	nS1 = 1;
	nM1 = 1;

	for (int i = 1; ; i++) {
		if (nE == nE1 && nS == nS1 && nM == nM1) {
			cout << i << "\n";
			break;
		}

		nE1++;
		nS1++;
		nM1++;

		if (nE1 > 15) {
			nE1 = 1;
		}

		if (nS1 > 28) {
			nS1 = 1;
		}

		if (nM1 > 19) {
			nM1 = 1;
		}
	}


	return 0;
}


//3085 : 봄보니
int fn_Brute_Force_02()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nResult = 0;
	int nN = 0;

	cin >> nN;

	vector<string> vList(nN);

	for (int i = 0; i < nN; i++) {
		cin >> vList[i];
	}


	for (int i = 0; i < nN; i++) {
		for (int j = 0; j < nN; j++) {
			if (j + 1 < nN) {
				swap(vList[i][j], vList[i][j + 1]);
				int nTmp = fn_Check(vList);
				if (nResult < nTmp) {
					nResult = nTmp;
				}
				swap(vList[i][j], vList[i][j + 1]);
			}

			if (i + 1 < nN) {
				swap(vList[i][j], vList[i+1][j]);
				int nTmp = fn_Check(vList);
				if (nResult < nTmp) {
					nResult = nTmp;
				}
				swap(vList[i][j], vList[i+1][j]);
			}
		}
	}
	cout << nResult << "\n";

	return 0;
}

int fn_Check(vector<string>& vList)
{
	int nResult = 0;
	int nCount = 0;
	int nLen = vList.size();

	nResult = 1;
	for (int i = 0; i < nLen; i++) {
		nCount = 1;
		for (int j = 0; j < nLen - 1; j++) {
			if (vList[i][j] == vList[i][j + 1]) {
				nCount++;
			}
			else {
				nCount = 1;
			}

			if (nResult < nCount) {
				nResult = nCount;
			}
		}

		nCount = 1;
		for (int j = 0; j < nLen - 1; j++) {
			if (vList[j][i] == vList[j + 1][i]) {
				nCount++;
			}
			else {
				nCount = 1;
			}


			if (nResult < nCount) {
				nResult = nCount;
			}
		}

	}

	return nResult;
}



//2309 : 일곱난쟁이
int fn_Brute_Force_01()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const int LEN = 9;
	vector<int> vList(LEN);
	int nSum = 0;

	for (int i = 0; i < LEN; i++) {
		cin >> vList[i];
		nSum += vList[i];
	}

	sort(vList.begin(), vList.end());

	cout << "\n";

	for (int i = 0; i < LEN; i++) {
		for (int j = i + 1; j < LEN; j++) {
			if ((nSum - (vList[i] + vList[j])) == 100) {

				for (int k = 0; k < LEN; k++) {
					if (i == k || j == k) {
						continue;
					}
					cout << vList[k] << "\n";
				}

				return 0;
			}
		}
	}
	return 0;
}
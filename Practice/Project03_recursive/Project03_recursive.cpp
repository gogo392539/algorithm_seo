// Project03_recursive.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fn_Recursive01();	//9095 : 1,2,3 더하기
int fn_Count(int nSum, int nN);

int fn_Recursive02();	//1759 : 암호 만들기
void fn_Password(vector<char>& vList, string strPasswd, int nIdx, int nC);
bool fn_Check_Passwd(string strPasswd);

int g_nAns = 0;
int fn_Recursive03();	//14501 : 퇴사
void fn_Resigned(vector<int>& vT, vector<int>& vP, int nN, int nDay, int nSum);

int fn_Recursive04();	//14889 : 스타트와 링크


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	fn_Recursive03();

	return 0;
}


int fn_Recursive04()
{
	int nN = 0;

	cin >> nN;

	vector<vector<int>> vS(nN, vector<int>(nN));

	for (int i = 0; i < nN; i++) {
		for (int j = 0; j < nN; j++) {
			cin >> vS[i][j];
		}
	}



	return 0;
}



int fn_Recursive03()
{
	int nN = 0;

	cin >> nN;

	vector<int> vT(20);
	vector<int> vP(20);

	for (int i = 1; i <= nN; i++) {
		cin >> vT[i] >> vP[i];
	}

	fn_Resigned(vT, vP, nN, 1, 0);

	cout << g_nAns << "\n";

	return 0;
}

void fn_Resigned(vector<int>& vT, vector<int>& vP, int nN, int nDay, int nSum) 
{
	if (nDay == nN + 1) {
		if (g_nAns < nSum) {
			g_nAns = nSum;
		}
		return;
	}

	if (nDay > nN) {
		return;
	}

	fn_Resigned(vT, vP, nN, nDay + vT[nDay], nSum + vP[nDay]);
	fn_Resigned(vT, vP, nN, nDay + 1, nSum);
}


int fn_Recursive02()
{
	int nL = 0;
	int nC = 0;
	
	cin >> nL >> nC;

	vector<char> vList(nC);
	string strPasswd;

	for (int i = 0; i < nC; i++) {
		cin >> vList[i];
		//cin.ignore();
	}

	sort(vList.begin(), vList.end());

	fn_Password(vList, strPasswd, 0, nL);


	return 0;
}

void fn_Password(vector<char>& vList, string strPasswd, int nIdx, int nL)
{
	if (strPasswd.length() == nL) {
		if (fn_Check_Passwd(strPasswd)) {
			cout << strPasswd << "\n";
		}
		
		return ;
	}

	if (nIdx >= vList.size()) {
		return ;
	}


	fn_Password(vList, strPasswd + vList[nIdx], nIdx + 1, nL);
	fn_Password(vList, strPasswd, nIdx + 1, nL);

}

bool fn_Check_Passwd(string strPasswd)
{
	int nConsonant = 0;		//자음
	int nVowel = 0;			//모음


	for (int i = 0; i < strPasswd.length(); i++) {
		if (strPasswd[i] == 'a' || strPasswd[i] == 'i' || strPasswd[i] == 'e' || strPasswd[i] == 'o' || strPasswd[i] == 'u') {
			nVowel++;
		}
		else {
			nConsonant++;
		}
	}

	if (nConsonant < 2) {
		return false;
	}

	if (nVowel < 1) {
		return false;
	}


	return true;
}


int fn_Recursive01()
{
	int nCase = 0;
	
	cin >> nCase;

	for (int i = 0; i < nCase; i++) {
		int nN = 0;
		int nSum = 0;
		int nResult = 0;
		cin >> nN;
		nResult = fn_Count(nSum, nN);
		cout << nResult << "\n";
	}

	

	return 0;
}

int fn_Count(int nSum, int nN)
{
	if (nSum == nN) {
		return 1;
	}
	else if (nSum > nN) {
		return 0;
	}

	int nCount = 0;

	for (int i = 1; i <= 3; i++) {
		nCount += fn_Count(nSum + i, nN);
		
	}
	return nCount;
}


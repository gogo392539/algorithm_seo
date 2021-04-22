// Practice04_bruteforce_M_N.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//1248 : 맞춰봐
int nCorrect = 0;
bool g_correctCheck[21] = { 0, };
vector<vector<int>> g_vCorrectS(10, vector<int>(10));
vector<int> g_vCorrect(10);
int fn_correct();
bool fn_correct_recursive(int nIdx);
bool fn_correct_check(int nIdx);

//2529 : 부등호
bool g_barCheck[10] = { 0, };
char g_szSign[20] = { 0, };
vector<string> g_vResult;
int fn_sign();
void fn_sign_recursive(int nLen, int nIdx, string strNum);
bool fn_sign_check(string strNum, int nLen);

//15661 : 링크와 스타트
vector<vector<int>> g_vS2(20, vector<int>(20));
int fn_link_and_start();
int fn_link_and_start_recursive(vector<int>& vTeam1, vector<int>& vTeam2, int nIdx, int nTotal);


//14889 : 스타트와 링크
vector<vector<int>> g_vS(20, vector<int>(20));
int fn_start_and_link();
int fn_start_and_link_recursive(vector<int>& vTeam1, vector<int> vTeam2, int nIdx, int nTotal);

//14501 : 퇴사
int g_nSum = 0;
int fn_resign();
void fn_resign_recursive(vector<int>& vT, vector<int>& vP, int nDay, int nFDay, int nSum);

//1795 : 암호만들기
int fn_make_passwd();
void fn_make_passwd_recursive(vector<char>& vC, string strPasswd, int nLen, int nIdx);
bool fn_make_passwd_check(string& strPasswd);

//9095 : 1, 2, 3 더하기
int fn_pluse_one_two_three();
int fn_pluse_one_two_three_recursive(int nInput, int nSum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//fn_pluse_one_two_three();
	//fn_make_passwd();
	//fn_resign();
	//fn_start_and_link();
	//fn_link_and_start();
	//n_sign();
	fn_correct();

	return 0;
}

int fn_correct()
{
	int nCount = 0;
	string strS;
	cin >> nCorrect >> strS;

	for (int i = 0; i < nCorrect; i++) {
		for (int j = i; j < nCorrect; j++) {
			if (strS[i] == '0') {
				g_vCorrectS[i][j] = 0;
			}
			else if (strS[i] == '+') {
				g_vCorrectS[i][j] = 1;
			}
			else  {
				g_vCorrectS[i][j] = -1;
			}
		}

		nCount++;
	}

	fn_correct_recursive(0);

	for (int i = 0; i < nCorrect; i++) {
		cout << g_vCorrect[i] << " ";
	}
	cout << "\n";


	return 0;
}

bool fn_correct_recursive(int nIdx)
{

	return true;
}

bool fn_correct_check(int nIdx)
{


	return true;
}

int fn_sign()
{
	int nN = 0;
	string strNum;

	cin >> nN;

	for (int i = 0; i < nN; i++) {
		cin >> g_szSign[i];
	}

	fn_sign_recursive(nN, 0, strNum);
	
	auto result = minmax_element(g_vResult.begin(), g_vResult.end());
	cout << *result.second << "\n";
	cout << *result.first << "\n";

	return 0;
}

void fn_sign_recursive(int nLen, int nIdx, string strNum)
{
	if (nIdx == nLen + 1) {
		if(fn_sign_check(strNum, nLen)) {
			g_vResult.push_back(strNum);
		}
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (g_barCheck[i]) {
			continue;
		}

		g_barCheck[i] = true;
		fn_sign_recursive(nLen, nIdx + 1, strNum + to_string(i));
		g_barCheck[i] = false;
	}

}

bool fn_sign_check(string strNum, int nLen)
{
	for (int i = 0; i < nLen; i++) {
		if (g_szSign[i] == '<') {
			if (strNum[i] > strNum[i + 1]) {
				return false;
			}
		}
		else if (g_szSign[i] == '>') {
			if (strNum[i] < strNum[i + 1]) {
				return false;
			}

		}
	}

	return true;
}

int fn_link_and_start()
{
	int nN = 0;
	vector<int> vTeam1;
	vector<int> vTeam2;

	cin >> nN;

	for (int i = 0; i < nN; i++) {
		for (int j = 0; j < nN; j++) {
			cin >> g_vS2[i][j];
		}
	}

	cout << fn_link_and_start_recursive(vTeam1, vTeam2, 0, nN) << "\n";

	return 0;
}

int fn_link_and_start_recursive(vector<int>& vTeam1, vector<int>& vTeam2, int nIdx, int nTotal)
{
	if (nIdx == nTotal) {
		if (vTeam1.empty() || vTeam2.empty()) {
			return -1;
		}

		int nSum1 = 0;
		int nSum2 = 0;
		int nResult = 0;

		for (int i = 0; i < vTeam1.size(); i++) {
			for (int j = 0; j < vTeam1.size(); j++) {
				if (i == j) {
					continue;
				}

				nSum1 += g_vS2[vTeam1[i]][vTeam1[j]];
			}
		}

		for (int i = 0; i < vTeam2.size(); i++) {
			for (int j = 0; j < vTeam2.size(); j++) {
				if (i == j) {
					continue;
				}

				nSum2 += g_vS2[vTeam2[i]][vTeam2[j]];
			}
		}

		nResult = nSum1 - nSum2;
		if (nResult < 0) {
			nResult = -nResult;
		}

		return nResult;
	}



	int nResult = -1;
	vTeam1.push_back(nIdx);
	int nT1 = fn_link_and_start_recursive(vTeam1, vTeam2, nIdx + 1, nTotal);
	if (nResult == -1 || (nT1 != -1 && nResult > nT1)) {
		nResult = nT1;
	}
	vTeam1.pop_back();


	vTeam2.push_back(nIdx);
	int nT2 = fn_link_and_start_recursive(vTeam1, vTeam2, nIdx + 1, nTotal);
	if (nResult == -1 || (nT2 != -1 && nResult > nT2)) {
		nResult = nT2;
	}
	vTeam2.pop_back();


	return nResult;
}

int fn_start_and_link()
{
	int nN = 0;
	vector<int> vTeam1;
	vector<int> vTeam2;

	cin >> nN;

	for (int i = 0; i < nN; i++) {
		for (int j = 0; j < nN; j++) {
			cin >> g_vS[i][j];
		}
	}

	cout << fn_start_and_link_recursive(vTeam1, vTeam2, 0, nN) << "\n";

	return 0;
}

int fn_start_and_link_recursive(vector<int>& vTeam1, vector<int> vTeam2, int nIdx, int nTotal)
{
	if (nIdx == nTotal) {
		if (vTeam1.size() != nTotal / 2) {
			return -1;
		}
		if (vTeam2.size() != nTotal / 2) {
			return -1;
		}

		int nT11 = 0;
		int nT22 = 0;
		int nResult = 0;

		for (int i = 0; i < nTotal / 2; i++) {
			for (int j = 0; j < nTotal / 2; j++) {
				if (i == j) {
					continue;
				}
				nT11 += g_vS[vTeam1[i]][vTeam1[j]];
				nT22 += g_vS[vTeam2[i]][vTeam2[j]];
			}
		}

		nResult = nT11 - nT22;
		if (nResult < 0) {
			nResult = -nResult;
		}
		return nResult;
	}

	if (vTeam1.size() > nTotal / 2) {
		return -1;
	}
	if (vTeam2.size() > nTotal / 2) {
		return -1;
	}


	int nResult = -1;
	vTeam1.push_back(nIdx);
	int nT1 = fn_start_and_link_recursive(vTeam1, vTeam2, nIdx + 1, nTotal);
	if (nResult == -1 || (nT1 != -1 && nResult > nT1)) {
		nResult = nT1;
	}
	vTeam1.pop_back();

	vTeam2.push_back(nIdx);
	int nT2 = fn_start_and_link_recursive(vTeam1, vTeam2, nIdx + 1, nTotal);
	if (nResult == -1 || (nT2 != -1 && nResult > nT2)) {
		nResult = nT2;
	}
	vTeam2.pop_back();

	return nResult;
}

int fn_resign()
{
	int nN = 0;

	cin >> nN;

	vector<int> vT(nN);
	vector<int> vP(nN);

	for (int i = 0; i < nN; i++) {
		cin >> vT[i] >> vP[i];
	}

	fn_resign_recursive(vT, vP, nN, 0, 0);

	cout << g_nSum << "\n";

	return 0;
}

void fn_resign_recursive(vector<int>& vT, vector<int>& vP, int nDay, int nFDay, int nSum)
{
	if (nFDay == nDay) {
		if (g_nSum < nSum) {
			g_nSum = nSum;
		}
		return;
	}

	if (nFDay > nDay) {
		return;
	}

	fn_resign_recursive(vT, vP, nDay, nFDay + 1, nSum);
	fn_resign_recursive(vT, vP, nDay, nFDay + vT[nFDay], nSum + vP[nFDay]);

}

int fn_make_passwd()
{
	int nL = 0;
	int nC = 0;

	cin >> nL >> nC;

	vector<char> vC(nC);
	string strPasswd;

	for (int i = 0; i < nC; i++) {
		cin >> vC[i];
	}

	sort(vC.begin(), vC.end());

	fn_make_passwd_recursive(vC, strPasswd, nL, 0);


	return 0;
}

void fn_make_passwd_recursive(vector<char>& vC, string strPasswd, int nLen, int nIdx)
{
	if (nLen == strPasswd.length()) {
		if (fn_make_passwd_check(strPasswd)) {
			cout << strPasswd << "\n";
		}
		return;
	}

	if (nIdx == vC.size()) {
		return;
	}

	fn_make_passwd_recursive(vC, strPasswd + vC[nIdx], nLen, nIdx + 1);
	fn_make_passwd_recursive(vC, strPasswd, nLen, nIdx + 1);
}

bool fn_make_passwd_check(string& strPasswd)
{
	int nConsonant = 0;
	int nVowel = 0;

	for (int i = 0; i < strPasswd.length(); i++) {
		if (strPasswd[i] == 'a' || strPasswd[i] == 'e' || strPasswd[i] == 'i' || strPasswd[i] == 'o' || strPasswd[i] == 'u') {
			nVowel++;
		}
		else {
			nConsonant++;
		}
	}

	if (nVowel >= 1 && nConsonant >= 2) {
		return true;
	}

	return false;
}

int fn_pluse_one_two_three()
{
	int nTestCase = 0;
	

	cin >> nTestCase;

	for (int i = 0; i < nTestCase; i++) {
		int nInput = 0; // 0 < nInput < 11
		int nCount = 0;

		cin >> nInput;

		//M(n) = M(1) + M(2) + M(3)
		nCount = fn_pluse_one_two_three_recursive(nInput, 0);
		cout << nCount << "\n";
	}

	return 0;
}

int fn_pluse_one_two_three_recursive(int nInput, int nSum)
{
	if (nSum == nInput) {
		return 1;
	}

	if (nSum > nInput) {
		return 0;
	}

	return fn_pluse_one_two_three_recursive(nInput, nSum + 1) + fn_pluse_one_two_three_recursive(nInput, nSum + 2) + fn_pluse_one_two_three_recursive(nInput, nSum + 3);
}



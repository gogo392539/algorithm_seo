// Practice_01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

void fn_Remainder1();	//10430번
void fn_Remainder2();	//4375번

void fn_Aliquot1();		//1037 : 약수
void fn_Aliquot2();		//17427 : 약수
void fn_Aliquot3();		//17425 : 약수

void fn_GCD_LCM();		//2609 : 최대공약수, 최소공배수
int fn_GCD(int nNum1, int nNum2);

void fn_PrimeNum1();		//1978 : 소수
bool fn_isPrime(int nNum);
void fn_PrimeNum2();		//1929 : 소수

using namespace std;

int main()
{
	fn_PrimeNum2();
}


//10430 : 나머지
void fn_Remainder1()
{
	int nA = 0;
	int nB = 0;
	int nC = 0;
	int nResult1 = 0;
	int nResult2 = 0;
	int nResult3 = 0;
	int nResult4 = 0;

	cout << "10430번" << "\n";
	cin >> nA >> nB >> nC;

	nResult1 = (nA + nB) % nC;
	nResult2 = ((nA % nC) + (nB % nC)) % nC;
	nResult3 = (nA * nB) % nC;
	nResult4 = ((nA % nC) * (nB % nC)) % nC;


	cout << nResult1 << "\n";
	cout << nResult2 << "\n";
	cout << nResult3 << "\n";
	cout << nResult4 << "\n";
}

//4375 : 나머지
void fn_Remainder2()
{
	int nN = 0;
	int nData = 0;
	int nIdx = 0;

	cout << "4375번" << "\n";

	while (cin >> nN) {
		nIdx = 0;
		for (int i = 1; ; i++) {
			nData = nData * 10 + 1;
			nData %= nN;

			if (nData == 0) {
				cout << i << "\n";
				break;
			}

		}
	}
}

//1037 : 약수
void fn_Aliquot1()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nCount = 0;
	int nTmp = 0;
	int nMax = 0;
	int nMin = 0;
	vector<int> vData;

	cout << "1037 번\n";

	cin >> nCount;

	for (int i = 0; i < nCount; i++) {
		nTmp = 0;
		cin >> nTmp;
		vData.push_back(nTmp);
	}

	sort(vData.begin(), vData.end());
	cout << vData.front() * vData.back() << "\n";

	/*nMax = nMin = vData[0];
	for (int i = 1; i < nCount; i++) {
		if (nMax < vData[i]) {
			nMax = vData[i];
		}

		if (nMin > vData[i]) {
			nMin = vData[i];
		}
	}


	cout << nMax * nMin << "\n";*/
}

//17427 : 약수
void fn_Aliquot2()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nN = 0;
	long long nSum = 0;

	cin >> nN;

	for (int i = 1; i <= nN; i++) {
		nSum += (long long)(nN / i) * i;
	}
	
	cout << nSum << '\n';
}

//17425 : 약수
void fn_Aliquot3()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const int MAX = 1000000;
	int nCase = 0;
	vector<long long> vList(MAX + 1, 1);
	vector<long long> vSum(MAX + 1);

	for (int i = 2; i <= MAX; i++) {
		for (int j = 1; j * i <= MAX; j++) {
			vList[i * j] += i;
		}
	}

	for (int i = 1; i <= MAX; i++) {
		vSum[i] = vSum[i - 1] + vList[i];
	}

	cin >> nCase;
	for (int i = 0; i < nCase; i++) {
		int nN = 0;
		cin >> nN;
		cout << vSum[nN] << "\n";
	}
}

//2609
void fn_GCD_LCM()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nNum1 = 0;
	int nNum2 = 0;
	int nGCD = 0;
	int nLCM = 0;

	cin >> nNum1 >> nNum2;

	if (nNum1 < nNum2) {
		int nTmp = nNum1;
		nNum1 = nNum2;
		nNum2 = nTmp;
	}

	nGCD = fn_GCD(nNum1, nNum2);
	nLCM = nNum1 * nNum2 / nGCD;

	cout << nGCD << '\n' << nLCM << '\n';
}

int fn_GCD(int nNum1, int nNum2)
{
	if (nNum2 == 0) {
		return nNum1;
	}
	else {
		return fn_GCD(nNum2, nNum1 % nNum2);
	}
}

//1978 : 소수
void fn_PrimeNum1()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nCase = 0;
	int nCount = 0;
	
	cin >> nCase;

	for (int i = 0; i < nCase; i++) {
		int nNum = 0;
		cin >> nNum;
		
		if (fn_isPrime(nNum)) {
			nCount++;
		}
		
	}
	cout << nCount << "\n";
}

bool fn_isPrime(int nNum)
{
	if (nNum < 2) {
		return false;
	}

	for (int j = 2; j * j <= nNum; j++) {
		if ((nNum % j) == 0) {
			return false;
		}
	}

	return true;
}

void fn_PrimeNum2()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const int MAX = 1000000;
	int nMin = 0;
	int nN = 0;
	int nM = 0;
	bool vPrimeList[MAX + 1] = { 0, };
	vPrimeList[0] = vPrimeList[1] = true;

	for (int i = 2; i * i <= MAX; i++) {
		if (vPrimeList[i] == false) {
			for (int j = i * i; j <= MAX; j += i) {
				vPrimeList[j] = true;
			}
		}
	}


	cin >> nM >> nN;

	for (int i = nM; i <= nN; i++) {
		if(vPrimeList[i] == false) {
			cout << i << "\n";
		}
	}
}




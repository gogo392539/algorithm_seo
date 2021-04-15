// Practice_01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

void fn_Remainder(); //10430

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fn_Remainder();

}


//10430번
void fn_Remainder() {
	int nA = 0;
	int nB = 0;
	int nC = 0;
	int nResult1 = 0;
	int nResult2 = 0;
	int nResult3 = 0;
	int nResult4 = 0;

	cin >> nA >> nB >> nC;

	nResult1 = (nA + nB) % nC;
	nResult2 = ((nA % nC) + (nB % nC)) % nC;
	nResult3 = (nA * nB) % nC;
	nResult4 = ((nA & nC) * (nB % nC)) % nC;


	cout << nResult1 << "\n";
	cout << nResult2 << "\n";
	cout << nResult3 << "\n";
	cout << nResult4 << "\n";
}



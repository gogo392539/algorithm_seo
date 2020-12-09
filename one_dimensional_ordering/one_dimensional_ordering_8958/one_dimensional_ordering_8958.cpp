// one_dimensional_ordering_8958.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

/*등차 수열의 합을 구하는 함수*/
int fn_IsometricSequenceSum(int nFirstTerm/*첫째항*/, int nCommonDifference /*공차*/, int nCountOfTerm /*항의 개수*/);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int nCount = 0;
	
	cin >> nCount;
	
	for (int j = 0; j < nCount; j++) {
		int nSum = 0;
		int nCorrectCount = 0;
		char arQuizResult[80] = { 0, };

		cin >> arQuizResult;

		for (int i = 0; i < strlen(arQuizResult); i++) {
			if (arQuizResult[i] == 'O') {
				nCorrectCount++;
			}

			if (arQuizResult[i] == 'X') {
				nSum += fn_IsometricSequenceSum(1, 1, nCorrectCount);
				nCorrectCount = 0;
			}
		}

		if (nCorrectCount != 0) {
			nSum += fn_IsometricSequenceSum(1, 1, nCorrectCount);
		}

		cout << nSum << "\n";
	}

	


	return 0;
}

/*등차 수열의 합을 구하는 함수*/
int fn_IsometricSequenceSum(int nFirstTerm, int nCommonDifference, int nCountOfTerm)
{
	int nResult = 0;
	int nEndTerm = 0;

	if (nCommonDifference == 0) {
		return 0;
	}

	if (nCountOfTerm == 1) {
		return 1;
	}

	nEndTerm = nFirstTerm + ((nCountOfTerm - 1) * nCommonDifference);

	nResult = nCountOfTerm * (nFirstTerm + nEndTerm) / 2;

	return nResult;
}

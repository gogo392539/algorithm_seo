// selectionSort.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
//선택 정렬

void printData(int *pData, int nSize);
void swapData(int &nSrc, int &nDst);

int main()
{
	int arData[9] = { 4,2,7,3,8,9,5,1,6 };
	int nSize = 0;
	int nMinindex = 0;
	int nMaxCount = 0;
	int nIndex = 0;

	nSize = 9;
	nMaxCount = nSize - 1;

	while (nIndex < nMaxCount) {
		nMinindex = nIndex;
		for (int i = nIndex; i < nSize; i++) {
			if (arData[nMinindex] > arData[i]) {
				nMinindex = i;
			}
		}
		swapData(arData[nMinindex], arData[nIndex]);
		printData(arData, nSize);
		nIndex++;
	}

	
    return 0;
}

void printData(int * pData, int nSize)
{
	for (int i = 0; i < nSize; i++) {
		printf("%d ", pData[i]);
	}
	printf("\n");
}

void swapData(int & nSrc, int & nDst)
{
	int nTmp = nSrc;
	nSrc = nDst;
	nDst = nTmp;
}

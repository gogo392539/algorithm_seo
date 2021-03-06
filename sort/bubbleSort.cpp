// bubbleSort.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void printData(int *pData, int nSize);
void swapData(int &nSrc, int &nDst);

int main()
{
	int arData[9] = { 9,8,7,6,5,4,3,2,1 };
	int nIndex = 0;
	int nCmpIndex = 0;
	int nSize = 0;
	int nCount = 0;

	nSize = 9;
	nCount = nSize - 1;
	for (int i = 0; i < nCount; i++) {
		nIndex = 0;
		while (nIndex < nCount) {
			if (arData[nIndex] > arData[nIndex + 1]) {
				swapData(arData[nIndex], arData[nIndex + 1]);
			}
			nIndex++;
		}
		printData(arData, nSize);
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
	int nTmp = 0;
	nTmp = nSrc;
	nSrc = nDst;
	nDst = nTmp;
}

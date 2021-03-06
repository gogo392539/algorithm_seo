// insertionSort.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void printData(int *pData, int nSize);

int main()
{
	int arData[7] = { 7,1,5,3,2,6,4 };
	int nSize = 0;
	int nIndex = 0;
	int nMaxCount = 0;
	int nBackUpData = 0;
	int nSortIndex = 0;

	nSize = 7;
	nMaxCount = nSize - 1;
	nSortIndex = 1;

	for (int i = 0; i < nMaxCount; i++) {
		nBackUpData = arData[nSortIndex];
		nIndex = nSortIndex;
		while (nIndex > 0 && arData[nIndex - 1] > nBackUpData) {
			arData[nIndex] = arData[nIndex - 1];
			nIndex--;
		}
		arData[nIndex] = nBackUpData;
		printData(arData, nSize);
		nSortIndex++;
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

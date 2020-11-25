// repeat_for_3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

//백준 1110번 문제
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nNum = 0;
    int nNum1 = 0;
    int nNum2 = 0;
    int nNum3 = 0;
    int nSum = 0;
    int nResult = 0;
    int nCount = 0;

    cin >> nNum;

    
    nNum3 = nNum;
    while (1) {
        nNum1 = nNum3 / 10;
        nNum2 = nNum3 % 10;
        nSum = nNum1 + nNum2;
        nResult = nNum2 * 10 + (nSum % 10);

        //cout << nResult << "\n";

        nCount++;
        
        if (nResult == nNum) {
            break;
        }

        nNum3 = nResult;
    }

    cout << nCount << "\n";

    return 0;
}
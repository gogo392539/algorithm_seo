// output_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

//백준 2588번 문제
int main()
{
    int nResult1 = 0;
    int nResult2 = 0;
    int nResult3 = 0;
    int narData1[3] = { 0, };
    int narData2[3] = { 0, };
    char szData1[4] = { 0, };
    char szData2[4] = { 0, };


    cin >> szData1 >> szData2;

    for (int i = 0; i < 3; i++) {
        narData1[i] = szData1[i] - '0';
        narData2[i] = szData2[i] - '0';
    }

    nResult1 = ((narData1[0] * 100) + (narData1[1] * 10) + narData1[2]) * narData2[2];
    cout << nResult1 << endl;

    nResult2 = ((narData1[0] * 100) + (narData1[1] * 10) + narData1[2]) * narData2[1];
    cout << nResult2 << endl;

    nResult3 = ((narData1[0] * 100) + (narData1[1] * 10) + narData1[2]) * narData2[0];
    cout << nResult3 << endl;

    cout << nResult1 + (nResult2 * 10) + (nResult3 * 100) << endl;

    return 0;
}


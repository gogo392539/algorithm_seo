// function_4673.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

void fn_Check_SelfNumber(vector<int>& vData);

int main()
{
	vector<int> vData;
	vData.reserve(10000);

	for (int i = 0; i < 10000; i++) {
		vData.push_back(i + 1);
	}

	for (int i = 0; i < 10000; i++) {
		fn_Check_SelfNumber(vData);
	}

	for (int i = 0; i < 10000; i++) {
		if (vData[i] != 0) {
			cout << vData[i] << "\n";
		}
	}


	

	return 0;
}

void fn_Check_SelfNumber(vector<int>& vData)
{
	


}

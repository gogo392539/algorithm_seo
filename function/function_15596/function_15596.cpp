// function_15596.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long sum(std::vector<int>& a);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();




	return 0;
}

long long sum(std::vector<int>& a) {
	long long ans = 0;

	/*accumulate()를 이용한 합 구하는 방법*/
	ans = accumulate(a.begin(), a.end(), 0LL);

	/*
	//vector 데이터를 직접 다 더하는 방법
	for (int i = 0; i < a.size(); i++) {
		ans += a[i];
	}
	*/

	return ans;
}

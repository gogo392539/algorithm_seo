// programmers2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 문제 : 프린터

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location);
void printVector(vector<int> vData);

int main()
{
	vector<int> priorities;
	priorities.reserve(5);

	priorities.push_back(1);
	priorities.push_back(1);
	priorities.push_back(9);
	priorities.push_back(1);
	priorities.push_back(1);
	priorities.push_back(1);

	//int nMax = *max_element(priorities.begin()+1, priorities.end());
	//cout << nMax << endl;



	solution(priorities, 0);


	return 0;
}

int solution(vector<int> vPriorities, int location) 
{
	int answer = 0;
	int nIdx = 0;
	int nMax = 0;
	int nFirst = 0;
	vector<int> vOrder; 

	for (int i = 0; i < vPriorities.size(); i++) {
		if (location == i) {
			vOrder.push_back(location);
		}
		else {
			vOrder.push_back(-1);
		}
	}

	while (!vPriorities.empty()) {
		nFirst = vPriorities.front();

		nMax = *max_element(vPriorities.begin() + 1, vPriorities.end());

		if (nFirst >= nMax) {
			if (vOrder[0] == location) {
				answer = nIdx + 1;
				break;
			}

			vPriorities.erase(vPriorities.begin());
			vOrder.erase(vOrder.begin());
			nIdx++;
		}
		else {
			int nOrder = vOrder.front();

			vPriorities.erase(vPriorities.begin());
			vOrder.erase(vOrder.begin());

			vPriorities.push_back(nFirst);
			vOrder.push_back(nOrder);
		}
	}
	
	cout << answer << endl;
	//printVector(vOrder);


	return answer;
}

void printVector(vector<int> vData) 
{

	for (int i = 0; i < vData.size(); i++) {
		cout << vData[i] << endl;
	}

}
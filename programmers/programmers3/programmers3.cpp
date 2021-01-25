// programmers3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 문제 : 기능개발(LEVEL 2)

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> vProgresses, vector<int> vSpeeds);
void printVector(vector<int> vData);

int main()
{
	vector<int> vProgresses;
	vector<int> vSpeed;
	vector<int> vResult;

	vProgresses.reserve(6);
	vSpeed.reserve(6);

	vProgresses.push_back(95);
	vProgresses.push_back(90);
	vProgresses.push_back(99);
	vProgresses.push_back(99);
	vProgresses.push_back(80);
	vProgresses.push_back(99);

	vSpeed.push_back(1);
	vSpeed.push_back(1);
	vSpeed.push_back(1);
	vSpeed.push_back(1);
	vSpeed.push_back(1);
	vSpeed.push_back(1);

	vResult = solution(vProgresses, vSpeed);
	printVector(vResult);


	return 0;
}

vector<int> solution(vector<int> vProgresses, vector<int> vSpeeds)
{
	int nTmp = 0;
	vector<int> vAnswer;
	vector<int> vTmp;
	vTmp.reserve(vProgresses.size());

	for (int i = 0; i < vProgresses.size(); i++) {
		int nRemainder = 0; /*나머지*/
		int nQuotient = 0;	/*몫*/
		int nData = 0;

		nQuotient = (100 - vProgresses[i]) / vSpeeds[i];
		nRemainder = (100 - vProgresses[i]) % vSpeeds[i];
		if (nRemainder == 0) {
			nData = nQuotient;
		}
		else {
			nData = nQuotient + 1;
		}

		vTmp.push_back(nData);
	}
	//printVector(vTmp);

	while (!vTmp.empty()) {
		int nCount = 0;
		nTmp = vTmp.front();

		while (1) {
			if (vTmp.empty()) {
				break;
			}
			if (nTmp >= vTmp.front()) {
				vTmp.erase(vTmp.begin());
				nCount++;
			}
			else {
				break;
			}
		}
		vAnswer.push_back(nCount);
	}
	//printVector(vAnswer);

	return vAnswer;
}

void printVector(vector<int> vData)
{

	for (int i = 0; i < vData.size(); i++) {
		cout << vData[i] << endl;
	}

}

#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int testCase;
	//testcase 입력
	cin >> testCase;

	int dCount; //문서의 수
	int dPosition; //문서의 위치
	int dImportance; //문서의 중요도
	queue<int> q;

	for (int i = 0; i < testCase; i++) {
		//문서의 수 입력
		cin >> dCount;
		//문서의 위치 입력
		cin >> dPosition;
		//문서의 중요도 입력
		cin >> dImportance;

		for (int i = 0; i < dCount; i++) {

		}


		if (!q.empty()) {
			q.pop();
		}
	}



	return 0;
}
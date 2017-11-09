#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int testCase;
	int dCount;
	int dPosition;
	int imp;
	int count;
	int result;
	queue<pair<int, int>> q;
	vector<int> v;
	pair<int, int> temp;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cin >> dCount;
		cin >> dPosition;

		for (int j = 0; j < dCount; j++) {
			cin >> imp;
			v.push_back(imp);
			if (j != dPosition) {
				q.push(make_pair(imp, 0));
			}
			else {
				q.push(make_pair(imp, 1));
			}
		}

		sort(v.begin(), v.end());
		count = 0;
		result = 0;
		while (!q.empty()) {
			if (v.back() > q.front().first) {
				temp = q.front();
				q.pop();
				q.push(temp);
			}
			else if (v.back() == q.front().first) {
				count++;
				if (q.front().second == 1) {
					result = count;
				}
				q.pop();
				v.pop_back();
			}
		}
		cout << result << endl;
	}

	return 0;
}
//int main(void) {
//	int testCase;
//	//testcase 입력
//	cin >> testCase;
//
//	int dCount; //문서의 수
//	int dPosition; //문서의 위치
//	int dImportance; //문서의 중요도
//	int imp;
//	int escapeCode;
//	int temp;
//	vector<int> v;
//	queue<int> q;
//
//	for (int i = 0; i < testCase; i++) {
//		//문서의 수 입력
//		while (1) {
//			cin >> dCount;
//			if (dCount > 0 && dCount <= 100)
//				break;
//		}
//		//문서의 위치 입력
//		while (1) {
//			cin >> dPosition;
//			if (dPosition >= 0 && dPosition < dCount)
//				break;
//		}
//		//N개 문서에 대한 중요도 입력
//		for (int j = 0; j < dCount; j++) {
//			cin >> imp;
//			v.push_back(imp);
//			q.push(imp);
//			if (j == dPosition) {
//				dImportance = imp;
//			}
//		}
//
//		sort(v.begin(), v.end());
//		escapeCode = 0;
//
//		while (1) {
//			if (v.back() > q.front()) {
//				temp = q.front();
//				q.push(temp);
//				q.pop();
//				if (dPosition == 0) {
//					dPosition = dCount - 1;
//				}
//				else {
//					dPosition--;
//				}
//			}
//			else {
//				if (escapeCode == dPosition) {
//					break;
//				}
//				escapeCode++;
//				q.pop();
//				v.pop_back();
//			}
//		}
//
//		cout << dPosition + 1 << endl;
//		while (!q.empty()) {
//			q.pop();
//		}
//		while (!v.empty()) {
//			v.pop_back();
//		}
//	}
//
//	return 0;
//}
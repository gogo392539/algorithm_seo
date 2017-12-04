#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int T;			//test case의 수
	string strP;	//수행할 함수
	string strX;
	int n;			//배열에 들어있는 수의 개수
	deque<int> x;	//배열에 들어있는 수
	//int tempX = 0;
	char temp;
	int result;
	int plen;
	int rev;

	cin >> T;

	for (int i = 0; i < T; i++) {
		strP = "";
		strX = "";
		rev = 1;
		cin >> strP;
		plen = strP.length();

		cin >> n;

		result = 1;

		while (1) {
			
			temp = getchar();
			if (temp >= '0' && temp <= '9') {
				strX += temp;
			}
			else if (temp == ',') {
				x.push_back(atoi(strX.c_str()));
				strX = "";
			}
			else if (temp == ']') {
				if (strX != "") {
					x.push_back(atoi(strX.c_str()));
				}
				strX = "";
				break;
			}
		}

		/*while (1) {
			temp = getchar();
			if (temp >= '0' && temp <= '9') {
				tempX *= 10;
				tempX += temp - '0';
			}
			else if (temp == ',') {
				x.push_back(tempX);
				tempX = 0;
			}
			else if (temp == ']') {
				if (tempX != 0) {
					x.push_back(tempX);
				}
				tempX = 0;
				break;
			}
		}*/

		for (int i = 0; i < plen; i++) {
			if (strP[i] == 'R') {
				rev *= -1;
			}
			else {
				if (x.empty()) {
					result = 0;
					break;
				}
				else {
					if (rev == 1) {
						x.pop_front();
					}
					else {
						x.pop_back();
					}
				}
			}

			/*switch (strP[i])
			{
			case 'R':
				rev *= -1;
				break;
			case 'D':
				if (x.empty()) {
					result = 0;
					break;
				}
				else {
					if (rev == 1) {
						x.pop_front();
					}
					else {
						x.pop_back();
					}
				}
				break;
			}*/
		}

		int len = x.size();

		if (result == 1) {
			if (rev == 1) {
				cout << "[";
				for (int i = 0; i < len; i++) {
					cout << x.front();
					x.pop_front();
					if (!x.empty()) {
						cout << ",";
					}

				}
				cout << "]" << endl; 
			}
			else {
				cout << "[";
				for (int i = 0; i < len; i++) {
					cout << x.back();
					x.pop_back();
					if (!x.empty()) {
						cout << ",";
					}

				}
				cout << "]" << endl;
			}
			/*if (rev == -1) {
				reverse(x.begin(), x.end());
			}
			cout << "[";
			for (int i = 0; i < len; i++) {
				cout << x.front();
				x.pop_front();
				if (!x.empty()) {
					cout << ",";
				}
				
			}
			cout << "]" << endl;*/
		}
		else {
			cout << "error" << endl;
		}
		x.clear();
	}

	return 0;
}

//#include <iostream>
//#include <deque>
//#include <string>
//
//using namespace std; 
//int main() {
//	std::ios::sync_with_stdio(false); bool chk; // true이면 앞에서 false이면 뒤에서 
//	bool ok;
//	int C, n; cin >> C;
//	while (C--) {
//		string cmd = "";
//		string input_arr = "";
//		deque<int> dq;
//		ok = true;
//		chk = true;
//		cin >> cmd;
//		cin >> n;
//		cin >> input_arr; // 배열을 담을 문자열 
//		string num = "";
//		for (int i = 0; i < input_arr.length(); ++i) {
//			// deque로 만들기
//			if (input_arr[i] == ',' || input_arr[i] == ']') {
//				if (input_arr[i - 1] == '[')
//					break;
//				dq.push_back(atoi(num.c_str()));
//				num = "";
//			}
//			else if (input_arr[i] != '[' && input_arr[i] != ']')
//				num += input_arr[i];
//		}
//		for (int i = 0; i < cmd.length(); ++i) {
//			// 변환 
//			if (cmd[i] == 'R') {
//				chk = !chk;
//			}
//			else {
//				if (dq.size() <= 0) {
//					ok = false;
//					break;
//				}
//				if (chk)
//					dq.pop_front();
//				else
//					dq.pop_back();
//			}
//		} // 출력해주는 함수 
//		if (ok) {
//			int size = dq.size();
//			cout << "[";
//			for (int i = 0; i < size; ++i) {
//				if (chk) {
//					cout << dq.front();
//					dq.pop_front();
//				}
//				else {
//					cout << dq.back();
//					dq.pop_back();
//				}
//				if (!dq.empty())
//					cout << ",";
//			} cout << "]" << endl;
//		}
//		else {
//			cout << "error" << endl;
//		}
//		dq.clear();
//	}
//	return 0;
//}


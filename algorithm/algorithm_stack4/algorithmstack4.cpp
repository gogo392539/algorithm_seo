#include "stack_seo.h"
#include <string>
#include <math.h>


using namespace std;

int main()
{
	s_stack<string> s;
	//s_stack<int> in;
	string pLetters;
	int sum = 0;
	int temp = 0;
	string tmp;

	while (1) {
		cin >> pLetters;
		if (pLetters.length() >= 2 || pLetters.length() <= 30) {
			break;
		}
	}
	

	for (int i = 0; i < pLetters.length(); i++) {
		
		switch (pLetters[i]) {
		case '(':
			tmp = pLetters[i];
			s.push(tmp);
			tmp = "";
			break;
		case '[':
			tmp = pLetters[i];
			s.push(tmp);
			tmp = "";
			break;
		case ')':
			while (1) {
				if ((s.empty()) || s.top() == "[") {
					cout << 0 << endl;
					return -1;
				}
				else if (s.top() == "(") {
					s.pop();
					if (temp == 0) {
						s.push("2");
					}
					else {
						temp *= 2;
						s.push(to_string(temp));
						temp = 0;
					}
					break;
				}
				else {		//정수 인 경우
					temp += atoi(s.pop().c_str());
				}
			}				
			break;
		case ']':
			while (1) {
				if ((s.empty()) || s.top() == "(") {
					cout << 0 << endl;
					return -1;
				}
				else if (s.top() == "[") {
					s.pop();
					if (temp == 0) {
						s.push("3");
					}
					else {
						temp *= 3;
						s.push(to_string(temp));
						temp = 0;
					}
					break;
				}
				else {		//정수 인 경우
					temp += atoi(s.pop().c_str());
				}
			}	
			break;
		}
	}

	while (!s.empty()) {
		if (s.top() == "(" || s.top() == "[") {
			cout << 0 << endl;
			return -1;
		}
		else {
			sum += atoi(s.pop().c_str());
		}
	}

	cout << sum << endl;

    return 0;
}


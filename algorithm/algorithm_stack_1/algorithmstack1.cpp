#include "stack_seo.h"
#include <string>


using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	s_stack<int> s;
	
	int instructionCount;
	while (1) {
		cin >> instructionCount;
		if (instructionCount >= 1 || instructionCount <= 100000)
			break;
	}

	string str;
	int value;
	for (int i = 0; i < instructionCount; i++) {
		cin >> str;
		
		if (str == "push") {
			cin >> value;
			s.push(value);
		}
		else if (str == "pop") {
			cout << s.pop() << endl;
		}
		else if (str == "size") {
			cout << s.size() << endl;
		}
		else if (str == "empty") {
			cout << s.empty() << endl;
		}
		else if (str == "top") {
			cout << s.top() << endl;
		}

	}
    return 0;
}


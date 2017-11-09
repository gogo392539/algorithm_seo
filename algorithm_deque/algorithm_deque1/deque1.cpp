#include "seo_deque.h"

#include <string>

using namespace std;

int main(void) {
	s_Deque<int> d;
	string str;
	int value;
	int count;
	cin >> count;

	for (int i = 0; i < count; i++) {
		cin >> str;
		if (str == "push_front") {
			cin >> value;
			d.push_front(value);
		}
		else if (str == "push_back") {
			cin >> value;
			d.push_back(value);
		}
		else if (str == "pop_front") {
			cout << d.pop_front() << endl;
		}
		else if (str == "pop_back") {
			cout << d.pop_back() << endl;
		}
		else if (str == "size") {
			cout << d.size() << endl;
		}
		else if (str == "empty") {
			cout << d.empty() << endl;
		}
		else if (str == "front") {
			cout << d.front() << endl;
		}
		else if (str == "back") {
			cout << d.back() << endl;
		}
	}


	return 0;
}
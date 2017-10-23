#include "queue_seo.h"

#include <string>

using namespace std;

int main()
{
	s_queue<int> q;
	string str;
	int value;
	int count;
	cin >> count;

	for (int i = 0; i < count; i++) {
		cin >> str;
		if (str == "push") {
			cin >> value;
			q.push(value);
		}
		else if (str == "pop") {
			cout << q.pop() << endl;
		}
		else if (str == "size") {
			cout << q.size() << endl;
		}
		else if (str == "empty") {
			cout << q.empty() << endl;
		}
		else if (str == "front") {
			cout << q.front() << endl;
		}
		else if (str == "back") {
			cout << q.back() << endl;
		}
	}


    return 0;
}


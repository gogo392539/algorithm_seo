#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	queue<int> q;
	int count;
	int N;
	int M;
	int temp;

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}
	count = 1;
	cout << "<";
	while (!q.empty()) {
		if (count != M) {
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		else {
			cout << q.front();
			q.pop();
			count = 0;
			if (!q.empty()) {
				cout << ", ";
			}
		}
		count++;
	}
	cout << ">";

	return 0;
}
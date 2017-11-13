#include<iostream>
#include<deque>

using namespace std;

int main(void) {
	deque<int> d;
	int N;
	int M;
	int pos[50];
	int tempPos;
	int count = 0;
	int result = 0;

	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; i++) {
		d.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		cin >> pos[i];
	}

	for (int i = 0; i < M; i++) {
		tempPos = pos[i];

		if (tempPos == 1) {
			d.pop_front();
			for (int j = i + 1; j < M; j++) {
				pos[j]--;
			}
		}
		else {
			if (tempPos <= ((d.size() / 2) + 1)) {
				while (tempPos != 1) {
					int tmp = d.front();
					d.pop_front();
					d.push_back(tmp);
					count++;
					tempPos--;
					for (int j = i + 1; j < M; j++) {
						pos[j]--;
						if (pos[j] == 0) {
							pos[j] = d.size();
						}
					}
				}
				d.pop_front();
				for (int j = i + 1; j < M; j++) {
					pos[j]--;
				}
			}
			else {
				while (1) {
					int tmp = d.back();
					d.pop_back();
					d.push_front(tmp);
					count++;
					tempPos++;
					for (int j = i + 1; j < M; j++) {
						pos[j]++;
						if (pos[j] == (d.size() + 1)) {
							pos[j] = 1;
						}
					}
					if (tempPos == (d.size() + 1)) {
						tempPos = 1;
						break;
					}
				}
				d.pop_front();
				for (int j = i + 1; j < M; j++) {
					pos[j]--;
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}
#include <iostream>

using namespace std;

int main(void) {
	long long int num;
	int n0 = 0;
	int n1 = 1;
	int n2;
	cin >> num;

	if (num >= 1500000) {
		num = num % 1500000;
	}

	if (num == 0) {
		cout << 0 << endl;
		return 0;
	}

	if (num == 1) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 2; i <= num; i++) {
		n2 = n0 % 1000000 + n1 % 1000000;
		n0 = n1 % 1000000;
		n1 = n2;
	}
	cout << n2 % 1000000 << endl;

	return 0;
}
#include <iostream>

using namespace std;

int fibonacci(int n, int &nZero, int &nOne);

int main(void) {
	int nZeroCount = 0;
	int nOneCount = 0;
	int nTestCase = 0;
	int nData = 0;

	cin >> nTestCase;

	while (nTestCase > 0) {
		cin >> nData;

		nZeroCount = 0;
		nOneCount = 0;

		fibonacci(nData, nZeroCount, nOneCount);
		cout << nZeroCount << " " << nOneCount << endl;

		nTestCase--;
	}

	

	return 0;
}

int fibonacci(int n, int &nZero, int &nOne) {
	if (n == 0) {
		nZero++;
		return 0;
	}
	else if (n == 1) {
		nOne++;
		return 1;
	}
	else {
		return fibonacci(n - 1, nZero, nOne) + fibonacci(n - 2, nZero, nOne);
	}

}
#include <iostream>

using namespace std;

long long int Factorial(int nData, int nCount);

int main(void) {
	int nN = 0;
	int nK = 0;
	int nCount = 0;
	long long int nResult = 10000000000000000000;
	long long int nResultN = 0;
	long long int nResultK = 0;

	cin >> nN;
	cin >> nK;

	nCount = nK;
	if (nN < nK) {
		cout << 0 << endl;
	}
	else if (nK < 0) {
		cout << 0 << endl;
	}
	else {
		nResultN = Factorial(nN, nCount);
		nResultK = Factorial(nK, nCount);
		nResult = nResultN / nResultK;

	}

	cout << nResult << endl;
	return 0;
}

long long int Factorial(int nData, int nCount) {
	long long int nResult = 1;
	for (int i = 0; i < nCount; i++) {
		nResult *= nData--;
	}

	return nResult;
}
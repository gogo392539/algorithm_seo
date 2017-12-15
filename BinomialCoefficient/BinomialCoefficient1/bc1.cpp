#include <iostream>

using namespace std;

int Factorial(int nData);

int main(void) {
	int nNaturalNumber = 0;
	int nInteger = 0;
	int nResult = 0;

	cin >> nNaturalNumber;
	cin >> nInteger;

	if (nNaturalNumber < nInteger) {
		cout << 0 << endl;
	}
	else if (nInteger < 0) {
		cout << 0 << endl;
	}
	else {
		nResult = Factorial(nNaturalNumber) / (Factorial(nInteger)*Factorial(nNaturalNumber - nInteger));
	}

	cout << nResult << endl;


	return 0;
}

int Factorial(int nData) {
	int nResult = 1;
	for (int i = nData; i > 0; i--) {
		nResult *= i;
	}

	return nResult;
}
#include <iostream> 

using namespace std;

unsigned long long int Factorial(double nNaturalNumber, double nInteger);

int main(void) {
	int nNaturalNumber = 0;
	int nInteger = 0;
	unsigned long long int nResult = 0;

	cin >> nNaturalNumber;
	cin >> nInteger;

	if (nNaturalNumber < nInteger) {
		cout << 0 << endl;
	}
	else if (nInteger < 0) {
		cout << 0 << endl;
	}
	else {
		nResult = Factorial(nNaturalNumber, nInteger);
	}

	cout << nResult << endl;

	return 0;
}

unsigned long long int Factorial(double nNaturalNumber, double nInteger) {
	double nResult = 1;
	unsigned long long int nResult1 = 0;
	while (nInteger > 0) {
		nResult *= ((nNaturalNumber--) / (nInteger--));
	}

	nResult1 = (unsigned long long int)nResult % 10007;

	return nResult1;
}


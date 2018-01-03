#include <iostream> 
#include <string.h>

using namespace std;

long long int Factorial(int nN, int nK);

int arBC[1001][1001];


int main(void) {

	memset(arBC, -1, sizeof(arBC));

	arBC[0][0] = 1;
	arBC[1][0] = 1;
	arBC[1][1] = 1;

	int nN = 0;
	int nK = 0;

	cin >> nN >> nK;

	cout << Factorial(nN, nK) << endl;

	return 0;
}

long long int Factorial(int nN, int nK) {

	if (arBC[nN][nK] != -1) {
		return arBC[nN][nK];
	}

	if (nK == 0 || nK == nN) {
		return 1;
	}

	arBC[nN][nK] = (Factorial(nN - 1, nK - 1) + Factorial(nN - 1, nK)) % 10007;

	return arBC[nN][nK];
}
#include <iostream>

using namespace std;


//포기 못풀겠다...
int main(void) {
	double dN = 0.0;
	double dK = 0.0;
	int nDivisor = 0;
	int nResultN = 0;
	int nResultK = 0;
	int nResult = 0;
	double dResult = 0.0;
	int nCount = 0;

	cin >> dN;
	cin >> dK;

	nDivisor = 10007;
	nResultN = 1;
	nResultK = 1;
	nResult = 1;
	dResult = 1.0;
	nCount = (int)dK;
	for (int i = 0; i < nCount; i++) {
		dResult *= (dN / dK);
		nResult = (int)dResult;
		if ((dResult - nResult) == 0) {
			dResult = nResult % nDivisor;
		}
		dN--;
		dK--;
	}
	cout << (int)dResult << endl;
	return 0;
}


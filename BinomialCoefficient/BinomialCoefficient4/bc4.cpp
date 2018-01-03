#include <iostream>

using namespace std;

int main(void) {
	int nN = 0;
	int nCount = 0;
	int nResult = 0;

	cin >> nN;

	nCount = nN;
	nResult = 1;
	if (nN == 0) {
		cout << nResult << endl;
	}
	else {
		for (int i = 0; i < nCount; i++) {
			nResult *= nN--;
		}
		cout << nResult << endl;
	}

	

	return 0;
}
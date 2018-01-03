#include<iostream>

using namespace std;

int main(void) {
	int nN = 0;
	int nCount = 0;
	int nResult = 0;
	int nRest = 0;
	
	cin >> nN;

	nCount = nN;

	for (int i = 0; i < nCount; i++) {
		if (nN % 5 == 0) {
			nResult++;
			nRest = nN / 5;
			while (1) {
				if (nRest % 5 == 0) {
					nResult++;
					nRest = nRest / 5;
				}
				else {
					break;
				}
			}
		}
		nN--;
	}
	

	cout << nResult << endl;

	return 0;
}
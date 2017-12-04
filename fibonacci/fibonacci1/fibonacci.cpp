#include <iostream>

using namespace std;

int main(void) {

	int num;
	long long int fibonacciArray[91];
	int n1 = 0;
	int n2 = 1;
	
	cin >> num;

	fibonacciArray[0] = 0;
	fibonacciArray[1] = 1;

	if (num == 0) {
		cout << fibonacciArray[n1] << endl;
	}
	else if (num == 1) {
		cout << fibonacciArray[n2] << endl;
	}

	for (int i = 2; i <= 90; i++) {
		fibonacciArray[i] = fibonacciArray[n1] + fibonacciArray[n2];
		n1++;
		n2++;

		if (num == i) {
			cout << fibonacciArray[i] << endl;
			break;
		}
	}

	return 0;
}




//int fibonacciNum(int num);
//
//int main(void) {
//
//	int num;
//	cin >> num;
//	cout << fibonacciNum(num) << endl;
//
//	return 0;
//}
//
//int fibonacciNum(int num) {
//	if (num == 0) {
//		return 0;
//	}
//	else if (num == 1) {
//		return 1;
//	}
//	else {
//		return fibonacciNum(num - 1) + fibonacciNum(num - 2);
//	}
//}
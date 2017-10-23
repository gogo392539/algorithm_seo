#include "stack_seo.h"
#include <Windows.h>

#pragma comment(lib, "winmm.lib")

using std::cout;
using std::endl;
using std::cin;

void createSequence(int count);

int main()
{
	//DWORD st = timeGetTime();
	std::ios::sync_with_stdio(false);

	int count;
	while (1) {
		cin >> count;
		if (count >= 1 || count <= 100000)
			break;
	}
	createSequence(count);

	//DWORD et = timeGetTime();
	//cout << et - st << endl;

    return 0;
}

//void createSequence(int count) {
//	s_stack<int> s;
//
//	int sequence;
//	char outputResult[200002];
//
//	int j = 1, o = 0;
//	int flag = 0;
//	int top = 0;
//
//	for (int i = 0; i < count; i++) {
//		scanf("%d", &sequence);
//		if (sequence > top) {
//			for (int n = top; n < sequence; n++) {
//				s.push(n + 1);
//				outputResult[o++] = '+';
//			}
//		}
//		else if (sequence < s.top()) {
//			cout << "NO" << endl;
//			exit(1);
//		}
//
//		s.pop();
//		outputResult[o++] = '-';
//		if (top < sequence)
//			top = sequence;
//	}
//
//	
//	for (int i = 0; i < o; i++)
//		printf("%c \n", outputResult[i]);
//}

void createSequence(int count) {
	s_stack<int> s;

	int* sequence = new int[count];
	char outputResult[200002];

	for (int i = 0; i < count; i++) {
		scanf("%d", &sequence[i]);
	}

	int i = 0, j = 1, o = 0;
	int flag = 0;


	while (i < count) {
		if (sequence[i] > s.top()) {
			s.push(j);
			outputResult[o++] = '+';
			j++;
		}
		else {
			if (s.top() == sequence[i]) {
				s.pop();
				outputResult[o++] = '-';
				i++;
			}
			else {
				cout << "NO" << endl;
				flag = -1;
				break;

			}
		}
	}

	if (flag != -1) {
		for (int i = 0; i < o; i++)
			printf("%c \n", outputResult[i]);
	}

	delete[]sequence;
}
#include "stack_seo.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	std::ios::sync_with_stdio(false);

	s_stack<char> s;

	int psLen;
	int count;
	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		
		string ps;
		psLen = 0;

		while (1) {
			cin >> ps;
			psLen = ps.length();
			if (psLen >= 2 || psLen <= 50)
				break;
		}

		for (int j = 0; j < psLen; j++) {
			if (ps[j] == '(')
				s.push(ps[j]);
			else {
				if (s.empty()) {
					printf("NO \n");
					break;
				}
				else {
					s.pop();
				}
			}

			if (j == (psLen - 1)) {
				if (s.empty()) {
					printf("YES \n");
				}
				else {
					printf("NO \n");
				}
			}
		}
		while (!s.empty()) {
			s.pop();
		}
	}

    return 0;
}


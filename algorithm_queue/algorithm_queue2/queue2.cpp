#include <iostream>
#include <deque>
#include <stack>

using namespace std;

void DFSFunc(int s);
void BFSFunc(int s);

int adjacencyMatrix[1000][1000] = { 0 };
int vCount;	//������ ����
int eCount; //������ ����
int startVertex;
bool DFSisVisits[1000] = { false };
bool BFSisVisits[1000] = { false };

int main(void)
{
	int e1, e2;

	//������ ���� �Է�
	while (1) {
		cin >> vCount;
		if (vCount >= 1 && vCount <= 1000)
			break;
	}
	//������ ���� �Է�
	while (1) {
		cin >> eCount;
		if (eCount >= 1 && eCount <= 10000)
			break;
	}
	//Ž�� ���� ��ġ �Է�
	cin >> startVertex;

	//���� �Է�
	for (int i = 0; i < eCount; i++) {
		cin >> e1;
		cin >> e2;

		adjacencyMatrix[e1 - 1][e2 - 1] = 1;
		adjacencyMatrix[e2 - 1][e1 - 1] = 1;
	}
	cout << startVertex << " ";
	DFSFunc(startVertex);
	cout << endl;
	
	cout << startVertex << " ";
	BFSFunc(startVertex);
	cout << endl;

	return 0;
}

void DFSFunc(int s) {
	/*
	//��ȸ ���
	DFSisVisits[s - 1] = true;
	
	for (int i = 1; i <= vCount; i++) {
		if (adjacencyMatrix[s - 1][i - 1] == 1 && !DFSisVisits[i - 1]) {
			cout << i << " ";
			DFSFunc(i);
		}
	}*/

	//���� ���
	stack<int> st;
	DFSisVisits[s - 1] = true;
	st.push(s);
	int ss;
	bool flag;

	while (!st.empty()) {
		ss = st.top();
		flag = false;
		for (int i = 1; i <= vCount; i++) {
			if (adjacencyMatrix[ss - 1][i-1] == 1 && !DFSisVisits[i-1]) {
				cout << i << " ";
				st.push(i);
				DFSisVisits[i - 1] = true;
				flag = true;
				break;
			}
		}
		if (!flag) {
			st.pop();
		}
	}
}

void BFSFunc(int s) {
	BFSisVisits[s - 1] = true;
	deque<int> d;
	d.push_front(s);

	while (!d.empty()) {
		s = d.back();
		d.pop_back();
		for (int i = 1; i <= vCount; i++) {
			if (adjacencyMatrix[s - 1][i - 1] == 1 && !BFSisVisits[i - 1]) {
				cout << i << " ";
				BFSisVisits[i - 1] = true;
				d.push_front(i);
			}
		}
	}

}
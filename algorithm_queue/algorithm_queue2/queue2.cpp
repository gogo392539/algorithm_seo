#include <iostream>
#include <deque>

using namespace std;

void DFSFunc(int s);
void BFSFunc(int s);

int adjacencyMatrix[1000][1000] = { 0 };
int vCount;	//정점의 개수
int eCount; //간선의 개수
int startVertex;
bool DFSisVisits[1000] = { false };
bool BFSisVisits[1000] = { false };

int main(void)
{
	int e1, e2;

	//정점의 개수 입력
	while (1) {
		cin >> vCount;
		if (vCount >= 1 && vCount <= 1000)
			break;
	}
	//간선의 개수 입력
	while (1) {
		cin >> eCount;
		if (eCount >= 1 && eCount <= 10000)
			break;
	}
	//탐색 시작 위치 입력
	cin >> startVertex;

	//간선 입력
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
	DFSisVisits[s - 1] = true;
	
	for (int i = 1; i <= vCount; i++) {
		if (adjacencyMatrix[s - 1][i - 1] == 1 && !DFSisVisits[i - 1]) {
			cout << i << " ";
			DFSFunc(i);
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
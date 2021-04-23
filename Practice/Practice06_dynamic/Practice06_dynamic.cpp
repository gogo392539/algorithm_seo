// Practice06_dynamic.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

//11052 : 카드 구매하기 2
int fn_dynamic_16194();

//11052 : 카드 구매하기
int fn_dynamic_11052();

//9095 : 1, 2, 3 더하기
int fn_dynamic_9095();

//11727 : 2 * n 타일링 2
int fn_dynamic_11727();

//11726 : 2 * n 타일링
long long g_nTile[1001] = { 0, };
int fn_dynamic_11726();
long long fn_dynamic_11726_recursive(int nInput);


//1463 : 1로 만들기
int g_arD[1000001];
int fn_dynamic_make_one();
int fn_dynamic_make_one_recursive(int nInput);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//fn_dynamic_make_one();
	//fn_dynamic_11726();
	//fn_dynamic_11727();
	//fn_dynamic_9095();
	//fn_dynamic_11052();
	fn_dynamic_16194();

	return 0;
}

int fn_dynamic_16194()
{
	int nN = 0;

	cin >> nN;

	vector<int> vPrica(nN + 1);
	vector<int> vMin(nN + 1);

	for (int i = 1; i <= nN; i++) {
		cin >> vPrica[i];
		vMin[i] = -1;
	}

	for (int i = 1; i <= nN; i++) {
		for (int j = 1; j <= i; j++) {
			if (vMin[i] == -1 || vMin[i] > vMin[i - j] + vPrica[j]) {
				vMin[i] = vMin[i - j] + vPrica[j];
			}
		}
	}


	cout << vMin[nN] << "\n";

	return 0;
}

int fn_dynamic_11052()
{
	int nN = 0;

	cin >> nN;

	vector<int> vPrice(nN + 1);
	vector<int> vMax(nN + 1);

	for (int i = 1; i <= nN; i++) {
		cin >> vPrice[i];
	}

	for (int i = 1; i <= nN; i++) {
		for (int j = 1; j <= i; j++) {
			vMax[i] = max(vMax[i], vMax[i - j] + vPrice[j]);
		}
	}

	cout << vMax[nN] << "\n";

	return 0;
}

int fn_dynamic_9095()
{
	int nCase = 0;
	int arData[12] = { 0, };
	
	cin >> nCase;

	vector<int> vList(nCase);

	arData[1] = 1;
	arData[2] = 2;
	arData[3] = 4;

	for (int i = 4; i <= 11; i++) {
		arData[i] = arData[i - 1] + arData[i - 2] + arData[i - 3];
	}

	for (int i = 0; i < nCase; i++) {
		cin >> vList[i];
	}

	for (int i = 0; i < nCase; i++) {
		cout << arData[vList[i]] << "\n";
	}

	return 0;
}

int fn_dynamic_11727()
{
	int nN = 0;
	int arTile[1001] = { 0, };

	cin >> nN;

	arTile[1] = 1;
	arTile[2] = 3;

	for (int i = 3; i <= nN; i++) {
		int nTmp = arTile[i - 1] + (2 * arTile[i - 2]);
		arTile[i] = nTmp % 10007;
	}
	
	cout << arTile[nN] << "\n";;

	return 0;
}

int fn_dynamic_11726()
{
	int nN = 0;
	long long nResult = 0;

	cin >> nN;

	nResult = fn_dynamic_11726_recursive(nN);

//	nResult %= 10007;
	cout << nResult << "\n";

	return 0;
}

long long fn_dynamic_11726_recursive(int nInput)
{
	if (nInput == 1) {
		g_nTile[nInput] = 1;
		return 1;
	}

	if (nInput == 2) {
		g_nTile[nInput] = 2;
		return 2;
	}

	if (g_nTile[nInput] > 0) {
		return g_nTile[nInput];
	}

	long long nSum = 0;
	if (nInput - 2 > 0) {
		nSum += fn_dynamic_11726_recursive(nInput - 2) % 10007;
	}
	
	if (nInput - 1 > 0) {
		nSum += fn_dynamic_11726_recursive(nInput - 1) % 10007;
	}
	g_nTile[nInput] = nSum % 10007;

	return g_nTile[nInput];
}

int fn_dynamic_make_one()
{
	int nX = 0;
	int nResult = 0;

	cin >> nX;

	nResult = fn_dynamic_make_one_recursive(nX);

	cout << nResult << "\n";

	return 0;
}

int fn_dynamic_make_one_recursive(int nInput)
{
	if (nInput == 1) {
		return 0;
	}

	if (g_arD[nInput] > 0) {
		return g_arD[nInput];
	}

	g_arD[nInput] = fn_dynamic_make_one_recursive(nInput - 1) + 1;

	if (nInput % 2 == 0) {
		int nTmp = fn_dynamic_make_one_recursive(nInput / 2) + 1;
		if (nTmp < g_arD[nInput]) {
			g_arD[nInput] = nTmp;
		}
	}

	if (nInput % 3 == 0) {
		int nTmp = fn_dynamic_make_one_recursive(nInput / 3) + 1;
		if (nTmp < g_arD[nInput]) {
			g_arD[nInput] = nTmp;
		}
	}

	return g_arD[nInput];
}

#include <string>
#include <iostream>

using namespace std;
string e, digits; //e는 현재계란가격, digits는 e의 원소들을 '정렬'한 형태.
int n, m; //n은 계란가격 e의 자릿수.
int main () {
	int C;
	cin >> C;
	cin >> e;
	cin >> m;

	for (int c = 0; c < C; c++) {
		for (int i = 0; i < getInput.size (); i++) {
			eggPrice[i] = getInput[i] - '0';
			orderedPlate[i] = eggPrice[i];
		}

		sort (orderedPlate, orderedPlate + getInput.size ());

		func1 (0);

		cout << result % 1000000007;
	}
}
#include <string>
#include <iostream>

using namespace std;
string e, digits; //e�� ����������, digits�� e�� ���ҵ��� '����'�� ����.
int n, m; //n�� ������� e�� �ڸ���.
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
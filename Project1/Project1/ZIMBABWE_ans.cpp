#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string e, digits, price; //e�� ����������, digits�� e�� ���ҵ��� '����'�� ����. string�� +�������� ���� ���� �� �ְ�, ���ĵ� ����.
int n, m; //n�� ������� e�� �ڸ���, m�� ��������-e�� m�� ������ٰ� �Ѵ�.
int sum=0;

bool taken[15];

void generate (string price, bool taken[]);
int main () {
	int C;
	cin >> C;
	cin >> e;
	cin >> m;

	string digits = sort (e.begin,e.end);
	

	return 0;
}
/*���ȣ���ϸ鼭 price-������������ĺ� �� �ϼ��ذ���. taken�� e�� �ڸ����� ���Ǿ��������θ� ����, �ϼ��Ǹ� ��Һ� ��, m�� ������� üũ �� ��.*/
void generate (string price, bool taken[]) {
	/*digits�� ���� ����ϴ� ���� ����� �ڸ� �� '�ٷ� �� �ڸ���'
	1. ���ų� 2.�̹� �ڸ����� �ٸ��ų� 3.�̹� ���ǰ� �������*/
	
	//������� - �ϼ��� ��.
	if(price.size == n)
}
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string e, digits, price; //e�� ����������, digits�� e�� ���ҵ��� '����'�� ����. string�� +�������� ���� ���� �� �ְ�, ���ĵ� ����.
int n, m; //n�� �������e �� �ڸ���, m�� ��������-e�� m�� ������ٰ� �Ѵ�.
int sum=0;

const int MOD = 1000000007;
bool taken[15];

int cache[1<<14][20][2]; //taken,mod,less

void generate (string price, bool taken[]);
int main () {
	int C;
	cin >> C;
	cin >> e;
	cin >> m;

	string digits = sort (e.begin,e.end);
	//generate(price,taken);

	return 0;
}
/*���ȣ���ϸ鼭 price-������������ĺ� �� �ϼ��ذ���. taken�� e�� �ڸ����� ���Ǿ��������θ� ����, �ϼ��Ǹ� ��Һ� ��, m�� ������� üũ �� ��.*/
void generate (string price, bool taken[]) {
	/*digits�� ���� ����ϴ� ���� ����� �ڸ� �� '�ٷ� �� �ڸ���'
	1. ���ų� 2.�̹� �ڸ����� �ٸ��ų� 3.�̹� ���ǰ� �������*/
	
	//������� - �ϼ��� ��.
	if (price.size == n) {
		//1
		if ((price < e) && stoi (price) % m == 0) {
			sum++;
			cout << price << endl;
			return;
		}
	}

	for(int i=0; i<n; i++) {
		if(!taken[i]) {
			/*digits�� ���� ����ϴ� ���� ����� �ڸ� �� '�ٷ� �� �ڸ���'
			1. ���ų� 2.�̹� �ڸ����� �ٸ��ų� 3.�̹� ���ǰ� �������*/
			if(i == 0 || digits[i-1]!= digits[i] || taken[i-1]) {
				taken[i] = true;
				generate(price+digits[i], taken);
				taken[i] = false;
			}
		}
	}
}

/*
price�� 1.n�ڸ����� ��� �ϼ��ɶ�, 2.m�� ����ΰ�? 3.e���� ���� ���ΰ�?�� �������� Ȯ���ѵ� �� ���ΰ� �����ȴ�.
�� ���� ��쿡 ���ǹǷ� ������ ���, 
1.taken��ȸ 2.price�� m���� ���� �������� ���� 3.e���� �׻� ������ or Ŀ�� �� �ִ��� ���θ� ����.

*/
int generate_memoi(int index, int taken, int mod, int less) {
	//n�ڸ��� �� ����.
	if(index == n)
		return (less && mod == 0 ? 1:0);

	int &ret = cache[taken][mod][less];
	
	//
	if(ret != -1) return ret;
	ret = 0; //
	
	for(int next = 0; next < n; next++) {
		if(taken & (1<<next) == 0) {
			
		}
	}
}
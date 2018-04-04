#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string e, digits, price; //e는 현재계란가격, digits는 e의 원소들을 '정렬'한 형태. string은 +연산으로 쉽게 더할 수 있고, 정렬도 간편.
int n, m; //n은 계란가격 e의 자릿수, m은 사탕가격-e는 m의 배수였다고 한다.
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
/*재귀호출하면서 price-원래계란가격후보 를 완성해간다. taken은 e의 자릿수가 사용되었는지여부를 저장, 완성되면 대소비교 후, m의 배수여부 체크 후 끝.*/
void generate (string price, bool taken[]) {
	/*digits의 수를 사용하는 경우는 사용할 자릿 수 '바로 앞 자리가'
	1. 없거나 2.이번 자릿수랑 다르거나 3.이미 사용되고 남은경우*/
	
	//기저사례 - 완성된 후.
	if(price.size == n)
}
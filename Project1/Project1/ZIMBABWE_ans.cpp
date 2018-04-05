#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string e, digits, price; //e는 현재계란가격, digits는 e의 원소들을 '정렬'한 형태. string은 +연산으로 쉽게 더할 수 있고, 정렬도 간편.
int n, m; //n은 계란가격e 의 자릿수, m은 사탕가격-e는 m의 배수였다고 한다.
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
/*재귀호출하면서 price-원래계란가격후보 를 완성해간다. taken은 e의 자릿수가 사용되었는지여부를 저장, 완성되면 대소비교 후, m의 배수여부 체크 후 끝.*/
void generate (string price, bool taken[]) {
	/*digits의 수를 사용하는 경우는 사용할 자릿 수 '바로 앞 자리가'
	1. 없거나 2.이번 자릿수랑 다르거나 3.이미 사용되고 남은경우*/
	
	//기저사례 - 완성된 후.
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
			/*digits의 수를 사용하는 경우는 사용할 자릿 수 '바로 앞 자리가'
			1. 없거나 2.이번 자릿수랑 다르거나 3.이미 사용되고 남은경우*/
			if(i == 0 || digits[i-1]!= digits[i] || taken[i-1]) {
				taken[i] = true;
				generate(price+digits[i], taken);
				taken[i] = false;
			}
		}
	}
}

/*
price는 1.n자리수가 모두 완성될때, 2.m의 배수인가? 3.e보다 작은 수인가?의 세가지를 확인한뒤 답 여부가 결정된다.
세 가지 경우에 사용되므로 각각의 경우, 
1.taken조회 2.price를 m으로 나눈 나머지만 전달 3.e보다 항상 작은지 or 커질 수 있는지 여부만 전달.

*/
int generate_memoi(int index, int taken, int mod, int less) {
	//n자리수 다 만듦.
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
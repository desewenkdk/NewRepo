/**
	10844 쉬운계단수열
**/

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define q 1000000000

long cache[100][10] ={0}; //cache[p][m] : p번째 수가 m일때, p번째수 ~ N번째 수인 부분수열의 경우의 수
long result;

long N;

/**
* layer번째 수가 digit인 경우, 그 뒤로 몇가지 경우가 나오는 지 계산하는 함수.
**/
long num(int layer, int digit);

int main() {
	scanf("%d",&N);
	if(N == 1) {
		printf("9");
		return 0;
	}
	for(int i=1; i<=9; i++) {
		result += num(1,i);
		result %= q; //더한 뒤에 %를 한 번 더 취해준다.
	}
	printf("%d",result);
	return 0;
}


long num(int layer, int digit) {
	long ret = 0;
	
	//"N-1번째"가 0,9이면 N번째는 무조건 1가지씩만 가능, 나머지 경우, 무조건 2가지의 경우가 생긴다. 
	if(layer == N-1) {
		if(digit == 0 || digit == 9)
			return 1;
		else
			return 2;
	}

	if(cache[layer][digit] != 0) {
		return cache[layer][digit];
	}

	if(digit == 0) {
		//ret += 1 * num(layer+1, digit-1); 0,9의 경우는, 그 다음 수 가 1이거나 8인 경우 하나씩만 고려한다. 
		ret += num(layer+1, digit+1);
	}
	else if(digit == 9)
		ret += num(layer+1, digit-1);

	//나머지 경우, 현재 수 +1, 현재 수-1만 다음에 올 수 있다. 
	else {	
		ret += num(layer+1, digit-1);
		ret += num(layer+1, digit+1);
	}
	ret %= q; //수가 너무 커지므로 저장하기 전에 %를 한 번 취해준다.
	cache[layer][digit] = ret; //캐싱한다.
	return ret;
}

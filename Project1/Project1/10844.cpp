/**
	10844 �����ܼ���
**/

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define q 1000000000

long cache[100][10] ={0}; //cache[p][m] : p��° ���� m�϶�, p��°�� ~ N��° ���� �κм����� ����� ��
long result;

long N;

/**
* layer��° ���� digit�� ���, �� �ڷ� ��� ��찡 ������ �� ����ϴ� �Լ�.
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
		result %= q; //���� �ڿ� %�� �� �� �� �����ش�.
	}
	printf("%d",result);
	return 0;
}


long num(int layer, int digit) {
	long ret = 0;
	
	//"N-1��°"�� 0,9�̸� N��°�� ������ 1�������� ����, ������ ���, ������ 2������ ��찡 �����. 
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
		//ret += 1 * num(layer+1, digit-1); 0,9�� ����, �� ���� �� �� 1�̰ų� 8�� ��� �ϳ����� ����Ѵ�. 
		ret += num(layer+1, digit+1);
	}
	else if(digit == 9)
		ret += num(layer+1, digit-1);

	//������ ���, ���� �� +1, ���� ��-1�� ������ �� �� �ִ�. 
	else {	
		ret += num(layer+1, digit-1);
		ret += num(layer+1, digit+1);
	}
	ret %= q; //���� �ʹ� Ŀ���Ƿ� �����ϱ� ���� %�� �� �� �����ش�.
	cache[layer][digit] = ret; //ĳ���Ѵ�.
	return ret;
}

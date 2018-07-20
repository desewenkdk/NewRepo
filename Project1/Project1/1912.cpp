#include <stdio.h>
#include <vector>
#include <algorithm>

int inputs[100000];
int cache[100000]; // i번째 수를 포함하는 연속수열의 합 중 가장 큰 값
int max = -1001; //현재 가장 큰 값

int main() {
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&inputs[i]);

	for(int i=0; i<N; i++) {
		if(i==0)
			cache[0] = inputs[0];
		else {
			cache[i] = std::max(cache[i-1]+inputs[i], inputs[i]);
		}
	}
	return 0;
}
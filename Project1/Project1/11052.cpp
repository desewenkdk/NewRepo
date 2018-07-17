/**
	11052 붕어빵
**/

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

int cache[1001];
int ret;
int result;
int num_fish;
int pfishSet[1001];
/*
	붕어빵n개의 최대가격 = cache[n]
	붕어빵s개 세트의 가격 = pfishSet[s]
	
	이 때, 붕어빵 N개의 최대 가격은, cache[N] = MAX(cache[i] + pfishSet[N-i])로 결정된다.(i : 1 ~ N-1)
*/

//int pSum(int num,int sum);
//Iterable하게 구현하는 것이 훨씬 간단하고 쉽게 만들어진다.(점화식)
int main() {
	scanf("%d",&num_fish);
	cache[0] = -1;
	pfishSet[0] = -1;
	
	for(int i=1; i<=num_fish; i++) {
		scanf("%d",&pfishSet[i]);
		cache[i] = -1;
	}
	cache[1] = pfishSet[1];
	ret = -1;


	for(int i=2; i<=num_fish; i++) {
		int cand = pfishSet[i];
		for(int j=1; j<i; j++) { // for문이 수행되면서, 가격이 최대가 되는 조합을 이끌어낸다. 
			//		result = pSum(i,pfishSet[i]);
			cand = std::max(cand, cache[j] + pfishSet[i-j]);
		}
		cache[i] = cand; // i개에서의 최대가격이 되는 경우를 저장, line35~37에서 가져와 사용한다.
	}
	printf("%d", cache[num_fish]);
	return 0;
}














//
//
//
//
//
//int pSum(int num, int sum) {
//	if(num == num_fish) {
//		(sum > cache[num] ? ret = sum : ret = cache[num]);
//		cache[num] = ret;
//		return ret;
//	}
//
//	if(cache[num] != -1) {
//		return cache[num];
//	}
//
//	for(int i = 1; i<=(num_fish - num); i++) {
//		//int tmpSum = std::max(cache[num+i],sum+pfishSet[i]);
//		ret = std::max(ret,cache[num] + pSum(num+i, sum+pfishSet[i]));
//	}
//	cache[num] = ret;
//	return ret;
//}
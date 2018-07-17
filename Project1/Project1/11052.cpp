/**
	11052 �ؾ
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
	�ؾn���� �ִ밡�� = cache[n]
	�ؾs�� ��Ʈ�� ���� = pfishSet[s]
	
	�� ��, �ؾ N���� �ִ� ������, cache[N] = MAX(cache[i] + pfishSet[N-i])�� �����ȴ�.(i : 1 ~ N-1)
*/

//int pSum(int num,int sum);
//Iterable�ϰ� �����ϴ� ���� �ξ� �����ϰ� ���� ���������.(��ȭ��)
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
		for(int j=1; j<i; j++) { // for���� ����Ǹ鼭, ������ �ִ밡 �Ǵ� ������ �̲����. 
			//		result = pSum(i,pfishSet[i]);
			cand = std::max(cand, cache[j] + pfishSet[i-j]);
		}
		cache[i] = cand; // i�������� �ִ밡���� �Ǵ� ��츦 ����, line35~37���� ������ ����Ѵ�.
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
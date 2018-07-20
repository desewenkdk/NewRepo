#include <stdio.h>
#include <algorithm>
#include <vector>
int cache[2][100001]; //[i][j]번째 스티커를 떼는 순간까지 누적된 점수의 최대값(오른쪽에서부터 계산된 값)
int stickers[2][100001];

int N;
std::vector<int> ans;
/**
* (i,j)번째 스티커를 제거한 경우에 가능한 경우 중 가장 큰 합을 가져온다.
**/
int partialSum(int i, int j);
int main() {
	int testcase;
	scanf("%d", &testcase);

	for(int i=0; i<testcase; i++) {
		scanf("%d", &N);
		for(int i=0; i<2; i++)
			for(int j=0; j<N; j++) {
				scanf("%d", &stickers[i][j]);
				cache[i][j] = -1;    //cache배열 초기화
			}
		int result = -1;
		result = std::max(result, partialSum(0, 0));
		result = std::max(result, partialSum(1, 0));
		ans.push_back(result);
	}

	for (int val: ans)
		printf("%d\n",val);
	return 0;
}

int partialSum(int i, int j) {
	int ret = -1;
	if(j == N) {
		return stickers[i][j];
	}

	if(cache[i][j] != -1)
		return cache[i][j];

	if(i == 0) {
		ret = stickers[i][j] + partialSum(1, j+1);
		if(j+1 < N)
			ret = std::max(ret,stickers[i][j] + partialSum(1,j+2));
	}
	else if(i == 1) {
		ret = stickers[i][j] + partialSum(0, j+1);
		if(j+1 < N)
			ret = std::max(ret, stickers[i][j] + partialSum(0, j+2));
	}
	cache[i][j] = ret;
	return ret;
}
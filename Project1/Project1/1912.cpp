#include <stdio.h>
#include <vector>
#include <algorithm>

int inputs[100000];
int cache[100000]; // i��° ���� �����ϴ� ���Ӽ����� �� �� ���� ū ��
int max = -1001; //���� ���� ū ��

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
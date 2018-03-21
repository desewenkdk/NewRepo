#include <iostream>
#include <vector>
using namespace std;

//cache[0] = INT_MAX, cache[i]에는, i에서부터 시작하는 부분수열 중 가장 긴 부분수열의 길이.가 저장.
//choices[i]에는, LIS의 i번째(0부터시작) 숫자를 나타내는 인덱스가 저장되어있다. 
int n,S[100],choices[101],cache[101];

int lis4(int start) {
	int &ret = cache[start+1];
	if(ret!=-1) return ret;
	
	ret=1;
	int bestNext = -1;

	for(int next = start+1; next<n; next++) {
		/*수열을 돌면서 수열의 길이가 가장 긴 오름차순 수열이 될 가능성이 있는 경우, (S[start]보다 큰 수가 나옴)
		거기서 다시 부분수열로 쪼개서 생각한다. S[next]가 추가되므로 길이는 +1된다
		*/
		//start=-1인경우, 처음 함수가 호출된 경우로, 이 경우에는 재귀를 돌게 한다.
		if(start==-1 && S[start]<S[next]) {
			int cand = lis4(next)+1;//재-----------귀
			if(cand > ret) //기존에 계산된 LIS의 길이보다 더 긴 경우 등장, candidate.(후보)
			{
				ret = cand;
				bestNext = next;
			}
		}
	}
	choices[start+1] = bestNext;
	return ret;
}

void reconstruct(int start, vector<int> &seq) {
	//start=-1은 함수 처음 호출시 넘어오는 값.
	if(start!=-1) seq.push_back(S[start]);
	//next는 LIS의 다음 수가 뭔지 choices배열에서 찾기 위한 수단.
	int next = choices[start+1];
	//choices의 마지막 값은 -1이다. 다 구했으니 끝. 첫 lis4호출부터 따라가다 보면 처음 choices[]에 저장되는 값인 bestNext가 -1인채로 그대로 저장됨을 알 수 있다.
	if(next!=-1) reconstruct(next,seq);
}

int main() {
	int a[10];
	printf("%d",a[1]);

	return 0;
}
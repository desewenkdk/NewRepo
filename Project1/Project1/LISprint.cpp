#include <iostream>
#include <vector>
using namespace std;

//cache[0] = INT_MAX, cache[i]����, i�������� �����ϴ� �κм��� �� ���� �� �κм����� ����.�� ����.
//choices[i]����, LIS�� i��°(0���ͽ���) ���ڸ� ��Ÿ���� �ε����� ����Ǿ��ִ�. 
int n,S[100],choices[101],cache[101];

int lis4(int start) {
	int &ret = cache[start+1];
	if(ret!=-1) return ret;
	
	ret=1;
	int bestNext = -1;

	for(int next = start+1; next<n; next++) {
		/*������ ���鼭 ������ ���̰� ���� �� �������� ������ �� ���ɼ��� �ִ� ���, (S[start]���� ū ���� ����)
		�ű⼭ �ٽ� �κм����� �ɰ��� �����Ѵ�. S[next]�� �߰��ǹǷ� ���̴� +1�ȴ�
		*/
		//start=-1�ΰ��, ó�� �Լ��� ȣ��� ����, �� ��쿡�� ��͸� ���� �Ѵ�.
		if(start==-1 && S[start]<S[next]) {
			int cand = lis4(next)+1;//��-----------��
			if(cand > ret) //������ ���� LIS�� ���̺��� �� �� ��� ����, candidate.(�ĺ�)
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
	//start=-1�� �Լ� ó�� ȣ��� �Ѿ���� ��.
	if(start!=-1) seq.push_back(S[start]);
	//next�� LIS�� ���� ���� ���� choices�迭���� ã�� ���� ����.
	int next = choices[start+1];
	//choices�� ������ ���� -1�̴�. �� �������� ��. ù lis4ȣ����� ���󰡴� ���� ó�� choices[]�� ����Ǵ� ���� bestNext�� -1��ä�� �״�� ������� �� �� �ִ�.
	if(next!=-1) reconstruct(next,seq);
}

int main() {
	int a[10];
	printf("%d",a[1]);

	return 0;
}
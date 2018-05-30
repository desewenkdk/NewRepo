#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
#define min(a,b) (a <= b ? a : b)
//const int INT_MAX = numeric_limits<int>::max();

class RMQ {
private : 
	// length of Array
	int n; 
	
	//각 구간의 최소치.
	vector<int> rangeMin; 
	
	/*initialize - 해당 노드내부의 최소치를 저장해둔다.*/
	int init(const vector<int>&array, int left, int right, int nodeNum);
	
	/*임의의 구간의 최소치를 구해내는 연산(질의연산.)*/
	int query(int left, int right, int nodeNum, int nodeLeft, int nodeRight);

	/*갱신*/
	int update(int index, int newValue, int nodeNum, int nodeLeft, int nodeRight);
public :
	/*생성자*/
	RMQ(const vector <int>&array) {
		n = array.size();
		rangeMin.resize(n*4);
		init(array, 0, n-1, 1);
	}
	
	/*임의의 구간의 최소치를 구해내는 연산(질의연산.)*/
	int query(int left, int right) {
		return query(left,right,1, 0, n-1);
	}

	/*배열array내부의 index위치에 있던 값이 nextValue로 바뀌었을 때, 구간트리를 갱신해주는 함수.*/
	int update(int index, int nextValue) {
		return update(index, nextValue, 1 ,0,n-1);
	}
};

/*init에서, 각node번호와, array에서의 구간을 전달받아와서 해당 노드구간의 최소치 - rangeMin[]를 저장해두는 초기화작업.*/
int RMQ::init(const vector<int>&array, int left, int right, int nodeNum) {
	//구간의 크기가 1인 경우.
	if(left == right) 
		return rangeMin[nodeNum] = array[left]; 

	int mid = (left + right) / 2;
	int leftMin = init(array, left, mid, nodeNum*2);
	int rightMin = init(array, mid+1, right, nodeNum * 2 + 1);
	//leftChild, rightChild중 더 작은 최소치를 현재 구간의 최소치로 삼는다.
	return rangeMin[nodeNum] = min(leftMin, rightMin);
}

/*노드구간 nL, nR가 주어질 때, 구하고자 하는 구간 [left, right]과 노드구간[nL, nR]의 교집합구간의 최소치를 구한다.*/
int RMQ::query(int left, int right, int nodeNum, int nodeLeft, int nodeRight) {
	//1. 구간의 교집합이 없는 경우 - 꽝, 순회종료, 아주 큰 값 반환.
	if(right < nodeLeft || left < nodeRight) {
		return INT_MAX;
	}

	//3. [left (NL~NR) right]인 경우 즉,최소치를 구하는 구간에 노드구간이 완전히 포함될 경우 - 미리 저장해둔 node의 최소치를 반환.
	if(left <= nodeLeft  && right >= nodeRight) {
		return rangeMin[nodeNum];
	}

	//2. left, right가 nodeL, nodeR에 포함됨=> 노드를 left, right로 재귀적으로 쪼개어 각각에 대해 구간최소치를 구해오고 그 중 작은 걸 반환.
	//노드를 반으로 쪼개기.
	int mid = (nodeLeft + nodeRight) / 2;
	return min(query(left, right, nodeNum*2, nodeLeft, mid), query(left, right, nodeNum*2+1,mid+1, nodeRight));
}

/*배열array내부의 index위치에 있던 값이 nextValue로 바뀌었을 때, 구간트리의 해당 값(최소치)를 갱신해주는 함수.*/
int RMQ::update(int index, int newValue, int nodeNum, int nodeLeft, int nodeRight) {
	//1.index가 노드구간과 상관없는 경우는 무시.
	if(index < nodeLeft || index > nodeRight) {
		return rangeMin[nodeNum];
	}

	//2. 트리의 리프까지 내려온 경우 - 그 노드의 값을 바꿔주자.
	if(nodeLeft == nodeRight) return rangeMin[nodeNum] = newValue;

	//3. 왼쪽, 오른쪽으로 나누어서 업데이트 재귀적으로 진행.
	int mid = (nodeLeft + nodeRight) / 2;
	return rangeMin[nodeNum] = min(update(index, newValue, nodeNum, nodeLeft, mid), update(index, newValue, nodeNum, mid+1, nodeRight));
}
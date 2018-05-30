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
	
	//�� ������ �ּ�ġ.
	vector<int> rangeMin; 
	
	/*initialize - �ش� ��峻���� �ּ�ġ�� �����صд�.*/
	int init(const vector<int>&array, int left, int right, int nodeNum);
	
	/*������ ������ �ּ�ġ�� ���س��� ����(���ǿ���.)*/
	int query(int left, int right, int nodeNum, int nodeLeft, int nodeRight);

	/*����*/
	int update(int index, int newValue, int nodeNum, int nodeLeft, int nodeRight);
public :
	/*������*/
	RMQ(const vector <int>&array) {
		n = array.size();
		rangeMin.resize(n*4);
		init(array, 0, n-1, 1);
	}
	
	/*������ ������ �ּ�ġ�� ���س��� ����(���ǿ���.)*/
	int query(int left, int right) {
		return query(left,right,1, 0, n-1);
	}

	/*�迭array������ index��ġ�� �ִ� ���� nextValue�� �ٲ���� ��, ����Ʈ���� �������ִ� �Լ�.*/
	int update(int index, int nextValue) {
		return update(index, nextValue, 1 ,0,n-1);
	}
};

/*init����, ��node��ȣ��, array������ ������ ���޹޾ƿͼ� �ش� ��屸���� �ּ�ġ - rangeMin[]�� �����صδ� �ʱ�ȭ�۾�.*/
int RMQ::init(const vector<int>&array, int left, int right, int nodeNum) {
	//������ ũ�Ⱑ 1�� ���.
	if(left == right) 
		return rangeMin[nodeNum] = array[left]; 

	int mid = (left + right) / 2;
	int leftMin = init(array, left, mid, nodeNum*2);
	int rightMin = init(array, mid+1, right, nodeNum * 2 + 1);
	//leftChild, rightChild�� �� ���� �ּ�ġ�� ���� ������ �ּ�ġ�� ��´�.
	return rangeMin[nodeNum] = min(leftMin, rightMin);
}

/*��屸�� nL, nR�� �־��� ��, ���ϰ��� �ϴ� ���� [left, right]�� ��屸��[nL, nR]�� �����ձ����� �ּ�ġ�� ���Ѵ�.*/
int RMQ::query(int left, int right, int nodeNum, int nodeLeft, int nodeRight) {
	//1. ������ �������� ���� ��� - ��, ��ȸ����, ���� ū �� ��ȯ.
	if(right < nodeLeft || left < nodeRight) {
		return INT_MAX;
	}

	//3. [left (NL~NR) right]�� ��� ��,�ּ�ġ�� ���ϴ� ������ ��屸���� ������ ���Ե� ��� - �̸� �����ص� node�� �ּ�ġ�� ��ȯ.
	if(left <= nodeLeft  && right >= nodeRight) {
		return rangeMin[nodeNum];
	}

	//2. left, right�� nodeL, nodeR�� ���Ե�=> ��带 left, right�� ��������� �ɰ��� ������ ���� �����ּ�ġ�� ���ؿ��� �� �� ���� �� ��ȯ.
	//��带 ������ �ɰ���.
	int mid = (nodeLeft + nodeRight) / 2;
	return min(query(left, right, nodeNum*2, nodeLeft, mid), query(left, right, nodeNum*2+1,mid+1, nodeRight));
}

/*�迭array������ index��ġ�� �ִ� ���� nextValue�� �ٲ���� ��, ����Ʈ���� �ش� ��(�ּ�ġ)�� �������ִ� �Լ�.*/
int RMQ::update(int index, int newValue, int nodeNum, int nodeLeft, int nodeRight) {
	//1.index�� ��屸���� ������� ���� ����.
	if(index < nodeLeft || index > nodeRight) {
		return rangeMin[nodeNum];
	}

	//2. Ʈ���� �������� ������ ��� - �� ����� ���� �ٲ�����.
	if(nodeLeft == nodeRight) return rangeMin[nodeNum] = newValue;

	//3. ����, ���������� ����� ������Ʈ ��������� ����.
	int mid = (nodeLeft + nodeRight) / 2;
	return rangeMin[nodeNum] = min(update(index, newValue, nodeNum, nodeLeft, mid), update(index, newValue, nodeNum, mid+1, nodeRight));
}
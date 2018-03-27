#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string getInput;
int eggPrice[14]; // ���� ��� ���� //c++�� �����迭�� ��� ��� ���Ұ� 0���� �ʱ�ȭ�� �ȴ�[//
int orderedPlate[14]; // ��� ������ �����ϴ� �������� ������������ ������ �迭
vector<int> generatedCandPrice; //���� ��� ���� �ĺ��� �� ��������Ʈ, m�� ������� Ȯ���� ���ľ���.
int checkDigit[14]; //orderedPlate���� ���� ������ �ƴ��� üũ, checkDigit[1] == 1 ->  o_P[1]�� �̹� ���� ���̴�.

int m; //��������. 
int result=0; // ������ ���� ��� ���ݵ��� �� �����ΰ�?

int func1 (int start_EP_index);
int arrayToInteger (int size, vector<int> arr);
int powInt (int val, int exp);
void printArray (int size,int arr[]);

int main () {
	orderedPlate[0] = -1;
	checkDigit[0] = -1;

	int C;
	cin >> C;
	cin >> getInput;
	cin >> m;

	for (int c = 0; c < C; c++) {
		for (int i = 0; i < getInput.size (); i++) {
			eggPrice[i] = getInput[i] - '0';
			orderedPlate[i] = eggPrice[i];
		}

		sort (orderedPlate, orderedPlate + getInput.size ());

		func1 (0);

		cout << result % 1000000007;
	}
	return 0;
}

int func1 (int start_EP_index) {
	int start;
	if (start_EP_index >= getInput.size()) {
		/*
		���� generatedCandPrice�� �� ä���� ������ �̷������ �ϴ� �۾��̴�.
		*/
		//���ڰ� �� ��.
		int candPrice = arrayToInteger (getInput.size(), generatedCandPrice);
		
		
		//���������� m�� ���� ��� ���θ� üũ�Ѵ�.
		if (candPrice % m == 0) {
			if (stoi(getInput) == candPrice)
				return result; 

			result++;
		}

	}
	else {
		//o_P���� ��ȸ�ϸ鼭 ���� �ڸ����� �� �����ϳ��� ���ؼ� �ִ´�.
		//for���� generatedCandPrice�� �����ϴ� �κ��̴�.
		for (start = 0; start < getInput.size (); start++) {
			if (checkDigit[start] < 1) {
				checkDigit[start] = 1;
				generatedCandPrice.push_back (orderedPlate[start]);

				func1 (start_EP_index + 1);

				//��ȸ �� ����.

				//has to fix  ex)4628 ->2468->2486nocheck
				generatedCandPrice.pop_back ();
				checkDigit[start] = 0;

				//fix.
				if (orderedPlate[start] >= eggPrice[start_EP_index])
					break;
			}
		}

	}
	return result;
}

int arrayToInteger (int size, vector<int> arr) {
	int sum=0;
	
	for (int i = 0; i <size; i++) {
		sum += arr.at(i) * powInt (10,size-1-i);
	}
	
	return sum;
	
}
	
int powInt (int val, int exp) {
	int t=1;
	for (int i = 0; i < exp; i++) {
		t *= val;
	}
	return t;
}

void printArray (int size, int arr[]) {
	for (int i = 0; i < size; i++) {
		cout << arr[i];
	}
	cout << endl;
}
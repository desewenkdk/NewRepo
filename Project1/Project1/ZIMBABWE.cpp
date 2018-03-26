#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string getInput;
int eggPrice[14]; // ���� ��� ���� //c++�� �����迭�� ��� ��� ���Ұ� 0���� �ʱ�ȭ�� �ȴ�[//
int orderedPlate[15] = {1}; // ��� ������ �����ϴ� �������� ������������ ������ �迭
vector<int> generatedCandPrice; //���� ��� ���� �ĺ��� �� ��������Ʈ, m�� ������� Ȯ���� ���ľ���.
int checkDigit[15] = {1,0}; //orderedPlate���� ���� ������ �ƴ��� üũ, checkDigit[1] == 1 ->  o_P[1]�� �̹� ���� ���̴�.

int m; //��������. 
int result=0; // ������ ���� ��� ���ݵ��� �� �����ΰ�?

int func1 (int start_EP_index);
int arrayToInteger (int length);
int powInt (int val, int exp);

int main () {
	orderedPlate[0] = -1;
	checkDigit[0] = -1;

	int C;
	cin >> C;
	cin >> getInput;
	cin >> m;

	for (int i = 0; i < getInput.length(); i++) {
		eggPrice[i] = getInput[i] - '0';
		orderedPlate[i] = eggPrice[i];
	}

	sort(orderedPlate,orderedPlate+ getInput.length ());
	func1 (0);

	cout << result % 1000000007;
	return 0;
}

int func1 (int start_EP_index) {

	if (start_EP_index >= getInput.length()) {
		/*
		���� generatedCandPrice�� �� ä���� ������ �̷������ �ϴ� �۾��̴�.
		*/
		//���ڰ� �� ��.
		int candPrice = arrayToInteger (getInput.length());

		//���������� m�� ���� ��� ���θ� üũ�Ѵ�.
		if (candPrice % m == 0) {
			result++;
		}

	}
	else
		//o_P���� ��ȸ�ϸ鼭 ���� �ڸ����� �� �����ϳ��� ���ؼ� �ִ´�.
		//for���� generatedCandPrice�� �����ϴ� �κ��̴�.
		for (int start=0; start < getInput.length(); start++) {
			if (checkDigit[start] < 1) {
				checkDigit[start] = 1;
				generatedCandPrice.push_back (orderedPlate[start + 1]);
				
				func1 (start_EP_index++);

				//��ȸ �� ����.
				generatedCandPrice.pop_back();
				checkDigit[start] = 0;

				if (orderedPlate[start] > eggPrice[start_EP_index])
					break;
			}
		}
	return result;
}

int arrayToInteger (int length) {
	int sum=0, tmp;
	
	for (int i = length; i > 0; i--) {
		sum += generatedCandPrice.at(i) * powInt (10,length-1);
	}
	
	return sum;
	
}
	
int powInt (int val, int exp) {
	int result=1;
	for (int i = 0; i < exp;i ++) {
		result *= val;
	}
	return val;
}
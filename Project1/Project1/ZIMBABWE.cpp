#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string getInput;
int eggPrice[14]; // ���� ��� ����
int orderedPlate[15]; // ��� ������ �����ϴ� �������� ������������ ������ �迭
int generatedCandPrice[14]; //���� ��� ���� �ĺ��� �� �����迭, m�� ������� Ȯ���� ���ľ���.
int checkDigit[15] = {1,0}; //orderedPlate���� ���� ������ �ƴ��� üũ, checkDigit[1] == 1 ->  o_P[1]�� �̹� ���� ���̴�.

int m; //��������. 
int result; // ������ ���� ��� ���ݵ��� �� �����ΰ�?


/*
1. n!��������. 2.(n-1)!��������->����Լ����� ó���ϵ��� �Ѵ�.
3. 
*/
int func1 (int start_EP_index);
int main () {
	orderedPlate[0] = -1;
	checkDigit[0] = -1;



	return 0;
}

int func1 (int start_EP_index) {
	for (int start; start < getInput.length; start++) {
		if (checkDigit[start] < 1) {
			checkDigit[start] = 1;
			if(orderedPlate[start] == eggPrice[start_EP_index]){
				func1 ();
			}
		}
	}
}

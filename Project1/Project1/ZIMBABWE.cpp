#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string getInput;
int eggPrice[14]; // ���� ��� ����
int orderedPlate[15]; // ��� ������ �����ϴ� �������� ������������ ������ �迭
vector<int> generatedCandPrice; //���� ��� ���� �ĺ��� �� ��������Ʈ, m�� ������� Ȯ���� ���ľ���.
int checkDigit[15] = {1,0}; //orderedPlate���� ���� ������ �ƴ��� üũ, checkDigit[1] == 1 ->  o_P[1]�� �̹� ���� ���̴�.

int m; //��������. 
int result; // ������ ���� ��� ���ݵ��� �� �����ΰ�?


/*
1. n!��������. 2.(n-1)!��������->����Լ����� ó���ϵ��� �Ѵ�.
3. 
*/
int func1 (int start_EP_index);
int arrayToInteger (int length);

int main () {
	orderedPlate[0] = -1;
	checkDigit[0] = -1;


	return 0;
}

int func1 (int start_EP_index) {
	int start = 0;

	//o_P���� ��ȸ�ϸ鼭 ���� �ڸ����� �� �����ϳ��� ���ؼ� �ִ´�.
	//for���� generatedCandPrice�� �ϼ��ϴ� �ܰ�.
	for (; start < getInput.length; start++) {
		if (checkDigit[start] < 1) {
			checkDigit[start] = 1;
			generatedCandPrice.push_back(orderedPlate[start+1]);

			//�� �̻� ū ���� �ͼ� �ȵȴ�.->�ܰ踦 �������� �ѱ��.
			if(orderedPlate[start] >= eggPrice[start_EP_index]){
				//???
				func1 (start_EP_index++);
				break;
			}

			//����Ž��
			else {
				
			}
		}
	}

	//���ڰ� �� ��.
	int candPrice = arrayToInteger (getInput.length);

	//���������� m�� ���� ��� ���θ� üũ�Ѵ�.
	if (candPrice % m == 0) {
		generatedCandPrice.pop_back;
		return result++;
	}
	else
		return result;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string getInput;
int eggPrice[14]; // 현재 계란 가격 //c++은 전역배열의 경우 모든 원소가 0으로 초기화가 된단[//
int orderedPlate[14]; // 계란 가격을 구성하는 정수들을 오름차순으로 정렬한 배열
vector<int> generatedCandPrice; //이전 계란 가격 후보가 될 정수리스트, m의 배수인지 확인을 거쳐야함.
int checkDigit[14]; //orderedPlate에서 쓰인 수인지 아닌지 체크, checkDigit[1] == 1 ->  o_P[1]이 이미 쓰인 값이다.

int m; //사탕갯수. 
int result=0; // 가능한 이전 계란 가격들이 몇 가지인가?

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
		여긴 generatedCandPrice가 다 채워진 다음에 이루어져야 하는 작업이다.
		*/
		//숫자가 다 들어감.
		int candPrice = arrayToInteger (getInput.size(), generatedCandPrice);
		
		
		//마지막으로 m에 대한 배수 여부를 체크한다.
		if (candPrice % m == 0) {
			if (stoi(getInput) == candPrice)
				return result; 

			result++;
		}

	}
	else {
		//o_P에서 순회하면서 현재 자릿수에 들어갈 숫자하나를 정해서 넣는다.
		//for문은 generatedCandPrice를 구성하는 부분이다.
		for (start = 0; start < getInput.size (); start++) {
			if (checkDigit[start] < 1) {
				checkDigit[start] = 1;
				generatedCandPrice.push_back (orderedPlate[start]);

				func1 (start_EP_index + 1);

				//순회 후 원복.

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
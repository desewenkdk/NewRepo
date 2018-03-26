#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string getInput;
int eggPrice[14]; // 현재 계란 가격 //c++은 전역배열의 경우 모든 원소가 0으로 초기화가 된단[//
int orderedPlate[15] = {1}; // 계란 가격을 구성하는 정수들을 오름차순으로 정렬한 배열
vector<int> generatedCandPrice; //이전 계란 가격 후보가 될 정수리스트, m의 배수인지 확인을 거쳐야함.
int checkDigit[15] = {1,0}; //orderedPlate에서 쓰인 수인지 아닌지 체크, checkDigit[1] == 1 ->  o_P[1]이 이미 쓰인 값이다.

int m; //사탕갯수. 
int result=0; // 가능한 이전 계란 가격들이 몇 가지인가?

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
		여긴 generatedCandPrice가 다 채워진 다음에 이루어져야 하는 작업이다.
		*/
		//숫자가 다 들어감.
		int candPrice = arrayToInteger (getInput.length());

		//마지막으로 m에 대한 배수 여부를 체크한다.
		if (candPrice % m == 0) {
			result++;
		}

	}
	else
		//o_P에서 순회하면서 현재 자릿수에 들어갈 숫자하나를 정해서 넣는다.
		//for문은 generatedCandPrice를 구성하는 부분이다.
		for (int start=0; start < getInput.length(); start++) {
			if (checkDigit[start] < 1) {
				checkDigit[start] = 1;
				generatedCandPrice.push_back (orderedPlate[start + 1]);
				
				func1 (start_EP_index++);

				//순회 후 원복.
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
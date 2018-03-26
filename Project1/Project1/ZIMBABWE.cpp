#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string getInput;
int eggPrice[14]; // 현재 계란 가격
int orderedPlate[15]; // 계란 가격을 구성하는 정수들을 오름차순으로 정렬한 배열
int generatedCandPrice[14]; //이전 계란 가격 후보가 될 정수배열, m의 배수인지 확인을 거쳐야함.
int checkDigit[15] = {1,0}; //orderedPlate에서 쓰인 수인지 아닌지 체크, checkDigit[1] == 1 ->  o_P[1]이 이미 쓰인 값이다.

int m; //사탕갯수. 
int result; // 가능한 이전 계란 가격들이 몇 가지인가?


/*
1. n!가지연산. 2.(n-1)!가지연산->재귀함수에서 처리하도록 한다.
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

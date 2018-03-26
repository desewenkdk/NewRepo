#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string getInput;
int eggPrice[14]; // 현재 계란 가격
int orderedPlate[15]; // 계란 가격을 구성하는 정수들을 오름차순으로 정렬한 배열
vector<int> generatedCandPrice; //이전 계란 가격 후보가 될 정수리스트, m의 배수인지 확인을 거쳐야함.
int checkDigit[15] = {1,0}; //orderedPlate에서 쓰인 수인지 아닌지 체크, checkDigit[1] == 1 ->  o_P[1]이 이미 쓰인 값이다.

int m; //사탕갯수. 
int result; // 가능한 이전 계란 가격들이 몇 가지인가?


/*
1. n!가지연산. 2.(n-1)!가지연산->재귀함수에서 처리하도록 한다.
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

	//o_P에서 순회하면서 현재 자릿수에 들어갈 숫자하나를 정해서 넣는다.
	//for문은 generatedCandPrice를 완성하는 단계.
	for (; start < getInput.length; start++) {
		if (checkDigit[start] < 1) {
			checkDigit[start] = 1;
			generatedCandPrice.push_back(orderedPlate[start+1]);

			//더 이상 큰 수가 와선 안된다.->단계를 다음으로 넘긴다.
			if(orderedPlate[start] >= eggPrice[start_EP_index]){
				//???
				func1 (start_EP_index++);
				break;
			}

			//전수탐색
			else {
				
			}
		}
	}

	//숫자가 다 들어감.
	int candPrice = arrayToInteger (getInput.length);

	//마지막으로 m에 대한 배수 여부를 체크한다.
	if (candPrice % m == 0) {
		generatedCandPrice.pop_back;
		return result++;
	}
	else
		return result;
}

#include <stdio.h>


int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
int main() {
	int i;
	for (i = 0; i < 10;i++) {
		arr[i] += 1;
	}
	return 0;
}
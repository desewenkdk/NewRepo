
#include <iostream>
#include <algorithm>
#include <tuple>
#include <stdlib.h>
#define MAXIMUM INT_MAX

using namespace std;


void printPairs(pair<int, int> *pairs, int n) {
	for (int i = 0; i<n; i++) {
		cout << pairs[i].first << "," << pairs[i].second << "||";
	}
	cout << endl;
}

bool pairCompByDiff(pair <int, int>a, pair<int, int> b) {
	return a.second > b.second;
}
bool pairCompByIdx(pair <int, int>a, pair<int, int> b) {
	return a.first < b.first;
}

int findApxAvg(int *nums, int start, int end, float target) {
	int mid;
	while (start <= end) {
		mid = (end + start) / 2;
		if (nums[mid] == target) return mid;
		else if (target<nums[mid]) end = mid - 1;
		else if (target>nums[mid]) start = mid + 1;
	}
	return mid;
}

int getMinimumSquareDiff(int *nums, int start, int end) {
	int subtotal = 0;
	if (start == end)
		return nums[start];

	int apxAvgidx = findApxAvg(nums, start, end, (nums[start] + nums[end]) / 2);
	//int tmp[3] = { 0,0,0 };
	//for (int i = -1; i <= 1; i++) {
	//	for (int j = start; j <= end; j++) {
	//		if (apxAvgidx + i >= j)
	//			tmp[i + 1] += nums[apxAvgidx + i] - nums[j];
	//		else
	//			tmp[i + 1] += nums[j] - nums[apxAvgidx + i];
	//	}
	//}
	//sort(tmp, tmp + 3);

	//return tmp[0] * tmp[0];
	for(int i=start; i<=end; i++) {
//		if(apxAvgidx>=i)
//			/*subtotal += (nums[apxAvgidx] - nums[i]) * (nums[apxAvgidx]-nums[i]);*/
////		else
//			tmp[i + 1] += nums[j] - nums[apxAvgidx + i];
//		subtotal +=  
			subtotal += (nums[apxAvgidx]-nums[i]) * (nums[apxAvgidx]-nums[i]);
	}
	
	return subtotal;
}


int main() {

	int c;
	int N[100];
	int n, s;
	int sum_squre_diff = 0;
	pair <int, int> pairs[100];
	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> n >> s;
	//	cout << n << "," << s;
		if (n<s)throw "Not allowed input n, s";

		//initalize array in sorted
		for (int i = 0; i < n; i++) {
			cin >> N[i];
		}
		sort(N, N + n);
		for (int i = 0; i<n; i++) {
			cout << N[i] << endl;
		}


		for (int i = 0; i < n; i++) {
			if (i == 0) pairs[0] = make_pair(0, INT_MAX);
			else
				pairs[i] = make_pair(i, N[i] - N[i - 1]);
		}

		//sort order by difference of two adjacent values
		sort(pairs, pairs + n, pairCompByDiff);
		printPairs(pairs, n);


///////////1. pairs에 저장된 인덱스-1값 기준으로 잘라야 한다.
		//re-sort 0~s-1 order by index-number in pairs, using stable_sort
		stable_sort(pairs, pairs + s, pairCompByIdx);
		printPairs(pairs, n);


		

		//calculate
		for (int i = 0; i<s - 1; i++) {
			sum_squre_diff += getMinimumSquareDiff(N,pairs[i].first,pairs[i+1].first-1);
		}
		sum_squre_diff += getMinimumSquareDiff(N,pairs[i].first,n-1);
		cout << sum_squre_diff << endl;
	}
	return 0;
}
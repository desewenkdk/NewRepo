#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define INT_MAX 1001
typedef enum color { red, green, blue };
int house[1000][3]; //house[0][red] = 0��° ���� red�� ���� ���
int num_house;
//int ret = 10000001; �� i��° ���� cache���� �־�� ������ �����ϴ�.
int cache[1000][3]; //(cache��, ������ ������ ���� �ּҰ� �ǵ��� ������ ������� �����ϰ� �ִ�.)
					//cache[i][red] = i��° ���� red�� ĥ�� ��� i��°���� ���� �� �ִ� �ּ���.
int cand;
std::vector<color> v ={ red, green, blue };

//int colorhome(color precolor, int precostSum, int houseindex); //������ ������ ��Ű�� ���� houseindex�� �Ķ���ͷ� �Ѱ�����.(���� �ǹ̴� ����.)

/*
IDEA : index������ colorSum�� �ּڰ� = MIN(������ ����� �ּڰ�,index+1������ �ּڰ� + index���� ���� �� ���)

*���� ��������, ���� �հ��� �񱳰� �ƴ�, cache[houseindex][color]�� ����� ������ �񱳸� ���� �ּ����� ����Ѵ�.
color����, '������ ĥ�� ��' ������ �����ش�.
*/
int colorhome2(color color, int houseindex);
int min(color precolor);

int main() {

	scanf("%d", &num_house);
	for(int i=0; i<num_house; i++) {
		for(color c : v) {
			scanf("%d", &house[i][c]);
			cache[i][c] = -1; //cache initializing
		}
	}

	int ret = 10000001;
	for(color c: v) {
		ret = std::min(ret, colorhome2(c, 0));
	}
	printf("%d", ret);
	return 0;
}

int colorhome2(color color, int houseindex) {
	if(houseindex == num_house)
		return house[houseindex][color];

	if(cache[houseindex][color] != -1)
		return cache[houseindex][color];

	int ret = 10000001;

	//for���� ���� �Ǹ�, ������ ����������. 
	switch(color) {
	case red:
		ret = std::min(ret, house[houseindex][color] + colorhome2(green, houseindex+1));
		ret = std::min(ret, house[houseindex][color] + colorhome2(blue, houseindex+1));
		break;
	case green:
		ret = std::min(ret, house[houseindex][color] + colorhome2(red, houseindex+1));
		ret = std::min(ret, house[houseindex][color] + colorhome2(blue, houseindex+1));
		break;
	case blue:
		ret = std::min(ret, house[houseindex][color] + colorhome2(red, houseindex+1));
		ret = std::min(ret, house[houseindex][color] + colorhome2(green, houseindex+1));
		break;
	}
	//update cache[][]
	cache[houseindex][color] = ret;
	return ret;
}

//int colorhome(color precolor, int precostSum, int houseindex) {
//	if(precostSum > ret)
//		return ret;
//
//	if(houseindex == num_house-1) {
//		//compare value (precostSum + lastcost) with ret
//		//update or preserve ret
//		int candidate = precostSum + min(precolor);
//		if(candidate < ret)
//			ret = candidate;
//		return ret;
//	}
//
//	for(color c:v) {
//		if(c == precolor) continue;
//		cand = (std::min)(ret, colorhome(c, precostSum+house[houseindex][c], houseindex+1));
//	}
//}

int min(color precolor) {
	int min;
	min = INT_MAX;
	for(color c:v) {
		if(c == precolor) continue;
		else {
			if(min > house[num_house-1][c])
				min = house[num_house-1][c];
		}
	}
	return min;
}
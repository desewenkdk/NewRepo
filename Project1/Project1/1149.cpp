#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define INT_MAX 1001
typedef enum color { red, green, blue };
int house[1000][3]; //house[0][red] = 0번째 집의 red에 대한 비용
int num_house;
//int ret = 10000001; 각 i번째 마다 cache값이 있어야 참조가 가능하다.
int cache[1000][3]; //(cache는, 마지막 값에서 부터 최소가 되도록 더해진 결과들을 저장하고 있다.)
					//cache[i][red] = i번째 집을 red로 칠할 경우 i번째에서 나올 수 있는 최솟합.
int cand;
std::vector<color> v ={ red, green, blue };

//int colorhome(color precolor, int precostSum, int houseindex); //참조적 투명성을 지키기 위해 houseindex를 파라미터로 넘겨주자.(별로 의미는 없다.)

/*
IDEA : index에서의 colorSum의 최솟값 = MIN(이전에 계산한 최솟값,index+1까지의 최솟값 + index에서 현재 색 비용)

*개량 버전에선, 이전 합과의 비교가 아닌, cache[houseindex][color]에 저장된 값과의 비교를 통해 최소합을 계산한다.
color값도, '다음에 칠해 줄' 색깔을 보내준다.
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

	//for문을 쓰게 되면, 오히려 복잡해진다. 
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
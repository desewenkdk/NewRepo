#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define INT_MAX 1001
typedef enum color {red, green, blue};
int house[1000][3]; //house[0][red] = 0번째 집의 red에 대한 비용
int num_house;
int ret = 3001;
int cand;
std::vector<color> v ={ red, green, blue };

int colorhome(color precolor, int precostSum, int houseindex); //참조적 투명성을 지키기 위해 houseindex를 파라미터로 넘겨주자.(별로 의미는 없다.)
int min(color precolor);

void main() {
	
	scanf("%d", &num_house);
	for(int i=0; i<num_house; i++) {
		for(color c : v) {
			scanf("%d",&house[i][c]);
		}
	}

	for(color c: v) {
		int firstCost = house[0][c];

		if(firstCost > ret)
			continue;

		cand = colorhome(c, firstCost, 1);
		if(cand < ret)
			ret = cand;
	}
	printf("%d",ret);

}

int colorhome(color precolor, int precostSum, int houseindex) {
	if(precostSum > ret)
		return ret;

	if(houseindex == num_house-1) {
		//compare value (precostSum + lastcost) with ret
		//update or not ret
	}

	for(color c:v) {
		if(c == precolor) continue;
		ca
	}
}

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
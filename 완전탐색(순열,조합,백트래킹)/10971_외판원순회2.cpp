#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/*
시간복잡도 : O(n!)
공간복잡도 : O(n^2)
*/

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif 

	int cityNum, cost[11][11], min = 987654321, result, i, flag;
	vector<int> city;

	scanf("%d", &cityNum);
	for (int i = 0; i < cityNum; i++) {
		for (int j = 0; j < cityNum; j++) {
			scanf("%d", &cost[i][j]);
		}
	}

	for (int i = 0; i < cityNum; i++) {
		city.push_back(i);
	}

	do {
		result = 0;
		flag = 0;

		for (i = 0; i < cityNum - 1; i++) {
			if (cost[city[i]][city[i + 1]] == 0) {
				flag = -1;
				break;
			}
			result += cost[city[i]][city[i + 1]];
		}
		if (cost[city[i]][city[0]] != 0 && flag != -1) {
			result += cost[city[i]][city[0]];
			if (min > result && result != 0) min = result;
		}

	}while(next_permutation(city.begin(), city.end()));

	printf("%d\n", min);

	return 0;
}
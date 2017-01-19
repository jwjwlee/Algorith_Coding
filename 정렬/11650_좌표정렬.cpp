#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

/*
시간복잡도 : O(n)
공간복잡도 : O(n)
*/
int main()
{
	int case_num, x, y;

	scanf("%d", &case_num);
	vector <pair<int, int>> point(case_num);

	for (int i = 0; i < case_num; i++) {
		scanf("%d %d", &point[i].first, &point[i].second);

	}

	sort(point.begin(), point.end());

	for (int i = 0; i < case_num; i++) {
		printf("%d %d\n", point[i].first, point[i].second);
	}

	return 0;
}
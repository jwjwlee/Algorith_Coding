#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

/*
시간복잡도 : O()
공간복잡도 : O()
*/

queue<pair<int, int>> q;
int visit[100001], cnt = 0;

int find(int x, int y)
{
	int temp;

	q.push(make_pair(x, 0));
	visit[x] = 1;

	while (!q.empty()) {
		temp = q.front().first;
		cnt = q.front().second;
		q.pop();

		if (temp == y) break;

		if (temp < 100000) {
			if (visit[temp + 1] == 0) {
				visit[temp + 1] = 1;
				q.push(make_pair(temp + 1, cnt + 1));
			}
		}

		if (temp > 0) {
			if (visit[temp - 1] == 0) {
				visit[temp - 1] = 1;
				q.push(make_pair(temp - 1, cnt + 1));
			}
		}
		if (temp <= 50000) {
			if (visit[temp * 2] == 0) {
				visit[temp * 2] = 1;
				q.push(make_pair(temp * 2, cnt + 1));
			}
		}
	}

	return cnt;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif 

	int a, b, result;

	scanf("%d %d", &a, &b);

	result = find(a, b);

	printf("%d\n", result);

	return 0;
}
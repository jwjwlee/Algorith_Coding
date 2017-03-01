#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, time, pre, preN, cost[10001];
	vector<pair<int, int>> v[10001];
	queue<int> q;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &time, &preN);
		cost[i] = time;
		if (preN == 0) q.push(i);
		for (int j = 1; j <= preN; j++) {
			scanf("%d", &pre);
			v[pre].push_back(make_pair(i, time));
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int temp = cost[cur] + v[cur][i].second;
			if (temp > cost[v[cur][i].first]) {
				cost[v[cur][i].first] = temp;
				q.push(v[cur][i].first);
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < cost[i]) max = cost[i];
	}
	printf("%d\n", max);

	return 0;
}
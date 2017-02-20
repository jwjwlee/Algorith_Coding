#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int N, connect, A, B, cost, visit[1001] = { 0 };
	vector<pair<int, int>> v[1001];
	priority_queue<pair<int, int>> pq;

	scanf("%d %d", &N, &connect);

	for (int i = 1; i <= connect; i++) {
		scanf("%d %d %d", &A, &B, &cost);
		v[A].push_back(make_pair(B, cost));
		v[B].push_back(make_pair(A, cost));
	}

	for (int i = 0; i < v[1].size(); i++)
		pq.push(make_pair(-v[1][i].second, v[1][i].first));

	int result = 0;
	visit[1] = 1;
	while (!pq.empty()) {
		int tempCost = -pq.top().first;
		int tempVertex = pq.top().second;
		pq.pop();

		if (visit[tempVertex] == 1) continue;
		
		visit[tempVertex] = 1;
		result += tempCost;
		for (int i = 0; i < v[tempVertex].size(); i++) {
			pq.push(make_pair(-v[tempVertex][i].second, v[tempVertex][i].first));
		}
	}
	printf("%d\n", result);

	return 0;
}
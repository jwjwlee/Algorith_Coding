#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int vertex, edge, A, B, cost, visit[10001] = { 0 };
	vector<pair<int, int>> v[10001];
	priority_queue<pair<int, int>> pq;

	scanf("%d %d", &vertex, &edge);
	for (int i = 1; i <= edge; i++) {
		scanf("%d %d %d", &A, &B, &cost);
		v[A].push_back(make_pair(B, cost));
		v[B].push_back(make_pair(A, cost));
	}


	for (int i = 0; i < v[1].size(); i++)
		pq.push(make_pair(-v[1][i].second, v[1][i].first));

	int result = 0;
	visit[1] = 1;
	while (!pq.empty()) {
		int curVertex = pq.top().second;
		int curCost = -pq.top().first;
		pq.pop();

		if (visit[curVertex] == 1) continue;

		visit[curVertex] = 1;
		result += curCost;
		for (int i = 0; i < v[curVertex].size(); i++) {
			if (visit[v[curVertex][i].first] == 0) 
				pq.push(make_pair(-v[curVertex][i].second, v[curVertex][i].first));			
		}

	}
	printf("%d\n", result);

	return 0;
}
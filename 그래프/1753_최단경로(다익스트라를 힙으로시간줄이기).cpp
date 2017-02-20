#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1000000000
using namespace std;

int dist[20001], visit[20001] = { 0 };
vector<pair<int, int>> v[20001];

int main()
{
	int V, E, start, A, B, cost;
	
	scanf("%d %d %d", &V, &E, &start);

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &A, &B, &cost);
		v[A].push_back(make_pair(B, cost));
	}

	for (int i = 1; i <= V; i++) dist[i] = MAX;
	
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int D = -pq.top().first;
		int V = pq.top().second;
		pq.pop();
		
		if (visit[V] == 1) continue;

		visit[V] = 1;
		for (int i = 0; i < v[V].size(); i++) {
			if (dist[v[V][i].first] > dist[V] + v[V][i].second) {
				dist[v[V][i].first] = dist[V] + v[V][i].second;
				pq.push(make_pair(-dist[v[V][i].first], v[V][i].first));
			}
		}
	}
	
	for (int i = 1; i <= V; i++) {
		if (dist[i] >= MAX) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <deque>
#define MAX 100000000
using namespace std;

int dist[1001], visit[1001] = { 0 }, from[1001], info[1001][1001];

int main()
{
	int n, m, A, B, cost, start, end;
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		dist[i] = MAX;
		for (int j = 1; j <= n; j++)
			info[i][j] = MAX;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &A, &B, &cost);
		if (info[A][B] > cost)
			info[A][B] = cost;
	}
	
	scanf("%d %d", &start, &end);
	dist[start] = 0;
	for (int i = 0; i < n - 1; i++) {
		int D = MAX + 1;
		int V;
		for (int j = 1; j <= n; j++) {
			if (visit[j] == 0 && D > dist[j]) {
				V = j;
				D = dist[j];
			}
		}

		visit[V] = 1;
		for (int j = 1; j <= n; j++) {
			if (dist[j] > dist[V] + info[V][j]) {
				dist[j] = dist[V] + info[V][j];
				from[j] = V;
			}
		}
	}
	printf("%d\n", dist[end]);

	deque<int> dq;
	dq.push_back(end);
	while (from[dq.back()] != start) {
		dq.push_back(from[dq.back()]);
	}
	dq.push_back(start);
	printf("%d\n", dq.size());
	
	while (!dq.empty()) {
		printf("%d ", dq.back());
		dq.pop_back();
	}
	printf("\n");

	return 0;
}
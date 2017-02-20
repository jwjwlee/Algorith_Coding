#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 100000000
using namespace std;

int city[1001][1001], dist[1001], visit[1001] = { 0 };
int main()
{
	int N, bus, A, B, cost, start, end;

	scanf("%d %d", &N, &bus);
	for (int i = 1; i <= N; i++) {
		dist[i] = MAX;
		for (int j = 1; j <= N; j++) {
			city[i][j] = MAX;
		}
	}

	for (int i = 0; i < bus; i++) {
		scanf("%d %d %d", &A, &B, &cost);
		if(city[A][B] > cost)
			city[A][B] = cost;
	}
			
	scanf("%d %d", &start, &end);
	dist[start] = 0;
	for (int i = 1; i < N; i++) {
		int tempD = MAX + 1;
		int tempV;

		for (int j = 1; j <= N; j++) {
			if (visit[j] == 0 && tempD > dist[j]) {
				tempD = dist[j];
				tempV = j;
			}
		}
		visit[tempV] = 1;
		for (int j = 1; j <= N; j++) {
			if (dist[j] > dist[tempV] + city[tempV][j])
				dist[j] = dist[tempV] + city[tempV][j];
		}
	}

	printf("%d\n", dist[end]);

	return 0;
}
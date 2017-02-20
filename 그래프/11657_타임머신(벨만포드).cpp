#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 100000000
using namespace std;

struct info
{
	int A, B, cost;
};

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int N, line, dist[501];
	
	scanf("%d %d", &N, &line);
	vector<info> v(line);
	for (int i = 0; i < line; i++) {
		scanf("%d %d %d", &v[i].A, &v[i].B, &v[i].cost);
	}

	for (int i = 1; i <= N; i++)
		dist[i] = MAX;
	
	dist[1] = 0;
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < line; j++) {
			int curS = v[j].A;
			int curE = v[j].B;
			int curT = v[j].cost;

			if (dist[curS] != MAX && dist[curE] > dist[curS] + curT) {
				dist[curE] = dist[curS] + curT;
				if (i == N) flag = true;
			}	
		}
	}
	
	if (flag == true) {
		printf("-1\n");
		return 0;
	}

	for (int i = 2; i <= N; i++) {
		if (dist[i] == MAX) printf("-1\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}
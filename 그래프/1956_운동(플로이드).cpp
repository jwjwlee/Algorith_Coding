#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAX 100000000
using namespace std;

int d[401][401];

int main()
{
	int n, m, a, b, cost;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &cost);
		d[a][b] = cost;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] != 0 && d[k][j] != 0) {
					if (d[i][j] == 0)
						d[i][j] = d[i][k] + d[k][j];
					else
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}

	int result = MAX;
	for (int i = 1; i <= n; i++) {
		if (d[i][i] == 0) continue;
		result = min(result, d[i][i]);
	}
	if (result == MAX) printf("-1\n");
	else printf("%d\n", result);

	return 0;
}
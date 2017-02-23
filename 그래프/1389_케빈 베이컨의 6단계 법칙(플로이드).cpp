#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int d[101][101];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int n, m, a, b;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		d[a][b] = 1;
		d[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (d[i][k] != 0 && d[k][j] != 0) {
					if (d[i][j] == 0)
						d[i][j] = d[i][k] + d[k][j];
					else
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}

	int minuser = 100000000;
	int user;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += d[i][j];
		}
		if (minuser > sum) {
			minuser = min(minuser, sum);
			user = i;
		}
	}

	printf("%d\n", user);

	return 0;
}
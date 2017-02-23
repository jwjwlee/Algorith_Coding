#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int n, d[21][21] = { 0 };

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &d[i][j]);
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (d[i][k] != 0 && d[k][j] != 0) {
					if (d[i][j] > d[i][k] + d[k][j]) {
						printf("-1\n");
						return 0;
					}
					if (d[i][j] == d[i][k] + d[k][j]) {
						d[i][j] = 0;
					}
				}
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (d[i][j] == d[j][i]) {
				d[j][i] = 0;
				sum += d[i][j];
			}
		}
	}

	printf("%d\n", sum);

	return 0;
}
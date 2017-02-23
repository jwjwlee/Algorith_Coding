#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX 10000001
using namespace std;

int f[101][101];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int n, m, a, b, cost;	
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &cost);
		if(cost < f[a][b] || f[a][b] == 0)
			f[a][b] = cost;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;				
				if (f[i][k] != 0 && f[k][j] != 0) {
					if (f[i][j] == 0) f[i][j] = f[i][k] + f[k][j];
					else {
						if (f[i][j] > f[i][k] + f[k][j])
							f[i][j] = f[i][k] + f[k][j];
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", f[i][j]);
		}
		printf("\n");
	}

	return 0;
}
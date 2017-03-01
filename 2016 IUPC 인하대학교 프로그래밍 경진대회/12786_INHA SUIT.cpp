#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 1000000000
using namespace std;

vector<int> v[101];
int result[101][101];
int main()
{
	int N, T, M, height; 

	scanf("%d %d", &N, &T);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &M);
		for (int j = 1; j <= M; j++) {
			scanf("%d", &height);
			v[i].push_back(height);
		}
	}
	
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= 20; j++)
			result[j][i] = MAX;
	}

	v[0].push_back(1);
	result[1][0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int a = v[i][j];
			int b = v[i][j] + 1;
			int c = v[i][j] - 1;
			int d = v[i][j] * 2;
			if (d > 20) d = 20;

			for (int k = 0; k < v[i + 1].size(); k++) {
				if (a == v[i + 1][k] || b == v[i + 1][k] || c == v[i + 1][k] || d == v[i + 1][k]) {
					result[v[i + 1][k]][i + 1] = min(result[v[i + 1][k]][i + 1], result[v[i][j]][i]);
				}
				else
					result[v[i + 1][k]][i + 1] = min(result[v[i + 1][k]][i + 1], result[v[i][j]][i] + 1);
			}
		}
	}

	int ans = MAX;
	for (int j = 1; j <= 20; j++) {
		ans = min(ans, result[j][N]);
	}
	if (ans > T) printf("-1\n");
	else printf("%d\n", ans);


	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, color[1001][3] = { 0 }, dp[1001][3] = { 0 };

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);
	}

	dp[0][0] = color[0][0];
	dp[0][1] = color[0][1];
	dp[0][2] = color[0][2];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0)
				dp[i][j] = min(color[i][j] + dp[i - 1][j + 1], color[i][j] + dp[i - 1][j + 2]);
			else if (j == 1)
				dp[i][j] = min(color[i][j] + dp[i - 1][j - 1], color[i][j] + dp[i - 1][j + 1]);
			else
				dp[i][j] = min(color[i][j] + dp[i - 1][j - 1], color[i][j] + dp[i - 1][j - 2]);
		}
	}

	if (N == 0) printf("0\n");
	else
		printf("%d\n", min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]));

	return 0;
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[501][501], tri[501][501];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int size, result = 0;

	scanf("%d", &size);
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}

	dp[1][1] = tri[1][1];
	for (int i = 2; i <= size; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			else if (j == i && j != 1)
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1] + tri[i][j], dp[i - 1][j] + tri[i][j]);
		}
	}
	
	for (int i = 1; i <= size; i++) {
		if (result < dp[size][i]) 
			result = dp[size][i];
	}

	printf("%d\n", result);

	return 0;
}
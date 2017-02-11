#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int caseN, dp[31][31] = { 0 }, x, y;

	for (int i = 1; i <= 30; i++) dp[1][i] = i;
	for (int i = 2; i <= 30; i++) {
		for (int j = 2; j <= 30; j++) {
			if (i == j) dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
		}
	}

	scanf("%d", &caseN);
	while (caseN--) {
		scanf("%d %d", &x, &y);
		printf("%d\n", dp[x][y]);
	}

	return 0;
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1000001];

void solve(int x)
{
	dp[1] = 0;

	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) {
			if(dp[i] > dp[i / 2] + 1)
				dp[i] = dp[i / 2] + 1;
		}

		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1)
				dp[i] = dp[i / 3] + 1;
		}
	}

	printf("%d\n", dp[x]);	
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int input;

	scanf("%d", &input);

	solve(input);

	return 0;
}
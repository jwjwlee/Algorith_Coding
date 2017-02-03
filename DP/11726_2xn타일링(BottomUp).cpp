#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[10002];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int n;

	scanf("%d", &n);

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n + 1; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	printf("%d\n", dp[n]);

	return 0;
}
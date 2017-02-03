#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[10002];

int solve(int cur)
{
	if (cur <= 1)
		return cur;

	if (dp[cur] != -1) return dp[cur];

	dp[cur] = (solve(cur - 1) + solve(cur - 2)) % 10007;

	return dp[cur];
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int n;

	for (int i = 0; i < 1002; i++) dp[i] = -1;

	scanf("%d", &n);

	printf("%d\n", solve(n + 1));

	return 0;
}
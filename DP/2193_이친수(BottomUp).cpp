#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int len;
	long long dp[91];

	scanf("%d", &len);
	dp[1] = 1; dp[2] = 1;
	for (int i = 3; i <= len; i++)	dp[i] = dp[i - 2] + dp[i - 1];
	
	printf("%lld\n", dp[len]);

	return 0;
}
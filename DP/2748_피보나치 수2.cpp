#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	long long dp[91], N;

	scanf("%lld", &N);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	printf("%lld\n", dp[N]);
	
	return 0;
}
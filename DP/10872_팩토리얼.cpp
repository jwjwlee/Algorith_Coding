#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	long long dp[13];
	
	scanf("%d", &N);

	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] * i;
	}
	printf("%lld\n", dp[N]);

	return 0;
}
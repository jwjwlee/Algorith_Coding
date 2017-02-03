#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	long long N, dp[101][11] = { 0 }, result = 0;

	scanf("%lld", &N);
	
	for (int i = 1; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) result += dp[N][i];

	printf("%lld\n", result % 1000000000);

	return 0;
}
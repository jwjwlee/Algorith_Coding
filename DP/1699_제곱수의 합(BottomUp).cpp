#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, squ[100001] = { 0 }, dp[100001] = { 0 };

	scanf("%d", &N);
	for (long long i = 1; i <= N; i++) {
		if(dp[i] == 0) dp[i] = i;
		if (i * i <= N) dp[i * i] = 1;
	}
	
	for (long long i = 1; i <= N; i++) {
		for (long long j = 1; j * j <= N; j++) {
			if(i - j * j > 0)
				dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	printf("%d\n", dp[N]);

	return 0;
}
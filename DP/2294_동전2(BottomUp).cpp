#include <iostream>
#include <stdio.h>
using namespace std;

int dp[100001];

int main()
{
	int N, K, val;

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= K; i++) dp[i] = 100001;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &val);
		dp[val] = 1;		
	}

	dp[0] = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j < i; j++) {
			if (dp[j] + dp[i - j] < dp[i])
				dp[i] = dp[j] + dp[i - j];
		}
	}
	
	if (dp[K] == 100001) printf("-1\n");
	else printf("%d\n", dp[K]);

	return 0;
}
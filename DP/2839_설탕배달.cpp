#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 100000

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int N;
	int dp[5001] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i <= 5000; i++) {
		if (i % 3 == 0) dp[i] = i / 3;
		else if (i % 5 == 0) dp[i] = i / 5;
		else dp[i] = INF;
	}


	for (int i = 4; i <= 5000; i++) {
		for (int j = 3; j <= 5000; j++) {
			if (i < j) break;
			if (dp[i] > dp[i - j] + dp[j]) {
				dp[i] = dp[i - j] + dp[j];
			}
		}
	}

	if (dp[N] == INF) printf("-1\n");
	else printf("%d\n", dp[N]);

	return 0;
}
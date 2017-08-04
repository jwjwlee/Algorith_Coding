#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, day[16], pay[16], dp[16] = { 0 };

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &day[i], &pay[i]);
	}

	if(day[N] == 1) dp[N] = pay[N];

	for (int i = N - 1; i > 0; i--) {
		if (i + day[i] - 1 > N) dp[i] = max(dp[i], dp[i + 1]);
		else dp[i] = max(dp[i + 1], pay[i] + dp[i + day[i]]);
	}

	printf("%d\n", dp[1]);
}
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int N;
	int point[301], dp[301] = { 0 };
	
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &point[i]);
	}

	dp[1] = point[1];
	dp[2] = point[1] + point[2];
	dp[3] = max(point[1] + point[3], point[2] + point[3]);
	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 2] + point[i], dp[i - 3] + point[i - 1] + point[i]);
	}

	printf("%d\n", dp[N]);
}
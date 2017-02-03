#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1000001];

int solve(int x)
{
	if (x == 1) return 0;

	int &ret = dp[x];

	if (ret != -1) return ret;

	//셋중 최솟값 저장
	ret = solve(x - 1) + 1;

	if (x % 3 == 0) {
		int val = solve(x / 3) + 1;
		if (val < ret)
			ret = val;
	}

	if (x % 2 == 0) {
		int val = solve(x / 2) + 1;
		if (val < ret)
			ret = val;
	}

	return ret;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int input;

	for (int i = 0; i < 1000001; i++) dp[i] = -1;

	scanf("%d", &input);

	printf("%d\n", solve(input));

	return 0;
}
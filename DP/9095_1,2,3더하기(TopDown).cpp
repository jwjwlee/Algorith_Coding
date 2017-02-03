#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[13];

int solve(int cur)
{
	if (cur == 0) return cur + 1;
	if (cur <= 2) return cur;

	if (dp[cur] != -1) return dp[cur];
	
	dp[cur] = solve(cur - 3) + solve(cur - 2) + solve(cur - 1);

	return dp[cur];
}


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int caseN, input; 

	scanf("%d", &caseN);
	for (int c = 0; c < caseN; c++) {
		for (int i = 0; i < 13; i++) dp[i] = -1;

		scanf("%d", &input);

		printf("%d\n",solve(input));
	}

	return 0;
}
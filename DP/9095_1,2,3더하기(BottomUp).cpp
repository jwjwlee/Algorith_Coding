#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[13];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int caseN, input;

	scanf("%d", &caseN);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int c = 0; c < caseN; c++) {	
		scanf("%d", &input);
		for (int i = 3; i <= input; i++) {
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}
	
		printf("%d\n", dp[input]);
	}

	return 0;
}
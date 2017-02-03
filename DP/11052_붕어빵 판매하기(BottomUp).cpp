#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
#ifdef _CONSOLE
		freopen("input.txt", "r", stdin);
#endif

		int N, price[1001], dp[1001] = { 0 };
		
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &price[i]);
		}

		dp[1] = price[1];
		for (int i = 2; i <= N; i++) {
			dp[i] = price[i];
			for (int j = 2; j <= i; j++) {
				if (dp[j - 1] + price[i - j + 1] > dp[i])
					dp[i] = dp[j - 1] + price[i - j +1];
			}
		}

		printf("%d\n", dp[N]);
		
		return 0;
}
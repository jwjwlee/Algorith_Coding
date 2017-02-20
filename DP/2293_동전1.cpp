#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int coinN, Tot, coin[101] = { 0 }, dp[10001] = { 0 };

	scanf("%d %d", &coinN, &Tot);
	for (int i = 1; i <= coinN; i++) scanf("%d", &coin[i]);

	dp[0] = 1;
	for (int i = 1; i <= coinN; i++) {
		for (int j = 0; j <= Tot; j++) {
			if (j - coin[i] >= 0) {
				dp[j] += dp[j - coin[i]];			
			}
		}
	}
	printf("%d\n", dp[Tot]);

	return 0;
}
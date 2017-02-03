#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1001], price[1001];

int solve(int cur, int N)
{
	if (cur <= 1) return price[cur];
	if (dp[cur] != -1) return dp[cur];

	
}



int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int FishN;

	for (int i = 0; i <= 1001; i++) dp[i] = -1;

	scanf("%d", &FishN);
	for (int i = 1; i <= FishN; i++) {
		scanf("%d", &price[i]);
	}















	return 0;
}
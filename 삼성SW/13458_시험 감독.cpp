#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000000];
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	long long N, major, sub, ans = 0;
	
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	scanf("%lld %lld", &major, &sub);

	for (int i = 0; i < N; i++) {
		arr[i] -= major;
		if (arr[i] < 0) continue;
		if (arr[i] % sub != 0) ans += (arr[i] / sub) + 1;
		else ans += (arr[i] / sub);
	}
	printf("%lld\n", ans + N);

	return 0;
}
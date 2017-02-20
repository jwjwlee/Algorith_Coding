#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int N;

	scanf("%d", &N);
	for (int i = 2; i * i <= N; i++) {
		while (N % i == 0) {
			printf("%d\n", i);
			N = N / i;
		}
	}
	if (N > 1) printf("%d\n", N);

	return 0;
}
#include <iostream>
#include <stdio.h>
using namespace std;

long long cal(long long a, long long  b, long long c)
{
	if (b == 1) return a % c;
	else if (b == 0) return 1;
	else if (b % 2 == 0) {
		long long ret = cal(a, b / 2, c) % c;
		return (ret * ret) % c;
	}
	else {
		return (a % c) * (cal(a, b - 1, c) % c);
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	long long A, B, C, result;

	scanf("%d %d %d", &A, &B, &C);

	printf("%d\n", cal(A, B, C) % C);

	return 0;
}
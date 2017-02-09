#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int N, val, result = 0;
	int pos[10001], p = 0, neg[10001], n = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &val);
		if (val <= 0) neg[++n] = val;
		else pos[++p] = val;
	}

	sort(neg + 1, neg + n + 1);
	sort(pos + 1, pos + p + 1);

	for (int i = 1; i <= n; i++) {
		if (neg[i] == 0) continue;
		if (i == n) {
			result += neg[i];
			break;
		}
		result += neg[i] * neg[i + 1];
		i++;
	}

	for (int i = p; i > 0; i--) {
		if (i == 1) {
			result += pos[i];
			break;
		}
		if (pos[i - 1] == 1) {
			result += pos[i];
			continue;
		}
		result += pos[i] * pos[i - 1];
		i--;
	}

	printf("%d\n", result);

	return 0;
}
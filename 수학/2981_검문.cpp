#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int input[101], index = 0, N;

int gcd(int a, int b)
{
	int temp = -1;

	if (index == N + 1) return a;
	if (a < b) swap(a, b);

	while (temp != 0) {
		if (a == 0) {
			a = b;
			break;
		}
		if (b == 0) break;
		temp = a % b;
		a = b;
		b = temp;
	}

	gcd(a, input[index++]);
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int minval = 1000000001, ret;
	vector<int> result;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
		if (minval > input[i]) minval = input[i];
	}

	for (int i = 0; i < N; i++) {
		input[i] -= minval;
	}

	index = 2;
	ret = gcd(input[0], input[1]);

	for (int i = 1; i * i <= ret; i++) {
		if (ret % i == 0) {
			result.push_back(i);
			result.push_back(ret / i);
		}
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		if (i == result.size() - 1) printf("%d ", result[i]);
		else if (result[i] != result[i+1] && result[i] !=0 && result[i] != 1)
			printf("%d ", result[i]);
	}
	printf("\n");

	return 0;
}
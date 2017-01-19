#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

long long arr[1000001], result[1000001], arrsize;

void something(int jump) {
	int i = 0;
	while (i < arrsize) {
		result[i] = result[i] + arr[jump];
		i = i + jump;
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif 

	long long callnum, jump, confirm, start, end, count = 0;

	scanf("%lld %lld", &arrsize, &callnum);

	for (int i = 0; i < callnum; i++) {
		scanf("%lld", &jump);
		arr[jump]++;
	}

	for (int i = 1; i < arrsize; i++) {
		if(arr[i] != 0)
			something(i);
	}

	for (int i = 1; i < arrsize; i++) {
		result[i] = result[i] + result[i - 1];
	}

	scanf("%lld", &confirm);
	for (int i = 0; i < confirm; i++) {
		scanf("%lld %lld", &start, &end);
		printf("%lld\n", result[end] - result[start - 1]);
	}
}	
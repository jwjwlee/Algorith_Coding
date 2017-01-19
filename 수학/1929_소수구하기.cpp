#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

/*
시간복잡도: O(n^2) ?
공간복잡도: O(n)
*/

int flag[1000001] = { 0 };

int main()
{
	int start, end;

	flag[1] = 1;
	for (int i = 2; i < 1000000; i++) {
		if (flag[i] == 0) {
			for (int j = i * 2; j < 1000000; j += i) {
				flag[j] = 1;
			}
		}
	}

	scanf("%d %d", &start, &end);
	for (int i = start; i <= end; i++) {
		if (flag[i] == 0) printf("%d\n", i);
	}

	return 0;
}
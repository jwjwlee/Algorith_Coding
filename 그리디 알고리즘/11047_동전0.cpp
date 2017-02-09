#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int coinN, totVal, coinVal[11], result = 0;

	scanf("%d %d", &coinN, &totVal);

	for (int i = 1; i <= coinN; i++) {
		scanf("%d", &coinVal[i]);
	}

	while (totVal != 0) {
		for (int i = coinN; i > 0; i--) {
			if (coinVal[i] <= totVal) {
				result++;
				totVal -= coinVal[i];
				break;
			}
		}
	}

	printf("%d\n", result);
	
	return 0;
}
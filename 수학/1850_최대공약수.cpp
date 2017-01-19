#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

/*
시간복잡도: O(n)
공간복잡도: O(1)
*/

int main()
{
	long long A, B, temp = -1;
	
	scanf("%lld %lld", &A, &B);
	
	if (A < B) swap(A, B);

	while (temp != 0) {
		temp = A % B;
		A = B;
		B = temp;
	}

	for (int i = 0; i < A; i++) {
		printf("1");
	}
	printf("\n");

	return 0;
}
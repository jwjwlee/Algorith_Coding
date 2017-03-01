#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	long long a, b, top, bottom;

	scanf("%lld %lld", &a, &b); 

	int back = sqrt(b);
	int front = sqrt(a);
	top = back - front;
	bottom = b - a;
	if (top == 0) {
		printf("0\n");
		return 0;
	}

	long long temp = -1;
	long long A = bottom;
	long long B = top;
	while (temp != 0) {
		temp = A % B;
		A = B;
		B = temp;
	}

	printf("%lld/%lld\n", top / A, bottom / A);

	return 0;
}
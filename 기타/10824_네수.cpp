#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string A, B, C, D;

	cin >> A >> B >> C >> D;
	A.append(B);
	C.append(D);

	long long first = stoll(A);
	long long second = stoll(C);
	printf("%lld\n", first + second);

	return 0;
}
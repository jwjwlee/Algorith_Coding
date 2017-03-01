#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	
	int T, toZero, toOne;
	string A, B;

	scanf("%d", &T);
	while (T--) {
		cin >> A >> B;
		toZero = 0;
		toOne = 0;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] == '1' && A[i] != B[i]) toZero++;
			if (A[i] == '0' && A[i] != B[i]) toOne++;
		}
		printf("%d\n", max(toZero, toOne));
	}

	return 0;
}
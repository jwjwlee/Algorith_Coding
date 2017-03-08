#include <iostream>
#include <stdio.h>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;

int main()
{
	int N, set = 0, input, bit = 0;
	char op[10];
	stack<int> st;

	scanf("%d", &N);
	while (N--) {
		scanf("%s", op);
		if (!strcmp(op, "add")) {
			scanf("%d", &input);
			bit = pow(2, input);
			set |= bit;
		}
		else if (!strcmp(op, "check")) {
			scanf("%d", &input);
			bit = pow(2, input);
			if ((set & bit) == 0) printf("0\n");
			else printf("1\n");
		}
		else if (!strcmp(op, "remove")) {
			scanf("%d", &input);
			bit = pow(2, input);
			set &= ~bit;
		}
		else if (!strcmp(op, "toggle")) {
			scanf("%d", &input);
			bit = pow(2, input);
			set ^= bit;
		}
		else if (!strcmp(op, "all")) {
			set = (1 << 21) - 2;
		}
		else {
			set = 0;
		}
	}
	return 0;
}
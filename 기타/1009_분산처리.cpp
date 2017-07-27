#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int test, a, b;

	scanf("%d", &test);
	while (test--) {
		scanf("%d %d", &a, &b);

		if (a > 9) {
			a -= 10 * (a / 10);
		}

		switch (a)
		{
		case 0:
			printf("10\n");
			break;
		case 1:
			printf("1\n");
			break;
		case 2:
			if (b % 4 == 1) printf("2\n");
			else if (b % 4 == 2) printf("4\n");
			else if (b % 4 == 3) printf("8\n");
			else printf("6\n");
			break;
		case 3:
			if (b % 4 == 1) printf("3\n");
			else if (b % 4 == 2) printf("9\n");
			else if (b % 4 == 3) printf("7\n");
			else printf("1\n");
			break;
		case 4:
			if (b % 2 == 0) printf("6\n");
			else printf("4\n");
			break;
		case 5:
			printf("5\n");
			break;
		case 6:
			printf("6\n");
			break;
		case 7:
			if (b % 4 == 1) printf("7\n");
			else if (b % 4 == 2) printf("9\n");
			else if (b % 4 == 3) printf("3\n");
			else printf("1\n");
			break;
		case 8:
			if (b % 4 == 1) printf("8\n");
			else if (b % 4 == 2) printf("4\n");
			else if (b % 4 == 3) printf("2\n");
			else printf("6\n");
 			break;
		case 9:
			if (b % 2 == 0) printf("1\n");
			else printf("9\n");
			break;
		}
	}
}
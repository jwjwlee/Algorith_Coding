#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int col, row;

	scanf("%d %d", &col, &row);

	if (col == 1) printf("1\n");	
	else if (col == 2) {
		if (row == 1 || row == 2) printf("1\n");
		else if (row >= 3 && row < 5) printf("2\n");
		else if (row >= 5 && row < 7) printf("3\n");
		else printf("4\n");
	}
	else {
		if (row < 7) printf("%d\n", min(4, row));
		else printf("%d\n", row - 2);
	}
	
	return 0;
}
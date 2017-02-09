#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int wom, men, intern, tot, result = 0;

	scanf("%d %d %d", &wom, &men, &intern);

	while (1) {
		tot = wom + men;
		if (tot < intern) break;
		if (wom < 0 || men < 0) break;
		wom -= 2;
		men -= 1;
		result++;
	}
	
	printf("%d\n", result - 1);

	return 0;
}
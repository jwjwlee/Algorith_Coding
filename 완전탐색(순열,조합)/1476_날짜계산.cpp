#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

/*
시간복잡도 : O(1)
공간복잡도 : O(1)
*/

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif 

	int Earth, Sun, Moon, count = 0;
	int year[4] = { 1, };

	scanf("%d %d %d", &Earth, &Sun, &Moon);

	while (year[1] != Earth || year[2] != Sun || year[3] != Moon) {
		year[1]++;
		if (year[1] == 16) year[1] = 1;
		
		year[2]++;
		if (year[2] == 29) year[2] = 1;
		
		year[3]++;
		if (year[3] == 20) year[3] = 1;

		count++;
	}

	printf("%d\n", count);

	return 0;
}
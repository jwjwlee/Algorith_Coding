#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int line, val, count = 0, n = 0, flag = 0;
	int tab[1001], correct[1001], edit[1001];
	bool edited;

	scanf("%d", &line);
	for (int i = 0; i < line; i++) scanf("%d", &tab[i]);
	for (int i = 0; i < line; i++) scanf("%d", &correct[i]);
	for (int i = 0; i < line; i++) edit[i] = correct[i] - tab[i];

	while (1) {
		
		flag = 0;
		for (int i = 0; i < line; i++) {
			if (edit[i] != 0) flag = -1;
		}
		if (flag == 0) break;

		//음수
		edited = false;
		for (int i = 0; i < line; i++) {
			if (edit[i] < 0) {
				edit[i]++;
				edited = true;
				if (edit[i + 1] >= 0) break;
			}
		}
		if(edited == true) count++;

		//양수
		edited = false;
		for (int i = 0; i < line; i++) {
			if (edit[i] > 0) {
				edit[i]--;
				edited = true;
				if (edit[i + 1] <= 0) break;
			}
		}
		if (edited == true) count++;
	}

	printf("%d\n", count);

	return 0;
}
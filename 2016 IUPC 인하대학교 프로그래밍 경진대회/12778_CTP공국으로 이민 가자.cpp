#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int T, num, i_input;
	char type, c_input;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %c", &num, &type);
		switch (type)
		{
		case 'C':
			for (int i = 0; i < num; i++) {
				getchar();
				scanf("%c", &c_input);
				printf("%d ", c_input - 'A' + 1);
			}
			printf("\n");
			break;
		case 'N':
			for (int i = 0; i < num; i++) {
				getchar();
				scanf("%d", &i_input);
				printf("%c ", i_input + 64);
			}
			printf("\n");
			break;
		}
	}

	return 0;
}
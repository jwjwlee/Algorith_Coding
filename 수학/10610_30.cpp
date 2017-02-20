#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

char a[100001];
int main()
{
	scanf("%s", &a);

	int len = strlen(a);
	sort(a, a + len);
	if (a[0] != '0') {
		printf("-1\n");
		return 0;
	}

	int temp = 0;
	for (int j = 0; j < len; j++) {
		temp += a[j] - '0';
	}

	if (temp % 3 != 0) {
		printf("-1\n");
		return 0;
	}
	
	for (int j = len - 1; j >= 0; j--) {
		printf("%c", a[j]);
	}
	printf("\n");
	
	return 0;
}
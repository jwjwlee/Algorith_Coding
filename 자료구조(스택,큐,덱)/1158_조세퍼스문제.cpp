#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

/*
시간복잡도 : O(n)
공간복잡도 : O(n)
*/

int main()
{
	int num, M, count, n = 0;
	
	scanf("%d %d", &num, &M);

	deque<int> de;
	deque<int> result;

	for (int i = 1; i <= num; i++) {
		de.push_back(i);
	}

	count = 1;
	for (int i = 1; i <= num*M; i++) {
		if (count % M == 0) {
			result.push_back(de.front());
			de.pop_front();
		}
		else {
			de.push_back(de.front());
			de.pop_front();
		}
		count++;
	}

	printf("<");
	for (int i = 1; i <= num; i++) {		
		if (i == num) {
			printf("%d", result.front());
			result.pop_front();
		}
		else {
			printf("%d, ", result.front());
			result.pop_front();
		}
	}

	printf(">\n");

	return 0;
}
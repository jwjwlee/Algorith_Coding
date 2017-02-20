#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int N, input;
	priority_queue<int> pq;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (input == 0) {
			if (pq.empty()) printf("0\n");
			else {
				printf("%d\n", -pq.top());
				pq.pop();
			}
		}
		else pq.push(-input);
	}

	return 0;
}
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

int visit[1000001] = { 0 };
queue<pair<int ,int>> q;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int total, cur, dest, up, down, temp, temp2;

	scanf("%d %d %d %d %d", &total, &cur, &dest, &up, &down);
	
	visit[cur] = 1;
	q.push(make_pair(cur,0));

	while (!q.empty()) {
		temp = q.front().first;
		temp2 = q.front().second;
		q.pop();
				
		if (temp + up <= 1000000) {
			if (visit[temp + up] == 0) {
				visit[temp + up] = temp2 + 1;
				q.push(make_pair(temp + up, temp2 + 1));
			}
		}
		if (temp - down > 0) {
			if (visit[temp - down] == 0) {
				visit[temp - down] = temp2 + 1;
				q.push(make_pair(temp - down, temp2 + 1));
			}
		}

		if (temp == dest) break;
	}
	
	if (visit[dest] == 0) printf("use the stairs\n");
	else if (cur == dest) printf("0\n");
	else
		printf("%d\n", visit[dest]);

	return 0;
}
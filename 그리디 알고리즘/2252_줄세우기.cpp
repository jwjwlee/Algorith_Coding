#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int visit[32001] = { 0 }, flag[32001] = { 0 };
vector<int> vec[32001];

void DFS(int x)
{
	if (flag[x] == 0) printf("%d ", x);
	else return;
	for (int i = 0; i < vec[x].size(); i++) {
			flag[vec[x][i]]--;
			visit[vec[x][i]] = 1;
			DFS(vec[x][i]);
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int N, comp, st1, st2;

	scanf("%d %d", &N, &comp);
	for (int i = 0; i < comp; i++) {
		scanf("%d %d", &st1, &st2);
		flag[st2]++;
		vec[st1].push_back(st2);
	}

	for (int i = 1; i <= N; i++) {
		if (flag[i] == 0 && visit[i] != 1) DFS(i);
	}
	printf("\n");
	return 0;
}
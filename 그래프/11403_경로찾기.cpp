#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v[101];
int path[101][101] = { 0 }, visit[101] = { 0 };

void DFS(int cur, int start)
{
	for (int i = 0; i < v[cur].size(); i++) {
		if (visit[v[cur][i]] == 0) {
			path[start][v[cur][i]] = 1;
			visit[v[cur][i]] = 1;
			DFS(v[cur][i], start);		
		}
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif	

	int N;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			scanf("%d", &path[i][j]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			if (path[i][j] == 1)
				v[i].push_back(j);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[j] = 0;
		}
		DFS(i, i);
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}

	return 0;
}
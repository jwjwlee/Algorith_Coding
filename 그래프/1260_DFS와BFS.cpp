#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
시간복잡도 : O(V+E)
공간 복잡도 : O(V+E)
*/

vector<int> vec[1001];
queue<int> que;
int visited[1001] = { 0 };
int visited2[1001] = { 0 };

void DFS(int x)
{
	visited[x] = 1;
	printf("%d ", x);
	for (int i = 0; i < vec[x].size(); i++) {
		if (visited[vec[x][i]] == 0)
			DFS(vec[x][i]);			
	}
}

void BFS(int x)
{
	que.push(x);
	visited2[x] = 1;

	while (!que.empty()) {
		int temp = que.front();
		que.pop();
		printf("%d ", temp);
		for (int i = 0; i < vec[temp].size(); i++) {
			if (visited2[vec[temp][i]] == 0) {
				visited2[vec[temp][i]] = 1;
				que.push(vec[temp][i]);
			}
		}
	}
}

int main()
{
	int ver_num, edge, start, vertex1, vertex2;

	scanf("%d %d %d", &ver_num, &edge, &start);

	for (int i = 0; i < edge; i++) {
		scanf("%d %d", &vertex1, &vertex2);
		vec[vertex1].push_back(vertex2);
		vec[vertex2].push_back(vertex1);
	}

	for (int i = 0; i < ver_num; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	DFS(start);
	printf("\n");
	BFS(start);
	printf("\n");

	return 0;
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> vec[100001];
queue<int> que;
int parent[100001];
int visited[100001];

void BFS(int x)
{
	que.push(x);
	visited[x] = 1;

	while (!que.empty()) {
		int temp = que.front();
		que.pop();
		for (int i = 0; i < vec[temp].size(); i++) {
			if (visited[vec[temp][i]] == 0) {
				visited[vec[temp][i]] = 1;
				parent[vec[temp][i]] = temp;
				que.push(vec[temp][i]);
			}
		}
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif 

	int nodenum, vertex1, vertex2;

	scanf("%d", &nodenum);
	for (int i = 0; i < nodenum; i++) {
		scanf("%d %d", &vertex1, &vertex2);
		vec[vertex1].push_back(vertex2);
		vec[vertex2].push_back(vertex1);
	}

	BFS(1);

	for (int i = 2; i <= nodenum; i++) {
		printf("%d\n", parent[i]);
	}

	return 0;
}
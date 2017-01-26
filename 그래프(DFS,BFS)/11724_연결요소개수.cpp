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
int visited[1001];

void DFS(int x)
{
	visited[x] = 1;

	for (int i = 0; i < vec[x].size(); i++) {
		if (visited[vec[x][i]] == 0)
			DFS(vec[x][i]);
	}
}

int main()
{
	int ver_num, edge, vertex1, vertex2, count = 0;
	scanf("%d %d", &ver_num, &edge);

	for (int i = 0; i < edge; i++) {
		scanf("%d %d", &vertex1, &vertex2);
		vec[vertex1].push_back(vertex2);
		vec[vertex2].push_back(vertex1);
	}

	for (int i = 1; i <= ver_num; i++) {
		if (visited[i] == 0) {
			DFS(i);
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}
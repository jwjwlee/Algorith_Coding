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
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif 

	int case_num, ver_num, edge, vertex, count = 0;
	scanf("%d", &case_num);
	for (int c = 0; c < case_num; c++) {
		count = 0;
		scanf("%d", &ver_num);

		for (int i = 1; i <= ver_num; i++) {
			scanf("%d", &vertex);
			vec[i].push_back(vertex);
			vec[vertex].push_back(i);
		}

		for (int i = 1; i <= ver_num; i++) {
			if (visited[i] == 0) {
				DFS(i);
				count++;
			}
		}

		printf("%d\n", count);
		
		for (int i = 1; i <= ver_num; i++) {
			vec[i].clear();
			visited[i] = 0;
		}
	}
	return 0;
}
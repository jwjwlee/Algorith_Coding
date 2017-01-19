#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> vec[100001];
int visited[100001], distarr[100001];
int val = 0;

void DFS(int x)
{
	visited[x] = 1;

	for (int i = 0; i < vec[x].size(); i++) {
		if (visited[vec[x][i].first] == 0) {
			val += vec[x][i].second;
			distarr[vec[x][i].first] = val;

			DFS(vec[x][i].first);

			val -= vec[x][i].second;
		}
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif 

	int vertexN, vertex, temp, input, flag, dist, maxchild, maxlen = 0, result = 0, root;

	scanf("%d", &vertexN);
	for (int i = 0; i < vertexN; i++) {
		scanf("%d", &vertex);
		input = 0;
		flag = 1;

		while (input != -1) {
			scanf("%d", &input);
		
			if (flag % 2 == 0) {
				vec[vertex].push_back(make_pair(temp, input));
			}
			else {
				temp = input;
			}
			flag++;
		}
	}

	for (int i = 1; i <= vertexN; i++) {
		if (vec[i].size() == 1) {
			root = i;
			break;
		}
	}
	
	//루트에서 가장 먼 자식탐색
	DFS(root);
	for (int i = 1; i <= vertexN; i++) {
		if (maxlen < distarr[i]) {
			maxlen = distarr[i];
			maxchild = i;
		}
	}

	//초기화
	for (int i = 1; i <= vertexN; i++) {
		distarr[i] = 0;
		visited[i] = 0;
	}

	//가장 먼 자식에서 가장 먼 정점 탐색
	DFS(maxchild);
	for (int i = 1; i <= vertexN; i++) {
		if (distarr[i] > result)
			result = distarr[i];
	}

	printf("%d\n", result);
	return 0;

	return 0;
}
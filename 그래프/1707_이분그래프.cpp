#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/*
시간복잡도 : O()
공간 복잡도 : O()
*/

vector<int> vec[20001];
int visited[20001];
queue<int> que;

int cnt = 0;
string BFS(int x)
{
	que.push(x);
	visited[x] = 1;

	while (!que.empty()) {
		int temp = que.front();
		que.pop();


		for (int i = 0; i < vec[temp].size(); i++) {
			if (visited[vec[temp][i]] == 0) {
				visited[vec[temp][i]] = visited[temp] + 1;
				que.push(vec[temp][i]);
			}
				
			else {
				if (((visited[vec[temp][i]] + 1) % 2) != (visited[temp] % 2)) {
					return "NO";
				}

			}


		}		
	}
	return "YES";
}


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif 

	int case_num, ver_num, edge, vertex1, vertex2;
	string result;

	scanf("%d", &case_num);
	for (int c = 0; c < case_num; c++) {
		scanf("%d %d", &ver_num, &edge);

		for (int i = 1; i <= ver_num; i++) {
			vec[i].clear();
			visited[i] = 0;
		}

		while (!que.empty()) {
			que.pop();
		}

		for (int i = 0; i < edge; i++) {
			scanf("%d %d", &vertex1, &vertex2);
			vec[vertex1].push_back(vertex2);
			vec[vertex2].push_back(vertex1);
		}

		for (int i = 1; i <= ver_num; i++) {
			if (visited[i] == 0) {
				cnt = 1;
				result = BFS(i);
				if (result == "NO") break;
			}
		}
	
		cout << result << "\n";
	}

	return 0;
}
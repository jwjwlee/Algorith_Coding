#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

int visit[10001] = { 0 }, arr[10001] = { 0 }, loc[4];
queue<pair<int, int>> q;

void BFS(int x, int y)
{
	int temp, index, temp2, temp3;
	
	q.push(make_pair(x,0));
	visit[x] = 1;

	while (!q.empty()) {
		temp = q.front().first;
		temp2 = q.front().second;
		q.pop();
		
		//각자릿수 저장
		temp3 = temp;
		for (int i = 3; i >= 0; i--) {
			loc[i] = temp3 / pow(10, i);
			temp3 -= loc[i] * pow(10, i);
		}
		
		//숫자변환
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < 10; j++) {
				if (j >= 10 - loc[i]) index = temp - pow(10, i) * (10 - j);
				else index = temp + pow(10, i) * j;
				//
				if (index >= 10000 || index < 1000) continue;
				
				if (visit[index] == 0 && arr[index] == 0) {
					visit[index] = temp2 + 1;
					q.push(make_pair(index, temp2 + 1));
					if (index == y) return;				
				}
			}
		}
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int caseN, init, dest;
	
	scanf("%d", &caseN);

	//소수 배열
	for (int i = 2; i < 10000; i++) {
		if (arr[i] == 0)
			for (int j = i * 2; j < 10000; j += i) {
				arr[j] = 1;
			}
	}

	for (int c = 0; c < caseN; c++) {

		scanf("%d %d", &init, &dest);

		while (!q.empty()) {
			q.pop();
		}

		for (int i = 0; i < 10000; i++) {
			visit[i] = 0;
		}

		BFS(init, dest);

		if (init == dest) printf("0\n");
		else if (visit[dest] == 0) printf("Impossible\n");
		else
			printf("%d\n", visit[dest]);

	}

	return 0;
}
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int group_map[102][102];
int dist_map[102][102];
queue<pair<int, int>> q;


void group_BFS(int init_x, int init_y, int group)
{
	int x, y;

	group_map[init_x][init_y] = group;
	q.push(make_pair(init_x, init_y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (group_map[x][y + 1] == 1) {
			group_map[x][y + 1] = group;
			q.push(make_pair(x, y + 1));
		}
		if (group_map[x + 1][y] == 1) {
			group_map[x + 1][y] = group;
			q.push(make_pair(x + 1, y));
		}
		if (group_map[x][y - 1] == 1) {
			group_map[x][y - 1] = group;
			q.push(make_pair(x, y - 1));
		}
		if (group_map[x - 1][y] == 1) {
			group_map[x - 1][y] = group;
			q.push(make_pair(x - 1, y));
		}
	}
}

void extend_BFS()
{
	int x, y;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (group_map[x][y + 1] == 0) {
			group_map[x][y + 1] = group_map[x][y];
			q.push(make_pair(x, y + 1));
		}
		if (group_map[x + 1][y] == 0) {
			group_map[x + 1][y] = group_map[x][y];
			q.push(make_pair(x + 1, y));
		}
		if (group_map[x][y - 1] == 0) {
			group_map[x][y - 1] = group_map[x][y];
			q.push(make_pair(x, y - 1));
		}
		if (group_map[x - 1][y] == 0) {
			group_map[x - 1][y] = group_map[x][y];
			q.push(make_pair(x - 1, y));
		}
	}
}

void dist_BFS()
{
	int x, y;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (dist_map[x][y + 1] == 0) {
			dist_map[x][y + 1] = dist_map[x][y] + 1;
			q.push(make_pair(x, y + 1));
		}
		if (dist_map[x + 1][y] == 0) {
			dist_map[x + 1][y] = dist_map[x][y] + 1;
			q.push(make_pair(x + 1, y));
		}
		if (dist_map[x][y - 1] == 0) {
			dist_map[x][y - 1] = dist_map[x][y] + 1;
			q.push(make_pair(x, y - 1));
		}
		if (dist_map[x - 1][y] == 0) {
			dist_map[x - 1][y] = dist_map[x][y] + 1;
			q.push(make_pair(x - 1, y));
		}
	}
}

int main()
{
	int size, val, groupN, min = 9999;
	scanf("%d", &size);

	//초기화
	for (int i = 0; i <= size + 1; i++) {
		for (int j = 0; j <= size + 1; j++) {
			dist_map[i][j] = -1;
			group_map[i][j] = -1;
		}
	}

	//입력
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			scanf("%d", &val);
			group_map[i][j] = val;
			dist_map[i][j] = val;
		}
	}

	//그룹 지도 만들기
	groupN = 2;
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (group_map[i][j] == 1) {
				group_BFS(i, j, groupN);
				groupN++;
			}
		}
	}

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (dist_map[i][j] != 0)
				q.push(make_pair(i, j));
		}
	}

	extend_BFS();

	//거리 지도 만들기
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (dist_map[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
	dist_BFS();

	//그룹과 거리지도 비교하여 최소다리길이 검색
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (group_map[i][j] != group_map[i][j + 1] && group_map[i][j + 1] != -1)
				if (min > dist_map[i][j] - 1 + dist_map[i][j + 1] - 1)
					min = dist_map[i][j] + dist_map[i][j + 1] - 2;
			if (group_map[i][j] != group_map[i + 1][j] && group_map[i + 1][j] != -1)
				if (min > dist_map[i][j] - 1 + dist_map[i + 1][j] - 1)
					min = dist_map[i][j] + dist_map[i + 1][j] - 2;
		}
	}

	printf("%d\n", min);

	return 0;
}
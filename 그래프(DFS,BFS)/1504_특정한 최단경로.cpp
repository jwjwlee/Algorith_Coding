#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int adj[801][801];

void floyd(int num)
{
	for (int k = 1; k <= num; k++) {
		for (int i = 1; i <= num; i++) {
			for (int j = 1; j <= num; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif 

	int ver_num, edge, vertex1, vertex2, distance, via1, via2, result;
	scanf("%d %d", &ver_num, &edge);

	for (int i = 1; i <= ver_num; i++)
		for (int j = 1; j <= ver_num; j++) {
			adj[i][j] = 100000000;
			adj[i][i] = 0;
		}

	for (int i = 0; i < edge; i++) {
		scanf("%d %d %d", &vertex1, &vertex2, &distance);
		adj[vertex1][vertex2] = distance;
		adj[vertex2][vertex1] = distance;
	}
	scanf("%d %d", &via1, &via2);

	floyd(ver_num);

	result = min(adj[1][via1] + adj[via1][via2] + adj[via2][ver_num], adj[1][via2] + adj[via2][via1] + adj[via1][ver_num]);
	if (result >= 100000000) printf("-1\n");
	else
		printf("%d\n", result);

	return 0;
}
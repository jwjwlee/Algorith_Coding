#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 1000000000
using namespace std;

struct info
{
	int S, E, time;
};


int main()
{
	int T, N, road, hole, cost, dist[501];

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &N, &road, &hole);

		vector<info> v(2*road + hole);
		for (int i = 0; i < road; i++) {
			scanf("%d %d %d", &v[i].S, &v[i].E, &v[i].time);
			v[i + road].S = v[i].E;
			v[i + road].E = v[i].S;
			v[i + road].time = v[i].time;
		}

		for (int i = 2*road; i < 2*road + hole; i++) {
			scanf("%d %d %d", &v[i].S, &v[i].E, &cost);
			v[i].time = -cost;
		}

		for (int i = 1; i <= N; i++) dist[i] = MAX;

		dist[1] = 0;
		bool flag = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < 2*road + hole; j++) {
				int S = v[j].S;
				int E = v[j].E;
				int C = v[j].time;

				if (dist[S] != MAX && dist[E] > dist[S] + C) {
					dist[E] = dist[S] + C;
					if (N == i) flag = true;
				}
			}
		}	

		if(flag == true) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
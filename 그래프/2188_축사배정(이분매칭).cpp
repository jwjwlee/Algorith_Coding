//이분 매칭
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int N, M, S, want;
vector<int> v[202];
bool visit[202];
int connect[202];

bool dfs(int n)
{
	if (visit[n]) return false;
	
	visit[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		//매칭 되어있지 않거나, 이미 앉아있는 놈을 다시 탐색하여 다른 곳에 앉힐 수 있다면
		if (!connect[v[n][i]] || dfs(connect[v[n][i]])) {
			connect[v[n][i]] = n;
			return true;
		}
	}

	return false;
}

int main()
{
	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &S);
		while (S--) {
			scanf("%d", &want);
			v[i].push_back(want);
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		fill_n(visit, 202, false);
		if (dfs(i)) ans++;
	}
	printf("%d\n", ans);

	return 0;
}
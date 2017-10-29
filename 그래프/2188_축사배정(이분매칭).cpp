//�̺� ��Ī
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
		//��Ī �Ǿ����� �ʰų�, �̹� �ɾ��ִ� ���� �ٽ� Ž���Ͽ� �ٸ� ���� ���� �� �ִٸ�
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
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int set[1000001];
int Find(int x)
{
	if (x == set[x]) return x;
	else return set[x] = Find(set[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if(x != y) set[y] = x;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m, op, a, b;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) set[i] = i;
	while (m--) {
		scanf("%d", &op);
		if (op == 0) {
			scanf("%d %d", &a, &b);
			Union(a, b);
		}
		else {
			scanf("%d %d", &a, &b);
			if (Find(a) == Find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
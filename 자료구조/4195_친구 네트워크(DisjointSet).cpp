#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int set[200010];
int Find(int x)
{
	if (set[x] == x) return x;
	else return set[x] = Find(set[x]);
}

int main()
{
	int T, relation, num[200010];
	char F1[21], F2[21];
	map<string, int> m;
	map<string, int>::iterator it1;
	map<string, int>::iterator it2;

	scanf("%d", &T);
	while (T--) {
		int val = 0;
		scanf("%d", &relation);
		m.clear();
		for (int i = 1; i <= relation * 2; i++) {
			num[i] = 1;
			set[i] = i;
		}
		for (int i = 0; i < relation; i++) {
			scanf("%s %s", F1, F2);
			it1 = m.find(F1);
			it2 = m.find(F2);
			if (it1 == m.end()) m.insert(pair<string, int>(F1, ++val));
			if (it2 == m.end()) m.insert(pair<string, int>(F2, ++val));
			
			int a = Find(m[F1]);
			int b = Find(m[F2]);

			if (a == b) {
				printf("%d\n", num[a]);
			}
			else if (a > b) {
				num[b] += num[a];
				set[a] = b;
				printf("%d\n", num[b]);
			}
			else {
				num[a] += num[b];
				set[b] = a;
				printf("%d\n", num[a]);
			}
		}
	}
	return 0;
}
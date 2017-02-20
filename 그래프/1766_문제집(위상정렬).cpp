#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int cnt[32001];
vector<int> v[32001];
priority_queue<int> pq;

int main()
{
	int N, info, A, B;
	
	scanf("%d %d", &N, &info);
	for (int i = 0; i < info; i++) {
		scanf("%d %d", &A, &B);
		v[A].push_back(B);
		cnt[B]++;
	}

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) pq.push(-i);
	}

	while (!pq.empty()) {
		int temp = -pq.top();

		printf("%d ", -pq.top());
		pq.pop();
		for (int i = 0; i < v[temp].size(); i++) {
			cnt[v[temp][i]]--;
			if (cnt[v[temp][i]] == 0)
				pq.push(-v[temp][i]);
		}	
	}	
	printf("\n");

	return 0;
}
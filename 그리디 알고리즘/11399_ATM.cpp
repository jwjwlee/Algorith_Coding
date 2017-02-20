#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, time, result;
	vector<int> v;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &time);
		v.push_back(time);
	}

	sort(v.begin(), v.end());

	result = v[0];
	for (int i = 1; i < v.size(); i++) {
		v[i] += v[i - 1];
		result += v[i];
	}
	printf("%d\n", result);
	
	return 0;
}
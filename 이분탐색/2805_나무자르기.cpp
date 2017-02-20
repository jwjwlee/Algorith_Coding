#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int treeN, want, height, minH = 0, maxH = 0;
	long long result = 0;
	vector<int> v;

	scanf("%d %d", &treeN, &want);
	for (int i = 0; i < treeN; i++) {
		scanf("%d", &height);
		maxH = max(maxH, height);
		v.push_back(height);
	}

	while (minH + 1 < maxH) {
		result = 0;
		int mid = (minH + maxH) / 2;

		for (int i = 0; i < treeN; i++) {
			if(v[i] - mid > 0)
				result += v[i] - mid;
		}

		if (result >= want) minH = mid;
		else maxH = mid;		
	}
	printf("%d\n", minH);
	
	return 0;
}
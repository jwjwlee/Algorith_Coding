#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	long long LanN, want, len, maxL = 0, minL = 0, result;
	vector<int> v;

	scanf("%lld %lld", &LanN, &want);
	for (int i = 0; i < LanN; i++) {
		scanf("%lld", &len);
		maxL = max(maxL, len);
		v.push_back(len);
	}

	while (minL <= maxL) {
		result = 0;
		long long mid = (minL + maxL) / 2;

		for (int i = 0; i < LanN; i++) {
			result += v[i] / mid;
		}
		
		if (result >= want) minL = mid + 1;	
		else maxL = mid - 1;
	}
	printf("%lld\n", minL - 1);

	return 0;
}
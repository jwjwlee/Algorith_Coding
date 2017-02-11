#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, val, result = 0;
	vector<int> A, B;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &val);
		A.push_back(val);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &val);
		B.push_back(val);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());
	
	for (int i = 0; i < N; i++) result += A[i] * B[i];
	
	printf("%d\n", result);

	return 0;
}
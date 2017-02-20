#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main()
{
	int N, M, input, mini, maxi;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		v.push_back(input);	
	}
	sort(v.begin(), v.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &input);
		
		mini = 0;
		maxi = N - 1;
		bool flag = false;
		while (mini <= maxi) {
			int mid = (mini + maxi) / 2;	
			if (v[mid] == input) flag = true;
			if (v[mid] > input) maxi = mid - 1;
			else mini = mid + 1;
		}
		if (flag == true) printf("1\n");
		else printf("0\n");		
	}

	return 0;
}
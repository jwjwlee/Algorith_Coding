#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> v;
bool cmp(string a, string b)
{
	if (a.size() < b.size()) return true;
	if (a.size() == b.size()) {
		if (a < b) return true;
		else return false;
	}
	else return false;
}

int main()
{
	int N;
	string input;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (i != 0) {
			if (v[i] == v[i - 1]) continue;
		}
		cout << v[i];
		printf("\n");
	}

	return 0;
}
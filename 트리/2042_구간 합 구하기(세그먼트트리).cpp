#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

long long make_tree(vector<long long> &arr, vector<long long> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	else
		return tree[node] = make_tree(arr, tree, node * 2, start, (start + end) / 2)
		+ make_tree(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

long long section_sum(vector<long long> &tree, int node, int start, int end, int first, int second)
{
	if (end < first || second < start) return 0;
	if (first <= start && end <= second) return tree[node];

	return section_sum(tree, node * 2, start, (start + end) / 2, first, second)
		+ section_sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, first, second);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long gap)
{
	if (index < start || index > end) return;
	tree[node] += gap;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, gap);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, gap);
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	long long Num, changeN, sumN, input, flag, first, second, gap;
	vector<long long> val, tree;

	scanf("%lld %lld %lld", &Num, &changeN, &sumN);
	for (int i = 0; i < Num; i++) {
		scanf("%lld", &input);
		val.push_back(input);
	}

	for (int i = 0; i <= 2 * Num - 1; i++) {
		tree.push_back(0);
	}

	make_tree(val, tree, 1, 0, val.size() - 1);

	for (int i = 0; i < changeN + sumN; i++) {
		scanf("%lld %lld %lld", &flag, &first, &second);
		if (flag == 1) {
			gap = second - val[first - 1];
			val[first - 1] = second;
			update(tree, 1, 0, val.size() - 1, first - 1, gap);
		}
		if (flag == 2)
			printf("%lld\n", section_sum(tree, 1, 0, val.size() - 1, first - 1, second - 1));
	}
	
	return 0;
}
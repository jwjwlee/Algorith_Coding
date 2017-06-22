#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> v;
char ans[15];
int L, C;

void process(int ansIndex, int charIndex)
{
	int vow = 0, con = 0;
	if (ansIndex == L) {
		for (int i = 0; i < L; i++) {
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				vow++;
			else
				con++;
		}
		if (vow >= 1 && con >= 2) {
			printf("%s\n", ans);
		}
		return;
	}
	if (charIndex >= C) return;
	
	ans[ansIndex] = v[charIndex];
	process(ansIndex + 1, charIndex + 1);
	process(ansIndex, charIndex + 1);
}



int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	char input;	
	
	scanf("%d %d", &L, &C);
	int vindex = 0, cindex = 0;
	for (int i = 0; i < C; i++) {
		getchar();
		scanf("%c", &input);
		v.push_back(input);
	}

	sort(v.begin(), v.end());
	process(0, 0);

	return 0;


}
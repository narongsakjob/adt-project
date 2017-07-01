#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n, m, cases, test[10002];
char s[10002];
string res[10002];

int solve(int i, int depth) {
	if (i < 0) return -1;
	m = max(m, depth);
	if (test[depth] != cases) {
		test[depth] = cases;
		res[depth] = "";
	}
	res[depth] += s[i];
	if ('a' <= s[i] && s[i] <= 'z')
		return i - 1;
	i = solve(i - 1, depth + 1);
	i = solve(i, depth + 1);
	return i;
}

int main() {
  
  for (scanf(" %d ", &cases); cases--; ) {
		gets(s);
		n = strlen(s); m = 0;
		solve(n - 1, 0);
    for (int i = (m+1) - 1; i >= 0; i--)cout << res[i];
		putchar('\n');
	}

}

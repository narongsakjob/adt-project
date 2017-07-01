#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int step[12] = {}, ans[12] = {0, 1};

void Backtracking( int now ) {
	if( now >= 12 )return;
	if( now > 0 ) {
		int i, f = 1, c = now;
		int tmp = 2, count = 2;

		for( i = 2; i <= c+1; i++ ) f *= i;

    for(i = 0; i < c-1; i++) {

			if(step[i] == step[i+1] && step[i] == 2)
				count++, tmp *= count;
			else {
				if(step[i] == 2)
					f /= tmp, tmp = 2, count = 2;
			}

    }

		if(step[i] == 2) f /= tmp, tmp = 2, count = 2;
		ans[c+1] += f;

  }

	step[now] = 0;
	Backtracking(now+1);
	step[now] = 2;
	Backtracking(now+1);

}
int main() {
	int t, n;
	Backtracking(0);
	cin >> t;
	while( t-- ) {
	   cin >> n;
     cout << ans[n] << endl;
	}
}

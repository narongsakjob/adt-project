#include <iostream>
#include <algorithm>

using namespace std;

int Compare(long long a, long long b, long long c, long long d) {
    if (a==c && b==d) return 0;
    return (a*d > b*c)? 1: -1;
}

main() {
    int n, m;
    while (cin >> n >> m ) {
        if (n==1 && m==1) break;
        int a = 0, b = 1, c = 1, d = 0;
        while (true) {
            int x = a + c, y = b + d;
            int cmp = Compare(n, m, x, y);
            if (cmp==0) break;
            if (cmp==1) {
                cout << "R";
                a = x;
                b = y;
            }
            else {
              cout << "L";
                c = x;
                d = y;
            }
        }
        cout << endl;
    }
}

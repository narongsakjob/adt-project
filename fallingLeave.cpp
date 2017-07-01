#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int Min, Max, ans[101];

void ReadTree(int p) {
    int val;
    cin >> val;
    if (val==-1) return;
    ans[p] += val;
    Min = min(Min, p);
    Max = max(Max, p);
    ReadTree(p-1);
    ReadTree(p+1);
}

int main() {
    int Case = 0, val;
    while (cin >> val && val!=-1) {

        for( int i=0 ; i<101; i++ )ans[i] = 0;
        Min = Max = 101/2;
        ans[101/2] = val;
        ReadTree((101/2)-1);
        ReadTree((101/2)+1);
        cout << "Case "<<++Case << ":"<< endl;
        cout << ans[Min] ;
        for( int i = Min+1; i <= Max; i++ ) cout << " "<< ans[i];
        cout << endl;
        cout << endl;

    }
}

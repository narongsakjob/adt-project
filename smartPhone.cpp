#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n,m,val;
    cin >> n >> m;
    int Ci[n],Mi[n],Si[n],Pi[n];
    set<pair<int,int> > typeOne;
    set<pair<int,int> > typeTwo;
    set<pair<int,int> > typeThree;

    for( int i=0; i<n; i++ ) {
        for( int j=0; j<4; j++ ) {
            cin >> val;
            pair<int,int> p;
            p.first = val;
            p.second = i;
            if( j == 0 ) {
                Ci[i] = val;
                typeOne.insert(p);
            }
            else if( j == 1 ) {
                Mi[i] = val;
                typeTwo.insert(p);
            }
            else if( j == 2 ) {
                Si[i] = val;
                typeThree.insert(p);
            }
            else Pi[i] = val;
        }
    }
    for( int i=0; i<m; i++ ) {
        int xj, yj;
        cin >> xj >> yj;
        xj--;
        set<pair<int,int> >::iterator it;
        if(xj == 0)       it = typeOne.lower_bound( make_pair(yj,-1) );
        else if(xj == 1)  it = typeTwo.lower_bound( make_pair(yj,-1) );
        else if(xj == 2)  it = typeThree.lower_bound( make_pair(yj,-1) );

        pair<int,int> p = *it;
        if( it == typeOne.end() || it == typeTwo.end() || it == typeThree.end() ) cout << '0' << endl;
        else {
            cout << Pi[p.second] << endl;
            int val1,val2,val3;
            if( i < m-1){
              val1 = Ci[p.second];
              val2 = Mi[p.second];
              val3 = Si[p.second];
              typeOne.erase(make_pair(val1,p.second));
              typeTwo.erase(make_pair(val2,p.second));
              typeThree.erase(make_pair(val3,p.second));
            }

        }
    }
}

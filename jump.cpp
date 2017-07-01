#include <iostream>
#include<vector>
#include<list>
#include<math.h>
using namespace std;

#define MAX_N 100000

int n,m;
vector<int> adj[MAX_N];
int deg[MAX_N];
int levels[MAX_N];
void read_input() {
    cin >> n >> m;
    double x[n+2] , y[n+2];
    int num[n+2];
    for(int i=0; i<n; i++) {
        deg[i] = 0;
    }
    for( int i=0; i<n+2; i++ ) {
        if( i == 0 ) {
            x[i] = 0;
            y[i] = 0;
        }
        else if( i == n+1 ) {
            x[i] = 100;
            y[i] = 100;
        }
        else {
            cin >> x[i] >> y[i];
        }
        num[i] = i;
    }
    for( int i=0; i<n+2; i++ ) {
        for( int j=0; j<n+2; j++ ) {
            if( (pow(x[i]-x[j],2) + pow(y[i]-y[j],2)) <= m*m && i!=j ) {
                int u = num[i];
                int v = num[j];
                adj[u].push_back(v);
                adj[v].push_back(u);
                deg[u]++;
                deg[v]++;
            }
        }
    }
}

void find_levels( int s ) {

    list<int> next_level;

    for( int u=0; u<n+2; u++ ) {
        levels[u] = -1;
    }

    next_level.push_back(s);
    levels[s] = 0;

    while( !next_level.empty() ) {

        list<int> current_level = next_level;
        next_level.clear();

        for( list<int>::iterator i = current_level.begin();
            i != current_level.end(); i++ ) {
            int u = *i;

            for( vector<int>::iterator j = adj[u].begin();
                j != adj[u].end(); j++ ) {
                int v = *j;

                if(levels[v] == -1) {
                    levels[v] = levels[u] + 1;
                    next_level.push_back(v);
                }
            }
        }
    }
}
int main() {
    read_input();
    find_levels(0);
    cout << levels[n+1] << endl;
}

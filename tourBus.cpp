#include <iostream>
#include <vector>
#include <list>

using namespace std;

#define MAX_N 100000

int n,m,k;
vector< pair<int,int> > adj[MAX_N];
int levels[MAX_N];

void read_input()
{
    cin >> n >> m >> k;
    for( int i=0; i<m; i++ ) {
        int Ci,Di,Hi;
        cin >> Ci >> Di >> Hi;
        adj[Ci].push_back(make_pair(Di,Hi));
        adj[Di].push_back(make_pair(Ci,Hi));
    }

}

void find_levels(int x, int z)
{
    list<int> next_level;
    for(int u=1; u<=n; u++) {
        levels[u] = -1;
    }
    next_level.push_back(x);
    levels[x] = 0;

    while(! next_level.empty()) {
        list<int> current_level = next_level;
        next_level.clear();

        for(list<int>::iterator i = current_level.begin();
            i != current_level.end(); i++) {
            int u = *i;

            for(vector< pair<int, int> >::iterator j = adj[u].begin();
                j != adj[u].end(); j++) {
                int v = j.base()->first;

                if(levels[v] == -1 && z <= j.base()->second) {
                    levels[v] = levels[u] + 1;
                    next_level.push_back(v);
                }
            }
        }
    }
}

int main(){

    read_input();
    int x = 0,y = 0,z = 0;
    for ( int i = 0; i < k; i++ ) {
        cin >> x >> y >> z;
        find_levels(x,z);
        if (levels[y] != -1) cout << "yes" << endl;
		    else cout << "no" << endl;
    }

}

#include <iostream>
#include <vector>
#include <list>

using namespace std;

#define MAX_N 100001

int n,m;
vector<int> adj[MAX_N];
int deg[MAX_N];
int levels[MAX_N];

void read_input()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        deg[i] = 0;
    }
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }
}

void find_levels(int s)
{
    list<int> next_level;

    next_level.push_back(s);
    levels[s] = 0;

    while(! next_level.empty()) {
        list<int> current_level = next_level;
        next_level.clear();

        for(list<int>::iterator i = current_level.begin();
            i != current_level.end(); i++) {
            int u = *i;

            for(vector<int>::iterator j = adj[u].begin();
                j != adj[u].end(); j++) {
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
    int count = 0;
    read_input();
    for( int u=1; u <= n; u++ ) {
        levels[u] = -1;
    }

    for ( int i = 1; i <= n; i++ ) {
        if (levels[i] == -1){
            find_levels(i);
            count ++;
        }
    }
    cout << count << endl;
}

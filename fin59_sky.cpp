#include <iostream>
#include <vector>
#include <list>
#include<math.h>

using namespace std;

#define MAX_N 100000

int n,m, l, s, t;
vector<int> adj[MAX_N];
int deg[MAX_N];
int levels[MAX_N];
int h[MAX_N];
void read_input()
{
  	cin >> n >> m >> l >> s >> t;
	for(int i=0; i<n; i++)
    	cin >> h[i];
  	for(int i=0; i<m; i++) {
    	int u,v;
    	cin >> u >> v;
 	 	adj[u - 1].push_back(v - 1);
    	adj[v - 1].push_back(u - 1);
  	}
}

void find_levels(int s)
{
  	list<int> next_level;
  	for(int u=0; u<n; u++) levels[u] = -1;
  	next_level.push_back(s);
  	levels[s] = 0;

    while( !next_level.empty() ) {

    	list<int> current_level = next_level;
    	next_level.clear();

      for( list<int>::iterator i = current_level.begin(); i != current_level.end(); i++ ) {
          int u = *i;
      		for( vector<int>::iterator j = adj[u].begin(); j != adj[u].end(); j++ ) {
        		int v = *j;
        		if( levels[v] == -1 ) {
        			if( h[v] < h[u] ) {
        				levels[v] = levels[u] + 1;
          				next_level.push_back(v);
					}	else {
							if( abs(h[v] - h[u]) <= l ) {
          					levels[v] = levels[u] + 1;
          					next_level.push_back(v);
						}
					}

        		}
      		}
    	}
  	}
}

int main()
{
  read_input();
  find_levels(s - 1);
  cout << levels[t - 1] << endl;
  return 0;
}

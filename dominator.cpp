#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;

int V, tc;
vector<vi> AdjList;
bitset<105> initVisited, curVisited;
bool first;

void dfs(int u, int del) {
	bitset<105> *visited;
	if (first)
		visited = &initVisited;
	else
		visited = &curVisited;

	visited->set(u);
	if (u == del)
		return;

	for (int i = 0; i < (int) AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (!visited->test(v))
			dfs(v, del);
	}
}

int main() {
  int count = 1;
	cin >> tc;
	while (tc--) {
		cin >> V;
		AdjList.assign(V, vi());
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				int e;
				cin >> e;
				if (e)
					AdjList[i].push_back(j);
			}
		}

		first = true;
		for (int i = 0; i < V; i++)
			initVisited.reset(i);
		dfs(0, V);
		first = false;

    cout << "Case "<< count++ <<":";
		for (int i = 0; i < V; i++) {
			for (int k = 0; k < V; k++)
				curVisited.reset(k);
			dfs(0, i);


      cout << endl << "+";
			for (int j = 0; j < V * 2 - 1; j++) {
        cout << "-";
			}
      cout << "+" << endl << "|";
			for (int j = 0; j < V; j++) {
				if (initVisited.test(j) && (i == j || !curVisited.test(j))) cout << "Y";
				else cout << "N";
        cout << "|";
			}
		}

    cout << endl <<"+";
		for (int j = 0; j < V * 2 - 1; j++) cout << "-";
    cout << "+" << endl;
	
	}

}

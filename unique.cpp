#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int,int> m;
map<int,int>::iterator it;

int main() {
	int TC;
  cin >> TC;
	while(TC--) {
		m.clear();
		int N;
		cin >> N;
		int pos = 0;
		int lastpos=0;
		int max = 0;
		while( pos <= N ) {
			if( pos == N ) {
				int temp = pos - lastpos;
				if(temp > max) max = temp;
				break;
			}
			int key;
			cin >> key;
			if( (it = m.find(key)) != m.end() ) {

				if(it -> second < lastpos){
					m[key] = pos;
					++pos;
					continue;
				}
				int temp = pos - lastpos;
				if(temp>max) max = temp;
				lastpos = it->second + 1;
				m[key] = pos;
			}
			else m[key] = pos;
			++pos;
		}
		cout << max << endl;
	}

}

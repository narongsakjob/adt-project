#include<iostream>
#include<map>
#include<queue>
using namespace std;

int main(){

	queue<int> reqQ;
	int n, m,x;
	cin >> n >> m;
	map<int, int> req;

	int countMiss = 0;

	for( int i = 0; i < m; i++ ){

		cin >> x;

		if(req.count(x) == 0){
			req.insert(pair<int,int>(x,1));
			if(reqQ.size() == n){
				req.erase(reqQ.front());
				reqQ.pop();
			}
			reqQ.push(x);
			countMiss++;
		}

	}

	cout << countMiss << endl;
}

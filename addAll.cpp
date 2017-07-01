#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
class Compare
{
public:
  bool operator()(int x , int y)const
  {
    return x > y;
  }
};


int main() {

  int n;
  while( cin >> n && n!=0 ) {
    int arr[n];

    priority_queue<int, vector<int>, Compare > q;

    for( int i = 0 ; i < n ; i++ ){
      cin >> arr[i];
      q.push(arr[i]);
    }

    int total = 0, cost = 0;
		while ( q.size() > 1 ) {

			total = q.top();
			q.pop();
			total += q.top();
			q.pop();
			cost += total;
			q.push(total);

		}
    cout << cost << endl;

  }

}

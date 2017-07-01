#include <iostream>
#include <queue>
using namespace std;

int main(){

  int n,m,k,l;
  cin >> n >> m;
  priority_queue<int> queue;


  for( int i = 0; i < n; i++ ) {
    cin >> k;
    queue.push(k);
  }
  int max,sum=0;
  for( int i = 0; i < m; i++ ) {
    cin >> l;
    max = queue.top();
    sum += max;
    sum %= 7919;
    if( max - l < 0 ) {
      queue.pop();
    }else{
      queue.pop();
      max-=l;
      queue.push(max);
    }
  }

  cout << sum <<endl;


}

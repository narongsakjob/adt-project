#include <iostream>
#include <queue>
using namespace std;

class Pair
{
public:
  int key;
  int value;

  Pair( int key , int value )
  :key(key),value(value){}

};

int flavor[20];

int main() {

  queue<Pair> queue;
  int n,m,a,a1,a2;
  cin >> n;

  for( int i = 0 ; i < n ; i ++ ) {

    cin >> m;
    if( m == 1 ) {

      cin >> a;
      for( int j = 0 ; j < a ; j++ ) {

        cin >> a1 >> a2;
        queue.push(Pair(a1,a2));

      }

    }else if( m == 2 ) {

      cout << queue.front().key << endl;
      flavor[ queue.front().value - 1 ]++;
      queue.pop();

    }


  }

  

  cout << queue.size() << endl;

  for( int i = 0 ; i < 20 ; i++ ){
    cout << flavor[i] << " ";
  }
  cout << endl;

}

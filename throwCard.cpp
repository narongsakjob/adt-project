#include <iostream>
#include <list>
using namespace std;

int main() {

  list<int> l;
  int n;

  while( cin >> n && n!= 0 ) {

    for( int i = 1; i <= n; i++ ) {
      l.push_back(i);
    }

    cout << "Discarded cards:";

    for( int i = 0 ; i < n-1 ; i++ ){

      cout << " " <<l.front();
      l.pop_front();
      int temp = l.front();
      l.pop_front();
      l.push_back(temp);
      if( i < n-2 )cout << "," ;
    }

    cout << endl;
    cout << "Remaining card: " << l.front() <<endl;
    l.pop_front();
    l.clear();
  }

}

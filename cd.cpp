#include <iostream>
#include <map>
using namespace std;

int main() {

  int n, m, key;
  map<int,int> ma;

  while( cin >> n >> m && n != 0 && m != 0 ) {

    for( int i = 0 ; i < n ; i++ ) {
      cin >> key;
      ma[key] = 1;
    }

    int count = 0;
    for( int i = 0 ; i < n ; i++ ) {
      cin >> key;
      if( ma[key] == 1 ) count++;
    }

    cout << count << endl;

    ma.clear();
  }

}

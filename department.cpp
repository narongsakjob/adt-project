#include <iostream>
#include <list>
#include <map>

using namespace std;

int main() {

  int n;
  list <int>l;
  map <int,int>m;

  while ( cin >> n && !cin.eof() ) {

    if( m[n] == 0 ) {
      l.push_back(n);
      m[n] +=1;
    }else m[n] +=1;
    // if( n == -1 ) break;
  }

  for( int i = 0; i < m.size(); i++ ) {
    cout << l.front() << " " << m[l.front()] << endl;
    l.pop_front();
  }

}

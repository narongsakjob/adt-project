#include <iostream>
#include <map>

using namespace std ;

map < int  ,int > m ;
map < int ,int > :: iterator h , t ;
int main() {
  int n ,set ,a;
  long ans =0;
  while ( cin >> n && n != 0 ) {

    for( int i = 0; i < n; i++ ) {

      cin >> set;
      for( int j = 0; j < set; j++ ) {

        cin >> a;
        m[a]+= 1;

      }

      h = m.begin();
      t = m.end();
      t--;
      int tail = (*t).first ;
      int head = (*h).first ;
      ans += tail - head;

      if( --m[tail] == 0 ) m.erase(t) ;
      if( --m[head] == 0 ) m.erase(h) ;



    }

    cout << ans << endl;
    m.clear();
    ans = 0;

  }

}

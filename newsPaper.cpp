#include<iostream>
#include<map>

using namespace std;

int main() {
  int n,k,m;
  map<char,double> map;
  char key;
  double value;
  cin >> n ;


  for( int i = 0; i < n; i++ ) {
    long price =0;
    cin >> k ;

    for( int j = 0; j < k; j++ ) {
      cin >> key;
      cin >> value;
      map[key] = value;
    }


    cin >> m;
    cin.ignore();

    for (int j = 0; j < m; j++) {
        unsigned char c;
        while ((c = cin.get()) != '\n') {
          price += map[c];
        }
      }

    printf("%.2lf$\n", price / 100.0);
    map.clear();
  }

}

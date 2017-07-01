#include<iostream>

using namespace std;

int main() {
  int n,w,h;
  cin >> n;

  for( int i = 0; i < n; i++ ) {

    cin >> w >> h;
    cout << (w/3)*(h/3) << endl;

  }

}

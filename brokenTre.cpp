#include <iostream>

using namespace std;

int h[10];

int max(char t , int c){

  int maxH = h[c-1];

  if( t == '-' ) {

    for( int i = c-1 ; i <= c+2 ; i++ ){
      if( h[i] > maxH )maxH = h[i];
    }

  }else if( t == 'o' ) {

    if(h[c] > h[c-1]) maxH = h[c];
    else maxH = h[c-1];

  }else if( t == 'i' ) {
    maxH = h[c-1];
  }

  return maxH;

}

int main() {

  int n;
  cin >> n;
  char t;
  int c;
  int maxH;

  for( int i = 0; i < n; i++ ) {

    cin >> t >> c;

    int temp = max(t,c);
    if( t == '-' ) {

      h[c-1] = temp + 1;
      h[c] = temp + 1;
      h[c+1] = temp + 1;
      h[c+2] = temp + 1;

    }else if( t == 'o' ) {
      h[c-1] = temp + 2;
      h[c] = temp + 2;
    }else if( t == 'i' ) {
      h[c-1] = temp + 4;
    }

  }

  maxH = h[0];
  for( int i = 0 ; i<10 ; i++ ) {
    if( h[i] > maxH )maxH = h[i];
  }

  cout << maxH << endl;

}

#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main(){

  int n ;
  cin >> n;
  char alberta[8];

  for( int i = 0 ; i < n ; i++ ) {

    cin >> alberta;

    int front = 0, back = 0 ;

    front += (alberta[0]-'A')*pow(26,2);
    front += (alberta[1]-'A')*pow(26,1);
    front += (alberta[2]-'A')*pow(26,0);

    back += (alberta[4]-'0')*pow(10,3);
    back += (alberta[5]-'0')*pow(10,2);
    back += (alberta[6]-'0')*pow(10,1);
    back += (alberta[7]-'0')*pow(10,0);

    int result = abs(front-back);

    if( result <= 100 ) {
      cout << "nice" << endl;
    }else{
      cout << "not nice" << endl;
    }


  }

}

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

  int n,m;
  cin >> n;

  for ( int i = 0 ; i < n ; i++ ) {

    cin >> m;

    int result = ((((((m*567)/9)+7492)*235)/47)-498);

    result = result/10;
    result = abs(result%10);


    cout << result << endl;


  }

}

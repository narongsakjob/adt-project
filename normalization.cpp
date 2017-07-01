#include <iostream>

using namespace std;


int main()
{

  int a,b;

  cin >> a;
  cin >> b;

    for( int i = a ; i >= 2 ; i-- ){
        if( a % i == 0 && b % i ==0){
          a = a/i;
          b = b/i;
          break;
        }
    }


  cout << a << "/" << b << endl;



}

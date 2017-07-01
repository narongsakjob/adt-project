#include <iostream>
#include <math.h>
using namespace std;




void changeBinary( long input , int x[] , int power , int count ){

  if( power < 0 )return;

  long order = pow(2,power);

  if( order > input ){
    x[count] = 0;
    changeBinary( input , x , power - 1 , count + 1 );
  }else{
    x[count] = 1;
    changeBinary( input-order , x , power - 1 , count + 1 );
  }

}



int main(){

  while(!cin.eof()) {
    long a , b;

    int binaryA[32];
    int binaryB[32];
    int result[32];
    long output = 0;
    long order;
    cin >> a;
    cin >> b;
    if(cin.eof()) {
      break;
    }
   changeBinary(a,binaryA,31,0);
   changeBinary(b,binaryB,31,0);

    for( int i = 0 ; i < 32 ; i++ ){
      if( binaryA[i] != binaryB[i] ){
        result[i] = 1;
      }else{
        result[i] = 0;
      }
    }

    for( int i = 0 ; i < 32 ; i++ ){
      if(result[i] == 1){
        order = pow(2,31-i);
          output += order;
      }
    }

    cout << output << endl;
  }
}

#include <iostream>
#include <math.h>
using namespace std;



int binary(int n,int count){

    if(n < 1)return count;

    if(n % 2 != 0 ){
      return binary(n/2,count+1);
    }else{
      return binary(n/2,count);
    }

}



 int hexadecimal(int n,int hexaValue,int power){

    int recure;
    int result;

    int powerValue = pow(10,power);

    if(powerValue <= n){
      recure = n - ((n/powerValue)*powerValue);
      result = hexaValue+(n/powerValue);

    }else{
       recure = n;
       result = hexaValue;
    }

    if( recure == 0)return result;
    else {

      return hexadecimal( recure , result*16 , power-1 );
    }

 }


int main() {

  int input;
  cin >> input;
  int n[input];


  for( int i = 0 ; i < input ; i++ ) {
    cin >> n[i];
  }


  int resultBinary[input];
  int resultHexa[input];
  int hexaValue;


  for( int i = 0 ; i < input ; i++ ) {
    resultBinary[i] = binary( n[i] , 0 );
    hexaValue = hexadecimal( n[i] , 0 , 4 );

    resultHexa[i] = binary( hexaValue , 0 );
  }




  for( int i = 0 ; i < input ; i++ ) {
    cout << resultBinary[i] << " " << resultHexa[i] << endl;
  }


}

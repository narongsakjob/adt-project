#include <iostream>
using namespace std;

int main(){
  int n,k;
  cin >> n ;
  cin >> k ;
  int input[n];

  for( int i = 0 ; i < n ; i++ ){
    cin >> input[i];
  }

  int keepResult = 0,result=0;
  bool check = true;

  for ( int i = 0 ; i <n ; i++ ){
    if(input[i+1] > input[i] && check == true){
      if( input[i+1] - input[i] >= k){
        keepResult -= input[i+1];
        check = false;
      }
    }else{

      if( input[i] - input[i+1] >= k && check == false && i!=n-1){
        check = true;
        keepResult += input[i+1];
        result = keepResult;


      }
    }
  }

  cout << result << endl;

}

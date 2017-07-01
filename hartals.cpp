#include<iostream>

using namespace std;

int main(){

  int n,date,numClosed;
  cin >> n;
  int result[n];


  for( int i = 0 ; i < n ; i++ ){

      cin >> date;
      cin >> numClosed;
      int data[numClosed];


      for( int j = 0 ; j < numClosed ; j ++ ){
        cin >> data[j];
      }

      result[i] = 0;
        for( int m = 2 ; m <= date ; m++ ){
          for(int k = 0 ; k < numClosed ; k ++){
            if( m % data[k] == 0 && (m - 6) % 7 != 0 && m % 7 != 0 ){
              result[i]++;
              break;
            }
        }
      }

  }


  for(int i = 0 ; i < n ; i++){
    cout << result[i] << endl;
  }




}

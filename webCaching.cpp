#include<iostream>

using namespace std;
int main(){

  int n,m,x;


  cin >> n;
  cin >> m;

  int a[n];
  int count=0;
  bool check=false;

  for( int i = 0 ; i < m ; i++ ){

    cin >> x;

    if( i < n){
      a[i] = x;
      count++;
    }else{
      for( int j = 0 ; j < n ; j++ ){
        if( x == a[j] ){
          check = true;
          break;
        }else{
          check = false;
        }

      }

      if( check == false ){
        for( int j = 0 ; j < n ; j++ ){
          if( j < n-1) a[j] = a[j+1];
        }
        a[n-1] = x;
        count++;
      }


    }



  }

  cout << count << endl;



}

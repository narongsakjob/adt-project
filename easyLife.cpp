#include <iostream>
using namespace std;

int date[31];

int main(){

  int n,count=0;

  cin >> n;

  for( int i = 0 ; i < n ; i++ ){

    int a,b,c;
    bool check = true;
    cin >> a >> b >> c;

    for( int i = a-1 ; i < b ;i++ ){
      if( date[i] + c > 6 ){
        check = false;
        break;
      }
    }

    if( check == true ){
      for( int i = a-1 ; i < b ; i++ ){
        date[i] += c;
      }
      count++;
    }

  }

  cout << count << endl;

}

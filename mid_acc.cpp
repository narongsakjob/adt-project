#include <iostream>
using namespace std;

int main(){
  int n,s;
  cin >> n;
  cin >> s;

  int engin[n];

  for( int i = 0 ; i < n ; i++){
    cin >> engin[i];
  }

  int count = 0 ;
  int second = 0;
  int speed = 0;
  int max = 0;

  while( n > 0){

    if(engin[count] == second){
        count++;
        speed += s;
        n--;
        if(speed > max){
          max = speed;
        }
    }else{
      if(speed > 0) speed--;
    }
    second++;

  }

  cout << max << endl;

}

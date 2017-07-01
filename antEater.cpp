#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  int sum=0;
  int food,count=0;
  for( int i = 0; i < n; i++ ) {
    cin >> food;
    if( food < 1000 && count == 0){
      sum+=food;
      count=1;
    }else if(food >= 1000 && count == 0){
      sum+=1000;
      count = 2;
    }

    count--;

  }
  cout << sum << endl;
  
}

#include <iostream>
#include <cstdlib>
using namespace std;



int main()
{

  int amount,distance;

  cin >> amount;
  cin >> distance;

  int x[amount];


  for( int i = 0 ; i < amount ; i++ ){
    cin >> x[i];
  }

  int count = 0;

  for( int i = 0 ; i < amount ; i++ ){

    for( int j = amount-1 ; j > i ; j--){
      if(abs(x[i] - x[j]) <= distance){
        count++;
      }

    }
  }


  cout << count << endl;





}

#include <iostream>

using namespace std;



int main()
{
  int n;
  cin >> n;
  int sum = 0;
  int count =0;
  int data[n];

  for( int i = 0 ; i < n ; i++ ){
    cin >> data[i];
  }

  for( int i = 0 ; i < n ; i++ ){
    sum = sum + data[i];
    if( sum > 1000 ){
      sum = 0;
      count++;
      i--;
    }
  }

  count++;
  cout << count << endl;


}

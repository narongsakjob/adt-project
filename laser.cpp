#include <iostream>

using namespace std;

int main() {

  int a,c;

  while( cin >> a && a !=0  && cin >> c) {
    int arr[c];
    int count=0;

    for( int i = 0 ; i < c ; i++ ) {

      cin >> arr[i];
      if( i == 0) count += (a - arr[i]);
      else if( (arr[i-1] - arr[i]) > 0 ) count+= (arr[i-1] - arr[i]);

    }

    cout << count << endl;

  }


}

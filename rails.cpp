#include <iostream>
#include <stack>
using namespace std;

int main() {

  int n;
  while ( cin >> n && n != 0 ) {

    int arr[n];

    while( cin >> arr[0] && arr[0] != 0) {

      for( int i = 1 ; i < n ; i++ ) {
        cin >> arr[i];
      }


      stack <int>s;
      int index =0;

      for( int i = 1 ; i <= n ; i++ ) {

        s.push(i);
        while( !s.empty() && s.top() == arr[index] ) {
					s.pop();
					index++;
					if( index==n ) break;
				}

      }


      if(s.empty()) cout << "Yes" << endl;
			else cout << "No" << endl;

    }
    cout << endl;



  }

}

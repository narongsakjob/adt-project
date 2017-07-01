#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int input;
	while (true) {
    cin >> input;
    int arr[input];


    if ( input == 0 ) {
    			break;

    } else if ( input < 13 ) {

    			continue;

    } else {

			for ( int i = 1 ; i < 1000 ; i++ ) {


      	for ( int j = 0 ; j < input ; j++ ) {
      		arr[j] = 1 ;
      	}

      	int r = 0;
      	arr[0] = 0;

      	for ( int j = 0 ;j < input ; j++ ) {

      		for ( int k = 0 ; k < i ; k++ ) {

      			if ( j == input-1) {
      				break;
      			}

      			r = ( r + 1 ) % input ;

      			if ( arr[r] == 0 ) {

      				k -= 1;

      			}

      		}

      		arr[r] = 0;
      	}



				if ( r+1 == 13 ) {
					cout << i << endl;
					break;
				}

			}

		}

	}

}

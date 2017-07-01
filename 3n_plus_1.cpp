#include <iostream>
using namespace std;


void work( int i , int j ){

	int max = 1;
	int a = 0;
	int count = 1;


	if( j > i ) {

		for( int k = j ; k >= i ; k--){

			a = k;

			while( a != 1){

				count++;

				if( a % 2 != 0){
					a = (3*a) + 1;

				}else{
					a = a/2;
				}


				if(  count > max ) {
					max = count;
				}

			}

			count = 1;

		}
	}else if( i == j ){

			a = i;

			while( a != 1){

				count++;

				if( a % 2 != 0){
					a = (3*a) + 1;

				}else{
					a = a/2;
				}


				if(  count > max ) {
					max = count;
				}

			}




	}else{

		for( int k = i ; k >= j ; k--){

			a = k;

			while( a != 1){

				count++;

				if( a % 2 != 0){
					a = (3*a) + 1;

				}else{
					a = a/2;
				}


				if(  count > max ) {
					max = count;
				}

			}

			count = 1;

		}
	}
			cout << i << " " << j << " " << max << endl;
}






int main() {


	while(!cin.eof()) {
	    int i,j;

	    cin >> i;
	    if(cin.eof()) {
	      break;
	    }
	    cin >> j;
	    work(i,j);

	  }

}

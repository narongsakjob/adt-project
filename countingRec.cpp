#include <iostream>
#include <stdio.h>
using namespace std;

char rec[101][101];

int main() {
	int n, m, i, j, k;

	while( true ) {
    cin >> n;
    if( n == 0 )break;
    cin >> m;

		for(i = 0; i < n; i++)cin >> rec[i];

		int result = 0, length, width, temp;

		for(i = 0; i < n; i++) {

			int sum[101] = {};

			for(j = i; j < n; j++) {
				for(k = 0; k < m;  k++) {

					sum[k] += rec[j][k]-'0';

          if(k == 0 || temp != length*width){
            temp = 0;
            length = 0;
          }

          temp += sum[k];
					length++;
          width = j-i+1;

          if(temp == length*width)result += length;

				}
			}

    }


    cout << result << endl;

  }

}

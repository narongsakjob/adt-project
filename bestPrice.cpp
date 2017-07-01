#include <iostream>

using namespace std;
int main() {
    int w,l,a;
    cin >> w >> l >> a;
    int arr[w][l];
    for ( int i = 0; i < w; i++ ) {
        for ( int j = 0; j < l; j++ ) {
            cin >> arr[i][j];
        }
    }
    int check = -1;

    for (int i = w; i >=1; i--) {
        for (int j = 1; j <= l; j++) {
            if (i*j >= a) {
                for (int k = 0; k < w - i + 1; k++) {
                    for (int m = 0; m < l - j + 1; m++) {
                        int value = 0;

                        for (int n = 0; n < i; n++)
                          for (int o = 0; o < j; o++) value += arr[k+n][m+o];

                        if (check == -1 || value < check) check = value;
                    }
                }
                break;
            }
        }
    }
    cout << check << endl;

}

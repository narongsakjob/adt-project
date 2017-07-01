#include <iostream>
#include <stdlib.h>
using namespace std;

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}


int main() {


    int n;
    int arr[1000000];

    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
      cin >> arr[i];
    }

    quickSort(arr,0,n-1);

    int result = 0;
    int temp;

    for( int i = 0 ; i < n ;i++ ){

      if( i == 0 ) result = abs(arr[i] - arr[i+1]);
      if( i < n-1 ){
        temp = abs( arr[i] - arr[i+1] );
        if( result > temp ) result = temp;
      }

    }
    cout << result << endl;


}

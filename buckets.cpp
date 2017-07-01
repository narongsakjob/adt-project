#include <iostream>
using namespace std;

int main(){

  int n;
  cin >> n;
  int keep[n];

  for( int i = 0 ; i < n ; i++ ) {
    cin >> keep[i];
  }

  int tank=0;
  int dataTank[5];
  for(int i = 0 ;i < 5 ;i++){
    dataTank[i] = 0;
  }
  int minData = dataTank[0],min=0;
  for( int i = 0 ; i < n ; i++ ){
    minData = dataTank[0];
    min = 0;
    for( int j = 0 ; j < 5 ; j++ ){
      if( dataTank[j] < minData){
        minData = dataTank[j];
        min = j;
      }
    }
      if(dataTank[min] == 0 && keep[i] < 1000){
        dataTank[min] = keep[i];
      }else{
        if( dataTank[min] + keep[i] >= 1000){
          dataTank[min] = 0;
          tank +=1000;
        }else{
          dataTank[min] += keep[i];
        }
      }


    }
  cout << tank << endl;



}

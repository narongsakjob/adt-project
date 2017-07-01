#include <iostream>
using namespace std;

int main(){

  int n,k;
  cin >> n;
  cin >> k;
  int countDown = n;
  int a = n;
  int keepN = n;
  int count = 1;
  int data[n];
  int runData = 0;
  for(int i = 0 ; i < n ; i++){
    data[i] = i+1;
  }

  while(a > 1){

    count=1;

    while(count <= k){

      if( runData ==  keepN) runData = 0;
      if(count == k && data[runData] != -1){
        a -=1;
        data[runData] = -1;
        count++;
      }
      if(data[runData] != -1) count++;
        runData++;
    }



  }

  for(int i = 0 ; i < n ; i++){
    if(data[i] != -1) cout<<data[i]<<endl;
  }

}

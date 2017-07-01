#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){

  int n,j,k,m,s,t;
  map<int, int> map;

  cin >> n ;
  int arr[n];


  for( int i = 0 ; i < n ; i++ ) {

    cin >> k >> m;
    arr[i] = k;
    map[i] = m;

  }

  cin >> j;

  for( int i = 0 ; i < j ; i++ ) {

    cin >> s >> t;
    int index = -1;
    int min = -1;
    bool check = true;
    for(int z = s-1 ; z < t ; z++ ){
      if( arr[z] > 0 && check == true){
        check= false;
        min = map[z];
        index = z;
      }
      if( min != -1 ){
          if( min > map[z] && arr[z] > 0 ) {
            index = z;
            min = map[z];
          }
      }

    }

    if(index == -1 )cout << "-1" <<endl;
    else {
      cout << map[index] << endl;
      arr[index]--;
    }

  }


}

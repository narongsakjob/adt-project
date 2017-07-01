
#include <map>
#include <iostream>
#include <string>

using namespace std;




int main() {

  int n;
  map <string,int>m;



  while( cin >> n && n != 0 ) {

      int max = 0;
      int arr[5];
    for( int i = 0 ; i < n ; i++ ) {

      cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

       int min = 500,index;
      string key;

      for( int i = 0 ; i < 5 ; i++ ) {

        for( int j = 0 ; j < 5 ; j++ ) {
          if( arr[j] < min ){
             min = arr[j];
             index = j;
           }
        }
        key+=to_string(min);
        arr[index] = 500;
        min = 500;



      }


      if( !m.count(key)  ){
        m[key] = 1;
        if( max < 1 ) max = 1;
      }else{
        if( m[key] + 1 > max ) max = m[key] + 1;
        m[key] += 1;
      }


    }
    int count = 0;
  		for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
  			if (it->second == max)count += it->second;
  		}
      cout << count <<endl;
    m.clear();

  }

}

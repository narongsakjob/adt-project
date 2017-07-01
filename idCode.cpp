#include<iostream>
#include <algorithm>
using namespace std;
char s[100];
int main() {


  while( cin >> s && s[0] != '#') {

        int count =0;
        for( int i = 0 ; i < 100 ; i++ ){
          if( s[i] == '\0' ) break;
          count++;
        }

       if( next_permutation( s, s+count ) ) cout<<s<<endl;
       else cout<<"No Successor"<<endl;

  }

}

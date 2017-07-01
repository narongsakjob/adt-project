#include <iostream>

using namespace std;

int main() {

  string s;

  while( cin >> s && s != "*") {
    int result = 0;
    double sum=0;
    for( int i = 0 ; i < s.length() ; i++ ) {
      if(s[i] == '/'){
        if( sum == 1 )result++;
        sum=0;
      }else{
        if( s[i] == 'W' ) sum+=1;
        else if( s[i] == 'H' ) sum+=0.5;
        else if( s[i] == 'Q' ) sum+=0.25;
        else if( s[i] == 'E' ) sum+=0.125;
        else if( s[i] == 'S' ) sum+=0.0625;
        else if( s[i] == 'T' ) sum+=0.03125;
        else if( s[i] == 'X' ) sum+=0.015625;
      }
    }
    cout << result << endl;

  }

}

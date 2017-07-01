#include <iostream>
#include <list>
using namespace std;

int main() {
  list <char> list1;
  list <char>::iterator it = list1.begin();
  string input;

  bool check = false;

  while( getline(cin,input) ) {
    for( int i = 0 ; i < input.size() ; i++ ) {


      if( input[i] != '[' && input[i] != ']' && check == false) {
          list1.push_back(input[i]);
      }

      if( input[i] != '[' && input[i] != ']' && check == true) {
          list1.insert(it,input[i]);
      }

      if( input[i] == '['){

        check = true;
        it = list1.begin();
      }
      if( input[i] == ']'){

        check = false;
      }

    }

    for(it=list1.begin();it!=list1.end();it++)cout << *it;
    list1.clear();
    cout << endl;
  }
}

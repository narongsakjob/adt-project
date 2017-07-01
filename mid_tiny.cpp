#include <iostream>
#include <list>
using namespace std;


int main() {

     int n,m,l,k,data;
     list<int> myList;
     list<int>::iterator it;
     list<int>::iterator temp;

     cin >> n;
     cin >> m;

     for( int i = 0; i < n; i++ ) {
        cin >> data;
        myList.push_back(data);
     }
     it = myList.begin();
     for( int i = 0; i < m; i++ ) {
        cin >> l;
        if( l == 1 ) {
          it++;
        }else if( l == 2 ) {
          it = myList.begin();
        }else if( l == 3 ) {
          cin >> k;
          it++;
          for( int i = 0; i < k; i++ ) {
            it = myList.erase(it);
          }
          it--;
        }else {
          cin >> k;
          temp = it;
          it++;
          for( int i = 0; i < k; i++ ) {
            cin >> data;
            myList.insert(it,data);
          }
          it = temp;
        }
     }

     for(it=myList.begin();it!=myList.end();it++)cout << *it << " ";
     cout << endl;





}

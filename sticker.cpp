#include <iostream>
using namespace std;
int n,m,s,u,v,direct;
string data[101],dataS;

int findlevel() {
  int x,y,count = 0;

  for( int i = 0 ; i < s ; i++ ) {
    if( dataS[i] == 'D' ) {
       direct = (direct+1)%4;
    }else if( dataS[i] == 'E' ) {
      direct -= 1;
      if (direct<0) direct = 3;
    }else {
      x=u; y=v;
      if (direct==0) x--;
      else if (direct==1) y++;
      else if (direct==2) x++;
      else y--;

      if ( y<0 || y>=m || x<1 || x>n || data[x][y]=='#' ) continue;
      else {
        data[u][v]='.';
        if (data[x][y]=='*') count++;
        u=x; v=y;
      }
    }
  }
  return count;
}

int main() {



  while( (cin >> n >> m >> s) && (n != 0 && m != 0 && s != 0) ) {

    for( int i = 1; i <= n; i++ ) {
      cin >> data[i];
    }
    cin >> dataS;

    bool check = true;
    for( u = 1; u <= n; u++ ) {
      for( v = 0; v < m; v++ ) {
        if (data[u][v]!='.' && data[u][v]!='*' && data[u][v]!='#') {
                   check = false;
                   break;
        }
      }
      if( check == false ) break;
    }

    if (data[u][v]=='N') direct=0;
    else if (data[u][v]=='L') direct=1;
    else if (data[u][v]=='S') direct=2;
    else if (data[u][v]=='O') direct=3;

    cout << findlevel() << endl;

  }

}

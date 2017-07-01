#include <iostream>
#include <stdio.h>
using namespace std;

int N,M,X,Y;
string g[25];
char land;
int v[25][25];
int ans;

int floodfill( int x, int y ) {
    int ret;

    if( y==M ) y=0; else if( y==-1 ) y=M-1;
    if( x<0 || x>=N || y<0 || y>=M ) return 0;
    if( v[x][y] ) return 0;
    if( g[x][y] != land ) return 0;

    v[x][y]=1;
    ret=1;

    ret += floodfill(x,y-1);
    ret += floodfill(x,y+1);
    ret += floodfill(x+1,y);
    ret += floodfill(x-1,y);
    return ret;
}

int main() {

  int t;
  while(cin >> N >> M && !cin.eof() ) {
      for( int i=0; i<N; i++ ) {
              cin >> g[i];
              for( int j = 0 ; j < M ; j++ ) {
                v[i][j] = 0;
              }
      }
      cin >> X >> Y;
      land = g[X][Y];
      floodfill(X,Y);

      ans = 0;

      for( int i=0; i<N; i++ ) {
          for( int j=0; j<M; j++ ) {
              if( g[i][j]==land ) {
                  t = floodfill(i,j);
                  if(t>ans) ans = t;
              }
          }
      }
      cout << ans << endl;

  }

}

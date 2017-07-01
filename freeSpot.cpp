#include<iostream>

using namespace std;

int main() {

  int w,h,n;
  int x1,x2,y1,y2;




  while ( true ){
  cin >> w >> h >> n;
  if(  w == 0 ) break;
  int slot = w*h;
  int arrSlot[w][h];
  for( int i = 0 ; i < w ; i++ ){
    for( int j = 0 ; j < h ; j++ ){
      arrSlot[i][j] = 0;
    }
  }
  int maxX,minX,maxY,minY ;


  for( int i = 0 ; i < n ; i++ ) {

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    if( x1  > x2 ) {
      maxX=x1;
      minX=x2;
    }else {
      maxX=x2;
      minX=x1;
    }

    if( y1 > y2 ) {
      maxY=y1;
      minY=y2;
    }else {
      maxY=y2;
      minY=y1;
    }

    for( int i = minX-1 ; i < maxX ; i++ ) {
      for( int j = minY-1 ; j < maxY ; j++ ) {

        if( arrSlot[i][j] == 0 ){
          slot-=1;
          arrSlot[i][j] = 1;
        }

      }
    }



  }

  if( slot == 0 ) cout << "There is no empty spots." << endl;
  else if( slot == 1) cout << "There is one empty spot." << endl;
  else cout << "There are " <<  slot  << " empty spots." << endl;

  }

}

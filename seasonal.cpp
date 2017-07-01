#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int n;
char map[30][30], used[30][30];

void color(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= n) return;
    if(used[x][y] != 0 || map[x][y] == '0') return;
    used[x][y] = 1;
    int i, j;
    for(i = -1; i <= 1; i++)
        for(j = -1; j <= 1; j++)
            color(x+i, y+j);
}
int main() {
    int img = 0;
    while( cin >> n && !cin.eof() ) {
        for( int i = 0; i < n; i++ ) {
            cin >> map[i];
        }
        memset( used, 0, sizeof(used) );
        int cnt = 0;
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < n; j++ ) {
                if( map[i][j] == '1' && used[i][j] == 0 ) {
                    color(i, j);
                    cnt++;
                }
            }
        }
        cout << "Image number "<< ++img << " contains " << cnt << " war eagles." << endl;
    }
}

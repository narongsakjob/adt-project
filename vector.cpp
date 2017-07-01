#include <iostream>
#include <math.h>
#include <set>
using namespace std;
int main(){
    set<int>x;
    int n,m;
    cin>>n;
    cin>>m;
    int a,y[m];
    set<int>::iterator low,up;
    for(int i=0;i<n;i++){
        cin>>a;
        x.insert(a);
    }
    for(int i=0;i<m;i++){
        cin>>y[i];
    }
    for(int i=0;i<m;i++){
        low = x.lower_bound(y[i]);
        low--;
        up = x.lower_bound(y[i]);
        if(abs(*low - y[i]) <= abs(*up - y[i])){
            cout<<*low<<endl;
        }
        else{
            cout<<*up<<endl;
        }
    }
}

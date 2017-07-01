#include <iostream>
#include <set>

using namespace std;

int main() {
    int n,m,b;
    set<int> x;
    set<int>::iterator it,temp;


    cin >> n;
    cin >> m;

    for (int i = 0 ; i < n ; i++) {
        cin >> b;
        x.insert(b);
    }
    for (int i = 0 ; i < m ; i++) {
        cin >> b;
        it = x.lower_bound(b);
        temp = x.lower_bound(b);
        temp--;
        if(abs(*temp-b) <= abs(*it-b))
            cout << *temp << endl;
        else
            cout << *it << endl;
    }

    return 0;
}

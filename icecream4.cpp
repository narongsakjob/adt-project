#include <iostream>
#include <queue>
using namespace std;

class Pair
{
public:
  int priority;
  int value;
  int index;

  Pair( int priority , int value , int index)
  :priority(priority),value(value),index(index){}

};

class PairCompare
{
public:
  bool operator()(const Pair&t1 , const Pair&t2)const
  {
      if( t1.value != t2.value)
        return t1.value > t2.value;
      else
        return t1.index > t2.index;

  }
};

int main(){

    priority_queue<Pair,vector<Pair>,PairCompare> queue;
    int n,a1,a2,count=0;
    cin >> n ;

    for( int i = 0 ; i < n ; i++ ){
      int m;
      cin >> m;
      if( m == 1 ){

        int a;
        cin >> a;

        for( int j = 0 ; j < a ; j++ ){

          cin >> a1 >> a2;
          queue.push(Pair(a1,a2,count++));

        }

      }else if( m == 2 ){

          cout << queue.top().priority << endl;
          queue.pop();

      }
    }

}

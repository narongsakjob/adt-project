#include <iostream>
#include<stdlib.h>

using namespace std;


char a[16],b[100];
int main()
{

  cin >> a;
  int result;
  while( a[0]-'0' >= 0 ){


    if(a[0]=='0' && a[1]=='x')
    {

      result = 0;
      for( int i=2 ; i < 16 ; i++ ){
        if(a[i]=='A')
        result=result*16+10;
        else if(a[i]=='B')
        result=result*16+11;
        else if(a[i]=='C')
        result=result*16+12;
        else if(a[i]=='D')
        result=result*16+13;
        else if(a[i]=='E')
        result=result*16+14;
        else if(a[i]=='F')
        result=result*16+15;
        else{
          if(a[i] != 0)result=result*16+a[i]-'0';
        }



      }
      cout << result << endl;

    }else{



      result=atoi(a);
      int hex,temp;

      for( int i=0 ; i!=-1 ; i++ ){

       hex=result%16;
       result/=16;

        if( hex == 10 )
          b[i]='A';
        else if( hex == 11 )
          b[i]='B';
        else if( hex == 12 )
          b[i]='C';
        else if( hex == 13 )
          b[i]='D';
        else if( hex == 14 )
          b[i]='E';
        else if( hex == 15 )
          b[i]='F';
        else{
          b[i] = hex+'0';
        }


        if(result<=0){
         temp = i;
         break;
        }

       }
       cout << "0x" ;
      for( int i = temp ; i >=0 ; i-- ){
         cout << b[i];
       }

       cout << endl;

    }

    cin >> a;

  }



}

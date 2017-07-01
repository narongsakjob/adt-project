#include <iostream>

using namespace std;


bool check_prime(int p)
{
  if (p <= 1) {
    return false;
  }

else{
int count = 0;
for(int i = 2 ; i<=p;i++){
 if(p%i == 0){
 count++;
}
}
if(count ==1){
return true;
}
else{
return false;
}
}

}

int main()
{

  int n;
  cin >> n;

  n =n + 1;

  while(true){
  	if(check_prime(n)){
  	break;
  	}
  	else{
  	n++;
  	}
  }

  cout << n;



}

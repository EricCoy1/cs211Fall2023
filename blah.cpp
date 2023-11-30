#include <iostream>
#include "/cs/slott/hw/23mailOrderA.h"
#include "/cs/slott/hw/14mailOrderB.h"
#include "/cs/slott/hw/mailOrderC.h"
using namespace std;
char getYN(string msg);
int main(){
  
  char ch = getYN("invalid");
  while(ch == 'Y'){
    cout << "works\n";
    cout << "Enter Again:";
    ch = getYN("invalid");
  } 
  

  return 0;
}

char getYN(string msg){
  char ch;
  cin >> ch;
  while(ch != 'Y' && ch != 'N'){
    cout << msg;
    cin >> ch;
  }
  return ch;
}

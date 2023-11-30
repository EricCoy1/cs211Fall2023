#include <iostream>
#include "LL.h"
using namespace std;

int main(){

  LL<int> a;

  a.addRear(2);
  a.addRear(5);
  a.addRear(7);
  a.displayAll();
  cout << endl;
  a.addInOrderAscend(6);
  a.displayAll();
  

  return 0;
}

#include <iostream>
#include "LL.h"
using namespace std;

int main(){
  LL<int> q;
  if(q.isEmpty())
    cout << "The queue is empty\n";
  q.displayAll();
  q.addRear(1);
  q.displayAll();
  cout << endl;
  q.addRear(2);
  q.addRear(3);
  q.addRear(4);
  q.displayAll();
  cout << endl;
  int x,y,z;
  x = q.deleteFront();
  y = q.deleteFront();
  z = q.deleteFront();
  cout << x << " " << y << " " << z << endl;
  q.displayAll();
  cout << endl;
  if(!q.isEmpty())
    cout << "The queue is not empty\n";
  int f;
  f = q.deleteFront();
  cout << f << endl;
  if(q.isEmpty())
    cout << "The queue is empty\n";
  q.displayAll();
  

  return 0;
}

#include <iostream>
#include "LL.h"
using namespace std;

int main(){
  LL<int> L;
  if(L.isEmpty())
    cout << "The queue is empty\n";
  L.addFront(1);
  L.addFront(2);
  L.addFront(3);
  L.addRear(4);
  L.addRear(5);
  L.displayAll();
  cout << endl;
  int x = L.deleteFront();
  cout << x << " has been deleted\n";
  x = L.deleteRear();
  cout << x << " has been deleted\n";
  L.displayAll();
  cout << endl;
  x = L.deleteFront();
  cout << x << " has been deleted\n";
  x = L.deleteRear();
  cout << x << " has been deleted\n";
  L.displayAll();
  cout << endl;
  x = L.deleteFront();
  cout << x << " has been deleted\n";
  L.displayAll();
  L.addRear(10);
  L.addFront(11);
  L.displayAll();
  cout << endl;
  x = L.deleteRear();
  cout << x << " has been deleted\n";
  //int y = L.getCount();
  //cout << y << endl;
  x = L.deleteRear();
  cout << x << " has been deleted\n";
  L.displayAll();
  cout << endl << endl;

  LL<int> a;
  a.addRear(1);
  a.addRear(2);
  a.displayAll();
  cout << endl;
  LL<int> b(a);
  b.displayAll();
  cout << endl;
  a.deleteFront();
  a.displayAll();
  cout << endl;
  b.displayAll();

  return 0; 
}

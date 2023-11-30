#include <iostream>
using namespace std;

int main(){

  int* P1;
  int* P2;
  P1 = new int;
  *P1 = 1;
  cout << *P1 << endl;
  P2 = new int;
  *P2 = 2;
  cout << *P2 << endl;

  P2 = P1;
  cout << *P2 << endl;
  delete P2;
  P1 = NULL;

  P2 = new int;
  *P2 = 3;
  cout << *P2 << endl;

  return 0;
}

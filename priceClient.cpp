#include <iostream>
#include <iomanip>
#include "price.h"

using namespace std;

ostream& operator<<(ostream& o, Price& t);

int main(){
  Price p1(2, 50);
  Price p2(3, 75);
  Price p3(1, 99);
  Price p4(1, 58);

  Price total1 = p1 + p2;
  Price total2 = p1 + p1;
  Price total3 = p1 + p4;
  Price diff1 = p2 - p1;
  Price diff2 = p1 - p3;
  operator<<(cout, total1);
  operator<<(cout, total2);
  operator<<(cout, total3);
  operator<<(cout, diff1);
  operator<<(cout, diff2);
  cout << endl;
  operator<<(cout, p1);
  cout << endl;
  operator<<(cout, p2);
  cout << endl;
  
  cout << "$" << p1 << "+$" << p2 << "=$" << total1 << endl;
  cout << "$" << p1 << "+$" << p1 << "=$" << total2 << endl;
  cout << "$" << p1 << "+$" << p4 << "=$" << total3 << endl;
  cout << "$" << p2 << "+$" << p1 << "=$" << diff1 << endl;
  cout << "$" << p1 << "+$" << p3 << "=$" << diff2 << endl;

  return 0;
}

ostream& operator<<(ostream& o, Price& t){
  if(t.cent < 10)
    o << t.dollar << ".0" << t.cent;
  else
    o << t.dollar << "." << t.cent;
  return o;
}

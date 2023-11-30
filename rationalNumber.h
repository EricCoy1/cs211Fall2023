
//define the rNum class here. The data members are top and bottom.
#include <iostream>
using namespace std;

//defining rNum
#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
class rNum{
  //freind functions for non meber functions
  friend istream& operator>>(istream& i, rNum& r);
  friend ostream& operator<<(ostream& o, rNum& r);
  friend bool operator==(const rNum& r, rNum key);
  friend bool operator!=(const rNum& r, rNum key);
 private:
  //numerator and denominator
  int top;
  int bottom;
 public:
  rNum();
  rNum(int t, int b);
  rNum operator+(const rNum& r);
  bool operator>(const rNum& r);
};
#endif

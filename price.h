#include <iostream>

using namespace std;

#ifndef PRICE_H
#define PRICE_H
class Price{
  //friend ostream& operator<<(ostream& o, Price& t);
 private:
  int dollar;
  int cent;
 public:
  Price();
  Price(int d, int c);
  Price operator+(const Price& p);
  Price operator-(const Price& p);
};
#endif

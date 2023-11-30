#include <iostream>
#include "price.h"

using namespace std;

Price::Price(){
  dollar = 0;
  cent = 0;
}

Price::Price(int d, int c){
  dollar = d;
  cent = c;
}

Price Price::operator+(const Price& p){
  int dol = this->dollar + p.dollar;
  int cen = this->cent + p.cent;
  if(cen >= 100){
    cen = cen % 100;
    //if(cen == 0)
    //cen = 00;
      
    dol++;
  }

  Price total(dol, cen);
  return total;
}

Price Price::operator-(const Price& p){
  int dol = this->dollar - p.dollar;
  int cen = this->cent - p.cent;
  if(cen < 0){
    cen = cen + 100;
    dol--;

  }
  Price difference(dol, cen);
  return difference;
}

ostream& operator<<(ostream& o, Price& t){
  if(t.cent < 10)
    o << t.dollar << ".0" << t.cent;
  else
    o << t.dollar << "." << t.cent;
  return o;
}

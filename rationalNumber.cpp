#include <iostream>
#include <iomanip>
#include "rationalNumber.h"
using namespace std;

//default constructor: set top to 0 and bottom to 1
rNum::rNum(){
  top = 0;
  bottom = 1;
}


//non-default constructor: we won't be using it in the client, but we might as well make it.
rNum::rNum(int t, int b){
  top = t;
  bottom = b;
}



//Create all operator overloaded functions here. You need to figure out what you need by reading the client. 

//>> overloaded function to input rational numbers
istream& operator>>(istream& i, rNum& r){
  cout << endl << "\tEnter the top number: ";
  i >> r.top;
  cout << "\tEnter the bottom number: ";
  i >> r.bottom;
  return i;
} 


// << overloaded function to output rational numbers
ostream& operator<<(ostream& o, rNum& r){
  cout << r.top << "/" << r. bottom;
  return o;
}

rNum rNum::operator+(const rNum& r){
  int bot = this->bottom * r.bottom;
  int top1 = this->top * (bot / this->bottom);
  int top2 = r.top * (bot / r.bottom);
  int top = top1 + top2;
  rNum a(top, bot);
  return a;
}


bool rNum::operator>(const rNum& r){
  double n1 = this->top / this->bottom;
  double n2 = r.top / r.bottom;
  if(n1 > n2)
    return true;
  else 
    return false;
}

/*
bool operator==(const rNum& r, rNum key){
  if(r.top && r.bottom == key)
    return true;
}

bool operator!=(const rNum& r, rNum key){
  if(r.top && r.bottom != key)
    return false;
}
*/

//This is not an operator overloaded function.. This function will simplify a rational number to the simplest form.
/*????? rNum::simplify()
{

}
*/

#include <iostream>
using namespace std;

bool isLetter(char c){
  if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    return true;
  else
    return false;
}

char myToLower(char c){
  char lower = c;
  if(lower >= 65 && lower <= 90){
    lower = c + 32;
    return lower;
  }else
    return lower;
}

#include <iostream>
using namespace std;

const int MAX = 5;
typedef char el_t;

#ifndef STACK_H
#define STACK_H
class Stack{
 private:
  el_t el[MAX];
  int top;
  void stackError(string errorMsg);
 public:
  Stack();
  bool isEmpty();
  bool isFull();
  void push(el_t e);
  el_t pop();
  el_t topElem();
  void displayAll();
  void clearIt();

};
#endif

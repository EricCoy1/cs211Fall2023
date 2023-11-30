#include <iostream>
#include "stack.h"
using namespace std;

void Stack::stackError(string errorMsg){
  cout << errorMsg << endl;
}

Stack::Stack(){
  top = -1;
}

bool Stack::isEmpty(){
  if(top == -1){
    return true;
  } else {
    return false;
  }
}

bool Stack::isFull(){
  if(top >= MAX - 1){
    return true;
  } else {
    return false;
  }
}

void Stack::push(el_t e){
  if(isFull()){
    stackError("Error. Expression is too long.");
  } else {
    el[++top] = e;
  }
}

el_t Stack::pop(){
  if(isEmpty()){
    stackError("Error. Not enough operands.");
  } else {
    return el[top--];
  }
}

el_t Stack::topElem(){
  if(isEmpty() == true)
    stackError("Stack is empty");
  else
    return el[top];
}

void Stack::displayAll(){
  if(isEmpty() == true)
    cout << "[ empty ]\n";
  else
    for(int i = top; i > -1; i--){
      cout << el[i] << endl;
    }
}

void Stack::clearIt(){
  top = -1;
}

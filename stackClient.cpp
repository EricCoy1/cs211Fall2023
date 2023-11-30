#include <iostream>
#include "stack.h"
using namespace std;

void addPerson(Stack& s, string name);

int main(){

  Stack s;
  if(s.isEmpty() == true)
    cout << "The stack is empty.\n\n";
  addPerson(s, "Mike");
  addPerson(s, "Kathy");
  string topElem = s.topElem();
  cout << topElem << " is at the top.\n\n";
  addPerson(s, "Dave");
  addPerson(s, "Alice");
  addPerson(s, "Tom");
  if(s.isFull() == true)
    cout << "The stack is full.\n\n";
  s.displayAll();
  cout << endl << endl;
  addPerson(s, "Meg");
  s.pop();
  topElem = s.topElem();
  cout << topElem << " is at the top.\n\n";
  s.clearIt();
  if(s.isEmpty() == true)
    cout << "The stack is empty.\n";

  return 0;
}

void addPerson(Stack& s, string name){
  if(!s.isFull())
    s.push(name);
  else
    cout << "You cannot push. The stack is full\n\n";
}

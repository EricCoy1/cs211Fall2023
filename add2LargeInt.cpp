#include <iostream>
#include "LL.h"
using namespace std;

void createReverseLL(LL<int>& l, const string& s);
LL<int> addLLs(LL<int>& l1, LL<int>& l2);

int main(){
  string n1, n2;
  cout << "Enter the first number: ";
  cin >> n1;
  cout << "Enter the second number: ";
  cin >> n2;

  LL<int> L1;
  LL<int> L2;
  LL<int> total;
  
  //int x = n1.length();
  //cout << x << endl;
  //int y = '7' - 48;
  //cout << y << endl;
  createReverseLL(L1, n1);
  //L1.displayAll();
  //cout << endl;
  createReverseLL(L2, n2);
  //L2.displayAll();
  //cout << endl;
  addLLs(L1, L2, total);
  L1.displayAll();
  cout << " + ";
  L2.displayAll();
  cout << " = ";
  total.displayAll();
  cout << endl;
  L1.printAllReverse();
  cout << " + ";
  L2.printAllReverse();
  cout << " = ";
  total.printAllReverse();
  cout << endl;
  //int z = total.getCount();
  //cout << z;

  return 0;
}


void createReverseLL(LL<int>& l, const string& s){
  int i = s.length() - 1;
  while(i != -1){
    int y = s[i] - 48;
    l.addRear(y);
    i--;
  }
}

LL<int> addLLs(LL<int>& l1, LL<int>& l2, LL<int>& t){
  int carriedValue = 0;
  node<int>*p;
  node<int>*q;
  if(l1.count > l2.count){
    q = l2.front;
    for(p = l1.front; p != NULL; p = p->next){
      if(q != NULL){
	int sum = p->elem + q->elem + carriedValue;
	if(sum >= 10)
	  sum = sum - 10;
	carriedValue = (p->elem + q->elem) / 10;
	t.addRear(sum);
	q = q->next;
      }else {
      int sum = p->elem + carriedValue;
      carriedValue = (p->elem + carriedValue) / 10;
      if(sum >= 10)
	sum = sum - 10;
      t.addRear(sum);
      }
    }
    int sum = carriedValue;
    if(sum == 1)
      t.addRear(sum);
  }else if(l1.count < l2.count){
    p = l1.front;
    for(q = l2.front; q != NULL; q = q->next){
      if(p != NULL){
        int sum = q->elem + p->elem + carriedValue;
        if(sum >= 10)
          sum = sum - 10;
	carriedValue = (q->elem + p->elem) / 10;
        t.addRear(sum);
        p = p->next;
      }else {
	int sum = q->elem + carriedValue;
	carriedValue = (q->elem + carriedValue) / 10;
	if(sum >= 10)
	  sum = sum - 10;
	t.addRear(sum);
      }
    }
    int sum = carriedValue;
    if(sum == 1)
      t.addRear(sum);
  }else {
    for(p = l1.front, q = l2.front; p != NULL && q != NULL; p = p->next, q = q->next){
      int sum = p->elem + q->elem + carriedValue;
      if(sum >= 10)
	sum = sum - 10;
      carriedValue = (p->elem + q->elem) / 10;
      t.addRear(sum);
    }
    int sum = carriedValue;
    if(sum == 1)
      t.addRear(sum);
  }
  return t;
}

/*
int sum = p->elem + q->elem + carriedValue;
if(sum >= 10){
  sum = sum - 10;
 }
carriedValue = (p->elem + q->elem) / 10;
t.addRear(sum);
*/

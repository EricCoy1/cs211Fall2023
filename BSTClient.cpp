/*********************************
Template prepared by Kazumi Slott
CS211
Test client for BST labs
*********************************/
#include <iostream>
#include <cstdlib> //for rand()
#include "BST.h"
#include "LL.h"
using namespace std;


int main()
{
  srand(time(0)); //you need to include cstdlib
  LL<int> l;
  BST<int> b;
  for(int i = 0; i < 10000; i++){
    int num = rand() % + 1;
    l.addRear(num);
    b.insertNode(num);
  }

  int key;
  cout << "What number do you want to search for? ";
  cin >> key;

  
  cout << "BST *************************" << endl;
 
  

  cout << "LL************************" << endl;
  
  ??????????????????????????
  
  */
  return 0;
}

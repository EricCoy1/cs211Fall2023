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
  /*
  srand(time(0)); //you need to include cstdlib
  LL<int> l;
  BST<int> b;
  bool found;
  for(int i = 0; i < 10000; i++){
    int num = rand() % 10000 + 1;
    l.addRear(num);
    b.insertNode(num);
  }

  int key;
  cout << "What number do you want to search for? ";
  cin >> key;

  
  cout << "BST *************************" << endl;
 
  found = b.search(key);
  if(found == true)
    cout << "found\n";
  else
    cout << "not found\n";

  cout << "LL************************" << endl;
  
  found = l.search(key);
  if(found == true)
    cout << "found\n";
  else
    cout << "not found\n";
  */

 BST<int> b;
/*
 b.insertNode(5);
 b.insertNode(8);
 b.insertNode(3);
 b.insertNode(9);
 b.insertNode(6);
 b.insertNode(1);
 b.insertNode(0);
 b.insertNode(4);
 b.insertNode(7);
 b.insertNode(20);
 */
b.insertNode(5);
b.insertNode(3);
b.insertNode(8);
b.insertNode(2);
b.insertNode(4);
b.insertNode(1);
b.insertNode(10);

 cout << "----Print all elements using the in-order traversal-----" << endl;
 b.inOrderPrint();
 cout << endl;

 cout << "----Print all elements using the pre-order traversal-----" << endl;
 b.preOrderPrint();
 cout << endl;

 cout << "----Print all elements using the post-order traversal-----" << endl;
 b.postOrderPrint();
 cout << endl;

//int maxLength = b.getMaxLength();
//cout << maxLength << endl;
bool search;
search = b.searchRec(8);
cout << search << endl;


 cout << "\n---destructor gets called when b goes out of scope here---" << endl;
 

  return 0;
}

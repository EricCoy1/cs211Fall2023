#ifndef LL_H
#define LL_H
#include <iostream>
using namespace std;

template <class T>
struct node{
  T elem;
  node<T>* next;
};

template <class T>
class LL{
  //friend LL<int> addLLs(LL<int>& l1, LL<int>& l2, LL<int>& t);
  //friend bool palindrome(LL<char>& l);
 private:
  node<T>* front;
  node<T>* rear;
  int count;
  void LLError(const string& msg);
  void printAllReverse(node<T>* p);
 public:
  LL();
  bool isEmpty();
  void addRear(const T& el);
  void displayAll();
  void printAllReverse();
  T deleteFront();
  void addFront(const T& el);
  T deleteRear();
  void deleteNode(const T& e);
  void addInOrderAscend(const T& e);
  bool search(const T& e);
  int getCount();
  LL(const LL<T>& source);
  ~LL();
};

template <class T>
LL<T>::LL(){
  front = NULL;
  rear = NULL;
  count = 0;
}

template <class T>
bool LL<T>::isEmpty(){
  if(count == 0 && front == NULL && rear == NULL){
    return true;
  } else {
    return false;
  }
}


template <class T>
int LL<T>::getCount(){
  return count;
}

template <class T>
void LL<T>::addRear(const T& el){
  if(isEmpty()){
    front = rear = new node<T>;
  } else {
    rear->next = new node<T>;
    rear = rear->next;
  }
  rear->next = NULL;
  count++;
  rear->elem = el;
}

template <class T>
void LL<T>::displayAll(){
  if(isEmpty())
    cout << "[ empty ]\n";
  else {
    node<T>*p = front;
    while(p != NULL){
      cout << p->elem << " ";
      p = p->next;
    }
  }
}

template <class T>
void LL<T>::printAllReverse(node<T>* p){
  if(p == NULL)
    return;
  else{
    printAllReverse(p->next);
    cout << p->elem;
  }
}

template <class T>
void LL<T>::printAllReverse(){
  printAllReverse(front);
}

template <class T>
void LL<T>::LLError(const string& msg){
  cout << msg << endl;
}

template <class T>
T LL<T>::deleteFront(){
  if(isEmpty())
    LLError("Error: list is empty.");
  else {
    T temp = front->elem;
    node<T>*second = front->next;
    delete front;
    front = second;
    count--;
    if(front == NULL)
      rear = NULL;
    return temp;
  }
}

template <class T>
void LL<T>::addFront(const T& el){
  if(isEmpty()){
    front = rear = new node<T>;
  } else {
    //T temp = front->elem;
    node<T>*p = new node<T>;
    p->next = front;
    front = p;
    //front->elem = el;
    //p->elem = el;
  }
  count++;
  front->elem = el;
}

template <class T>
T LL<T>::deleteRear(){
  if(isEmpty())
    LLError("Error: list is empty.");
  else {
    T temp;
    if(front == rear){
      temp = rear->elem;
      front = rear = NULL;
      count--;
      return temp;
    }else {
      node<T>*p;
      for(p = front; p->next != rear; p = p->next){
	;
      }
      temp = rear->elem;
      delete rear;
      rear = p;
      rear->next = NULL;
      count--;
      return temp;
    }
  }    
}

template <class T>
void LL<T>::deleteNode(const T& e){
  node<T>* pre;
  node<T>* del;
  if(isEmpty()){
    return;
  }else{
    if(front->elem == e){
      deleteFront();
    }else{
      for(pre = front, del = front->next; del != NULL && del->elem != e; pre = del, del = del->next)
	;
      if(del != NULL){
	pre->next = del->next;
	if(del == rear)
	  rear = pre;
	delete del;
	count--;
      }
    }
  }
}

/*
  This function will add an element in between the elements that are larger and smaller than it. 
 */
template <class T>
void LL<T>::addInOrderAscend(const T& e){
  //if list is empty
  if(isEmpty())
    addFront(e);
  else{
    //if element to be added is less than the first element
    if(e < front->elem)
      addFront(e);
    //start of general code
    else{
    node<T>*p = front;
    while(p->next != NULL && p->next->elem < e)
      p = p->next;
    //if element to be added is greater than all elements
    if(p->next == NULL)
      addRear(e);
    //general code
    else{
      node<T>*n = new node<T>;
      n->elem = e;
      n->next = p->next;
      p->next = n;
      count++;
    }
    }
  }
}

template <class T>
bool LL<T>::search(const T& e){
  node<T>*p;
  if(isEmpty())
    return false;
  else{
    int counter = 0;
    for(p = front; p != NULL; p = p->next){
      counter++;
      if(p->elem == e){
	      cout << counter << " nodes checked" << endl;
	      return true;
      }
    }
    cout << counter << " nodes checked" << endl;
    return false;
  }
}

template <class T>
LL<T>::LL(const LL<T>& L){
  this->front = this->rear = NULL;
  this->count = 0;
  node<T>*p = L.front;
  while(p != NULL){
    this->addRear(p->elem);
    p = p->next;
    //count++; this was commented out because count was already being incremented in addRear so another count wasnt needed. It was inter
  }
}

template <class T>
LL<T>::~LL(){
  while(!isEmpty())
    deleteFront();
}
#endif

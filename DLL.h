#ifndef DLL_H
#define DLL_H
#include <iostream>
using namespace std;

template <class T>
struct node{
  T elem;
  node<T>* next;
  node<T>* prev;
};

template <class T>
class DLL{
 private:
  node<T>* front;
  node<T>* rear;
  int count;
  void DLLError(const string& msg);
 public:
  DLL();
  bool isEmpty();
  void addRear(const T& el);
  void displayAll();
  void printAllReverseDLL();
  T deleteFront();
  void addFront(const T& el);
  T deleteRear();
  void deleteNode(const T& e);
  void addInOrderAscend(const T& e);
  bool search(const T& e);
  int getCount();
  DLL(const DLL<T>& source);
  ~DLL();
};

template <class T>
DLL<T>::DLL(){
  front = NULL;
  rear = NULL;
  count = 0;
}

template <class T>
bool DLL<T>::isEmpty(){
  if(count == 0 && front == NULL && rear == NULL){
    return true;
  } else {
    return false;
  }
}


template <class T>
int DLL<T>::getCount(){
  return count;
}

template <class T>
void DLL<T>::addRear(const T& el){
  if(isEmpty()){
    front = rear = new node<T>;
    rear->prev = NULL;
  }else{
    rear->next = new node<T>;
    rear->next->prev = rear;
    rear = rear->next;
  }
  rear->next = NULL;
  count++;
  rear->elem = el;
}

template <class T>
void DLL<T>::displayAll(){
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
void DLL<T>::printAllReverseDLL(){
  if(isEmpty())
    cout << "[ empty ]\n";
  else{
    node<T>*p = rear;
    while(p != NULL){
      cout << p->elem << " ";
      p = p->prev;
    }
  }
}


template <class T>
void DLL<T>::DLLError(const string& msg){
  cout << msg << endl;
}

template <class T>
T DLL<T>::deleteFront(){
  if(isEmpty())
    DLLError("Error: list is empty.");
  else {
    T temp = front->elem;
    node<T>*second = front->next;
    delete front;
    front = second;
    if(front != NULL)
      front->prev = NULL;
    count--;
    if(front == NULL)
      rear = NULL;
    return temp;
  }
}

template <class T>
void DLL<T>::addFront(const T& el){
  if(isEmpty()){
    front = rear = new node<T>;
    front->next = NULL;
    front->prev = NULL;
  } else {
    node<T>*p = new node<T>;
    p->next = front;
    front->prev = p;
    p->prev = NULL;
    front = p;
    //front->elem = el;
    //p->elem = el;
  }
  count++;
  front->elem = el;
}

template <class T>
T DLL<T>::deleteRear(){
  if(isEmpty())
    DLLError("Error: list is empty.");
  else {
    T temp;
    if(front == rear){
      temp = rear->elem;
      front = rear = NULL;
      count--;
      return temp;
    }else {
      node<T>*p = rear->prev;
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
void DLL<T>::deleteNode(const T& e){
  node<T>* del;
  if(isEmpty()){
    return;
  }else{
    if(front->elem == e){
      deleteFront();
    }else{
      for(del = front; del != NULL && del->elem != e;del = del->next)
	;
      if(del != NULL){
	if(del == rear){
	  rear = del->prev;
	  rear->next = NULL;
	  delete del;
	  count--;
	}else{
	  del->prev->next = del->next;
	  del->next->prev = del->prev;
	  delete del;
	  count--;
	}
      }
    }
  }
}
/*
  This function will add an element in between the elements that are larger and smaller than it. 
 */
template <class T>
void DLL<T>::addInOrderAscend(const T& e){
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
	n->prev = p;
	p->next = n;
	n->next->prev = n;
	count++;
      }
    }
  }
}

template <class T>
bool DLL<T>::search(const T& e){
  node<T>*p;
  if(isEmpty())
    return false;
  else{
    for(p = front; p != NULL; p = p->next){
      if(p->elem == e)
	return true;
    }
    return false;
  }
}

template <class T>
DLL<T>::DLL(const DLL<T>& L){
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
DLL<T>::~DLL(){
  while(!isEmpty())
    deleteFront();
}
#endif

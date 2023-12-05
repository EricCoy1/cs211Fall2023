/*************************
Template prepared by Kazumi Slott
CS211
BST class
 ************************/
#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <class T> //forward declaration
class BST;

template <class T>
class Node
{
  friend class BST<T>; //make BST a friend of Node so it can access the private members

 private:
   T elem;
   Node<T>* right;
   Node<T>* left;

 public:
   Node(){right = NULL; left = NULL;} 
   Node(const T& e){elem = e; right = NULL; left = NULL;}
};


template <class T>
class BST
{
private:
  Node<T>* root;
  void insertNode(Node<T>*&, const T&);
  void inOrderPrint(Node<T>*p);
  void preOrderPrint(Node<T>*p);
  void postOrderPrint(Node<T>*p);
  int getMaxLength(Node<T>*p);
  bool searchRec(Node<T>*p, const T& e);
public:
  BST();
  void insertNode(const T&);
  bool search(const T&);
  void inOrderPrint();
  void preOrderPrint();
  void postOrderPrint();
  int getMaxLength();
  bool searchRec(const T& key);
  void destroy(Node<T>*p);
  ~BST();
};


template <class T>
BST<T>::BST()
{
  root = NULL;
}

template <class T>
void BST<T>::inOrderPrint(){
  inOrderPrint(root);
}

template <class T>
void BST<T>::inOrderPrint(Node<T>*p){
  if(p == NULL)
    return;
  inOrderPrint(p->left);
  cout << p->elem << "-->";
  inOrderPrint(p->right);
}

template <class T>
void BST<T>::preOrderPrint(){
  preOrderPrint(root);
}

template<class T>
void BST<T>::preOrderPrint(Node<T>*p){
  if(p == NULL)
    return;
  cout << p->elem << "-->";
  preOrderPrint(p->left); 
  preOrderPrint(p->right);
}

template <class T>
void BST<T>::postOrderPrint(){
  postOrderPrint(root);
}

template <class T>
void BST<T>::postOrderPrint(Node<T>*p){
  if(p == NULL)
    return;
  postOrderPrint(p->left);
  postOrderPrint(p->right);
  cout << p->elem << "-->";
}

template <class T>
void BST<T>::insertNode(const T& e){
  insertNode(root, e);
}


template <class T>
void BST<T>::insertNode(Node<T>*& p, const T& e)
{
  if(p == NULL)
    p = new Node<T>(e);
  else if(e < p->elem)
    return insertNode(p->left, e);
  else // e > p->elem
    return insertNode(p->right, e);
}

template <class T>
bool BST<T>::search(const T& e)
{
  Node<T>*p = root;
  int counter = 0;
  while(p != NULL){
    if(p->elem == e){
      cout << counter << " nodes checked"<< endl;
      return true;
    } else if(p->elem < e){
        p = p->right;
    }
    else
      p = p->left;
    counter++;
  }

  //display the counter      
  cout << counter << " nodes checked"<< endl;
  return false;
}

template <class T>
int BST<T>::getMaxLength(){
  return getMaxLength(root);
}

template <class T>
int BST<T>::getMaxLength(Node<T>*p){
  if(p == NULL)
    return 0;
  else{
    return 1 + getMaxLength(p->left);
  }
}

template <class T>
bool BST<T>::searchRec(const T& key){
  searchRec(root, key);
}

template <class T>
bool BST<T>::searchRec(Node<T>*p, const T& e){
  if(p == NULL){
    return false;
  }else{
    searchRec(p->left, e);
    if(p->elem == e)
      return true;
    searchRec(p->right, e);
    if(p->elem == e)
      return true;
  }
  return false;
}

template <class T>
void BST<T>::destroy(Node<T>*p){
  if(p == NULL)
    return;
  destroy(p->left);
  destroy(p->right);
  cout << p->elem << "-->";
  delete p;
}

template <class T>
BST<T>::~BST(){
  destroy(root);
}


#endif

/**********************************************************
CS211
myVector client
template created by Kazumi Slott
3-13-2020

This program will test the myVector class
***********************************************************/
#include <iostream>
using namespace std;
//A. include the header file that contains myVector class definishion and function implementations
#include "myVector.h"

//B. Create a cat struct that has name (string) and id (int)
struct Cat{
  string name;
  int id;
};

//C. Create an operator overloading function for >> to fill a cat object
istream& operator>>(istream& in, Cat& c)
{
  cout << "Enter a cat name: ";
  in >> c.name;
  cout << "Enter a cat id: ";
  in >> c.id;
  return in;
}

//D. Create an operator overloading function for << to print a cat object
//   e.g.  Tom (1)  
ostream& operator<<(ostream& out, Cat& c)
{
  out << c.name << " (" << c.id << ")\n";
  return out;
}
/*
template <class T>
void print(const myVector<T>& v);
*/
int main()
{
  myVector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  cout << "---- 1 2 3 push_back ---- " << endl;
  print(v);

  v.erase(1);
  cout << "---- 1 3 erase ----" << endl;   
  print(v);

  cout << "--- illegal index 1 3 erase ---" << endl;
  v.erase(2);
  print(v);

  v.erase(0);
  cout << "--- 3 erase ----" << endl;
  print(v);

  v.insert(1, 9);
  cout << "--- 3 9 insert ---" << endl;
  print(v);

  v.insert(1, 8);
  cout << "--- 3 8 9 insert ---" << endl;
  print(v);

  v.insert(0, 7);
  cout << "--- 7 3 8 9 insert ---" << endl;
  print(v);

  cout << "--- illegal index 7 3 8 9 insert ---" << endl;
  v.insert(5, 6);
  print(v);

  cout << endl;

  cout << "--- Testing operator[]. 14 ---" << endl;
  v[0] = v[0] * 2;
  cout << v[0] << endl << endl;

  //E. Create a vector that will hold cats
  myVector<Cat> vc;
  Cat  c;  //create a cat struct

  //F. Add 3 cats
  for(int i = 0; i < 3; i++)
    {
      cin >> c; //fill the cat struct
      vc.push_back(c); //add the filled cat into the vector
    }
 
  //G. print all the cats in the cat vector
  print(vc);
}

//H. Create a template print function that will print all the elements from a vector of any data type
/*template <class T>
void print(const myVector<T>& v)
{
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
  cout << endl;
  }*/






#include <iostream>
#include <fstream>
#include "LL.h"
#include "utility.h"
using namespace std;

void createLL(LL<char>& l, string& s);
bool palindrome(LL<char>& l);

int main(){
  /*testing sentence from keyboard
  LL<char> L;
  string sentence;
  cout << "Enter a sentence: ";
  getline(cin, sentence);
  createLL(L, sentence);
  if(palindrome(L))
    cout << "\"" << sentence << "\" is a palindrome.\n";
  else
    cout << "\"" << sentence << "\" is NOT a palindrome.\n";
  */
  /*L.displayAll();
  cout << endl;
  */
  ifstream input_file;
  input_file.open("palindrome.dat");
  if(input_file.is_open() == false){
    return 1;
  }
  do{
    LL<char> L;
    string sentence;
    getline(input_file, sentence);
    createLL(L, sentence);
    if(palindrome(L))
      cout << "\"" << sentence << "\" is a palindrome.\n";
    else
      cout << "\"" << sentence << "\" is NOT a palindrome.\n";
  }while(input_file.eof() == false);
  input_file.close();

  return 0;
}
/*
function that creates a linked list full of characters from a string without grammar(ex: ,.-?!etc)
*/
void createLL(LL<char>& l, string& s){
  for(int i = 0; i < s.length(); i++){
    char character = s[i];
    if(isLetter(s[i])){
      character = myToLower(s[i]);
      l.addFront(character);
    }else
      ;
  }
}
/*
This function returns takes in a linked list full of characters and returns true if the linked list is a palindrome and false if not.
*/
bool palindrome(LL<char>& l){
  while(l.count != 0){
    if(l.front->elem == l.rear->elem){
      if(l.count == 1)
	l.deleteRear();
      else{
	l.deleteFront();
	l.deleteRear();
      }
    }else
      return false;
  }
  if(l.count == 0)
    return true;
}

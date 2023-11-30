/*********************************************************
Template provided by Kazumi Slott

Name: Eric Coy
This client tests the queue class memeber functions.
********************************************************/
#include <iostream>
using namespace std;
#include "queue.h"
#include "checkInput.h"

void showMenu();

int main()
{

  Queue q;
  int YN;
  int choice;
  do{
    showMenu();
    cout << "choose an option: ";
    choice = getData(1, 7, "Invalid entry. Please enter a valid entry: ");
    switch(choice){
    case 1:
      el_t element;
      cout << "Enter a character to add: ";
      cin >> element;
      q.add(element);
      cout << "Would you like to continue using the program?(Y/N) ";
      YN = getYN("Invalid character. Enter valid character: ");
      break;
    case 2:
      q.remove();
      cout << "Would you like to continue using the program?(Y/N) ";
      YN = getYN("Invalid character. Enter valid character: ");
      break;
    case 3:
      //el_t frontElement;
      //frontElement = q.getFront();
      //cout << "The front element is " << frontElement << endl;
      q.getFront();
      cout << "Would you like to continue using the program?(Y/N) ";
      YN = getYN("Invalid character. Enter valid character: ");
      break;
    case 4:
      q.goToBack();
      cout << "Would you like to continue using the program?(Y/N) ";
      YN =getYN("Invalid character. Enter valid character: ");
      break;
    case 5:
      int numOfElements;
      numOfElements = q.getSize();
      cout << "The queue has " << numOfElements << " elements.\n";
      cout << "Would you like to continue using the program?(Y/N) ";
      YN = getYN("Invalid character. Enter valid character: ");
      break;
    case 6:
      q.displayAll();
      cout << "Would you like to continue using the program?(Y/N) ";
      YN = getYN("Invalid character. Enter valid character: ");
      break;
    case 7:
      return 1;
      break;
    default:
      break;
      
    };


  }while(YN == 'Y');
  
  return 0;
}


void showMenu()
{
  cout << "1: add a new element" << endl; //(testing add(), isFull())
  cout << "2: remove an element" << endl; // (testing remove(), isEmpty())
  cout << "3: check the front element" << endl; //(testing getFront(), isEmpty())
  cout << "4: go back to the rear" << endl; //(testing goToBack())
  cout << "5: get the number of elements in the queue" << endl; //(testing getSize()) 
  cout << "6: display all the elements in the queue" << endl; //(testing displayAll()) 
  cout << "7: quit program" << endl;
}

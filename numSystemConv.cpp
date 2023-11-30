/***************************************************************************
CS211
Template prepared by Kazumi Slott 
Your name: Eric Coy

Program description:

***************************************************************************/
#include <iostream>
using namespace std;
#include "/cs/slott/cs211/checkInput.h"
#include "stack.h"

int getBase();
char convertToChar(int n);

int main()
{
  int dec;
  int base;

  cout << "Enter a number in base 10: ";

  //get a decimal number by calling getData in checkInput.h. Accept a numer 
  //between 1 and 999999.
  getData(1,999999, "Invalid input. Enter a valid input. ");

  //get a base (2, 8 or 16) by calling getBase
  base = getBase();
  char test;
  test = convertToChar(14);
  cout << test << endl;


  cout << "----------- Using recursion ---------------" << endl;
  //call convertRec to show the number in the base number system of the user’s choice


  cout << endl;

  cout << "----------- Using a stack ---------------" << endl;
  //Call convertStack to show the number in the base number system of the user’s choice


  cout << endl;
  return 0;
}

/****************************************************************************
This function asks for a number system to which a decimal number is converted, either 2, 8 or 16.
It rejects bad inputs other than 2, 8 or 16.
It returns either 2, 8 or 16
****************************************************************************/
int getBase()
{
  int base;//user input

  cout << "Enter a base to convert the base 10 number to: ";
  cin >> base;

  while(base != 2 && base != 8 && base != 16){
    cout << "Inavalid Input. Please Enter 2,8, or 16: )";
    cin >> base;
  }
  return base;
}

/****************************************************************************
This function receives an integer between 0 and 15 and returns the character.
If n = 0 .. 9, it returns '0' .. '9'
If n = 10 .. 15, returns 'A' .. 'F'

n is an integer between 0 and 15
****************************************************************************/
char convertToChar(int n)
{
  char newChar;
  if(n >= 0 && n <= 9){
    newChar = '0' + n;
    return newChar;
  }
  else if(n >= 10 && n <= 15){
    newChar = 'A' + n - 10;
    return newChar;
  }
}

/***************************************************************************
This is a <<recursive>> function to convert a decimal number to a different number system and print it.

n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
***************************************************************************/
void convertRec(int n, int b)
{
  switch(b){
  case 2:
    break;
  case 8:
    break;
  case 16:
    break;
  default:
    break;
  }
}

/**************************************************************************
This function uses a stack to convert a decimal number to a different number system and prints it.
This is not a recursive function.

n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
**************************************************************************/
void convertStack(int n, int b)
{
  switch(b){
  case 2:
    break;
  case 8:
    break;
  case 16:
    break;
  default:
    break;
  }
}

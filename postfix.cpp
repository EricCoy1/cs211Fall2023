#include <iostream>
using namespace std;
#include "stack.h"

bool isOperand(char ch);
int charToInt(char ch);
bool isOperator(char ch);
int doMath(int opr1, char opt, int opr2);

int main(){
  Stack ex;
  string expr;
  cout << "Enter an expression: ";
  cin >> expr;
  

  for(int i = 0; i < expr.length(); i++){
    int newInt;
    int operand1;
    int operand2;
    int answer;
    if(isOperand(expr[i])){
      newInt = charToInt(expr[i]);
	ex.push(newInt);
    } else if(isOperator(expr[i])){
      operand1 = ex.pop();
      operand2 = ex.pop();
      answer = doMath(operand1, expr[i], operand2);
      ex.push(answer);
    } else {
      return 1;
    }
  } 

  int finalAnswer = ex.pop();
  cout << "= " << finalAnswer;

  //ex.displayAll();

  /*int nInt;
  nInt = charToInt(expr[4]);
  cout << endl << nInt;
  */
  return 0;
}

/*************************************************
This function checks to see if the passed character is an operand: 0 - 9. It returns true if it is an operand, otherwise returns false.

ch is a character
**************************************************/
bool isOperand(char ch){
  if(ch >= '0' && ch <= '9')
    return true;
  else 
    return false;
}

/*************************************************
This function turns the passed character into an integer.
It returns the new integer

ch is a character
**************************************************/
int charToInt(char ch){
  int charInt;
  if(isOperand(ch) == true)
    charInt = ch - 48;
  return charInt;
}
/*************************************************
This function checks to see if the passed character is an operator: +, -, *, or /. It returns true if it is one of the operators, otherwise returns false.

ch is a character
**************************************************/
bool isOperator(char ch){
  switch(ch){
  case '+':
    return true;
    break;
  case '-':
    return true;
    break;
  case '*':
    return true;
    break;
  case '/':
    return true;
    break;
  default:
    cout << "Invalid item was found (" << ch << ")\n";
    return false;
    break;
  }
}

/*************************************************
This function performs the calculation with operand 1 and operand 2 based on the operator. It returns the answer.

opr1 is an integer
opr2 is an integer
ch is a character
**************************************************/
int doMath(int opr1, char opt, int opr2){
  int ans;
  switch(opt){
  case '+':
    ans = opr2 + opr1;
    return ans;
    break;
  case '-':
    ans = opr2 - opr1;
    return ans;
    break;
  case '*':
    ans = opr2 * opr1;
    return ans;
    break;
  case '/':
    ans = opr2 / opr1;
    return ans;
    break;
  default:
    break;
  }
}

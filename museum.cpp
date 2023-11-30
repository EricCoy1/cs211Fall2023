#include <iostream>
#include "array.h"
using namespace std;
#include "/cs/slott/cs211/checkInput.h" //for getData and getYN functions


int showMenu();
void getVisitorInfo(string c[], int a[], double t[], int& arS);
bool checkPassword();
char showStatistic(string c[], int a[], double t[], int arS);

int main(){

  const int MAX = 100;
  string countries[MAX];
  int age[MAX];
  double hours[MAX];
  int arSize = 0;
  int choice;
  bool password;
  char YN;
  do{
    choice = showMenu();
    switch(choice){
    case 1:
      getVisitorInfo(countries, age, hours, arSize);
      break;
    case 2:
      password = checkPassword();
      switch(password){
      case true:
	showStatistic(countries, age, hours, arSize);
	break;
      default:
	break;
      }
      break;
    default:
      break;

    }
  
  }
  while(choice == 1 || password == false || YN == 'Y' || YN == 'y'); //|| getYN) 

  return 0;
}

//museum menu
int showMenu(){
  int choice;//choice user enters for menu
  //presents user with 2 choices for the menu
  cout << "=============================================\n";
  cout << "1. Visitor\n2. Museum Staff\n";
  cout << "Enter your choice: ";
  //user enters choice until a valid one is provided
  choice = getData(1, 2, "Invalid choice. Enter 1 or 2: ");  
  if(choice == 1)
    cout << endl;
  //returns value of choice for switch statement to call functions
  return choice;
}

//collects visitor info
void getVisitorInfo(string c[], int a[], double t[], int& arS){
  cout << "Enter your country: ";
  //user enters country
  cin >> c[arS];
  cout << "Enter your age: ";
  //user enters age until a valid age is provided
  a[arS] = getData(0, 200, "The age has to be between 0 and 200. Enter again: ");
  cout << "Enter the number of hours you explored: ";
  //user enters hours until a valid time is provided
  t[arS] = getData(0.0, 10.0, "The number of hours has to be between 0 and 10.0 Enter again: ");
		   arS++;//updates size of each array
}

//asks user for password if they are museum staff
bool checkPassword(){
  int password;
  cout << "Enter the password: ";
  cin >> password;
  if(password != 5678){
    cout << "Password is wrong\n";
    return false;
  } else {
    cout << endl;
  return true;
  }
}

//shows visitor statistic when password is correct
char showStatistic(string c[], int a[], double t[], int arS){
  char YN;
  cout << "The total number of visitors is " << arS << endl << endl;
  if(arS == 0){
    cout << "Do you want to close the museum? Y or N:";
    YN = getYN("Invalid answer. Enter Y or N: ");
    return YN;
  } else if(arS > 0){
    cout << "-------- The names of the countries of visitors -------\n";
    sort(c, arS);
    for(int i = 0; i < arS; i++){
      print(c, arS);
    }
    cout << endl;
    cout << "Do you want to close the museum? Y or N:";
    YN = getYN("Invalid answer. Enter Y or N: ");
    return YN;
  }
}

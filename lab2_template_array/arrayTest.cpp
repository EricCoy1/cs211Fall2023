/***************************************************************
CS211
Template prepared by Kazumi Slott
1-28-2020

This program tests array.h
**************************************************************/
#include <iostream>
#include <iomanip>
#include "array.h"


/*template <class T>
void fill(T a[], int n);
template <class T>
void print(T a[], int n);
template <class T>
int getHighest(T a[], int n);
template <class T>
int getLowest(T a[], int n);*/

int main()
{
  //declare const called SZ_I set to 7
  const int SZ_I = 7;
  //declare const called SZ_D set to 3
  const int SZ_D = 3;
  //declare const called SZ_C set to 5
  const int SZ_C = 5;

  //create an integer array that has SZ_I slots
  int I_ar[SZ_I];
  //create a double array that has SZ_D slots
  double D_ar[SZ_D]; 
  //create a character array that has SZ_C slots
  char C_ar[SZ_C];

  //call fill with the integer array
  cout << "------ Filling the integer array ------\n";
  fill(I_ar, SZ_I);
  //call fill with the double array
  cout << "------ Filling the double array ------\n";
  fill(D_ar, SZ_D);
  //call fill with the character array
  cout << "------ Filling the character array ------\n";
  fill(C_ar, SZ_C);
  
  //call print (with 2 parameters) with the integer array
  print(I_ar, SZ_I);
  cout << endl;
  //call print with the double array
  print(D_ar, SZ_D);
  cout << endl;
  //call print with the character array
  print(C_ar, SZ_C);
  cout << endl;
  
  //call getHighest with the character array and show the highest value along with its location
  getHighest(C_ar, SZ_C);
  //call getLowest with the duoble and show the lowest value along with its location
  getLowest(D_ar, SZ_D);
  //call getAvg with the integer array and show the returend value
  getAvg(I_ar, SZ_I);

  //call unique with integer array and show unique array and the number of unique numbers
  cout << "the total number of unique intergers is " << unique(I_ar, I_ar, SZ_I) << endl;
  //unique(I_ar, I_ar, SZ_I);
  //call unique with character array and show unique array and the number of unique numbers


  //sort the double array and print it
  sort(D_ar, SZ_D);
  print(D_ar, SZ_D);
  cout << endl;
  //sort the character array and print it
  sort(C_ar, SZ_C);
  print(C_ar, SZ_C);

  return 0;
}

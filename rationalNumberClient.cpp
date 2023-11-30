/********************************************
Template created by Kazumi Slott
CS211
Date: 10/4/23
Your name: Eric Coy
Description of your program: ???????????????
********************************************/
#include <iostream>
using namespace std;
#include "array.h"  //This is your array.h
#include "rationalNumber.h" //inlcude rNum class

int main()
{
  //create rNum objects
  rNum n1;
  rNum n2;
  rNum ans;

  //enter the first rational number
  cout << "\n-------------- 1 -----------------" << endl;
  cout << "Rational Number 1";
  cin >> n1;
  //display the first rational number
  cout << "n1 is " << n1 << endl;
  //enter the second rational number
  cout << "\n-------------- 2 -----------------" << endl;
  cout << "\nRational Number 2";
  cin >> n2;
  //display the second rational number
  cout << "n2 is " << n2 << endl; 
  //compute the sum of the 1st and 2nd rational numbers
  cout << "\n-------------- 3 -----------------" << endl;
  ans = n1 + n2;
  //display the sum of the1st and 2nd rational numbers
  cout << n1 << " + " << n2 << " = " << ans << endl;
  //create an rNum array of rational numbers of size 
  cout << "\n-------------- 4 -----------------" << endl;
  const int SIZE = 3;
  //Declare an array of rNums that has SIZE slots
  rNum ar[SIZE];
  
  //fill the array by calling fill() in your array.h
  fill(ar, SIZE);
  //ca;;ing print to see if array is filled
  cout << "Checking to see if the array is filled" << endl;
  //print the array by calling print() in your array.h
  print(ar, SIZE);
  cout << endl;
  
  cout << "\n-------------- 5 -----------------" << endl;
  //sort the array in ascending order by calling sort() in your array.
  sort(ar, SIZE);

  
  cout << "Checking to see if the array is sorted in ascending order" << endl;
  //print the array by calling print() in your array.h
  print(ar, SIZE);
  cout << endl;
  

  /*
  cout << "\n-------------- 6 -----------------" << endl;
  cout << "Checking to see if " << n1 << " is in the array " << endl;
  //Call find() in your array.h to see if n1 exists in the array. Say found or not found. See #6 in the test runs in the hw document.   
  find(ar, SIZE, n1);
 
  
  cout << "\n-------------- 7 -----------------" << endl;
  cout << "n1 is " << n1 << " n2 is " << n2 << " before n1 += n2" << endl;
  n1 += n2;
 
  cout << "After n1 += n2, n1 is " << n1 << endl << endl;
  */  
  return 0;
}

  


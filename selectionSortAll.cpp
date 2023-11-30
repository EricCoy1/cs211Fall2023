/****************************************************
Template written by Kazumi Slott
CS211
selection sort lab

This program has 4 different selection sort functions.
*****************************************************/
#include <iostream>
#include "array.h"
#include <cstdlib>
using namespace std;
// include your array.h *** array.h included for print & fill, etc.

void selectionSort1(int array[], int N);
void selectionSort2(int array[], int N);
void selectionSort3(int array[], int N);
void selectionSort4(int array[], int N);
void test(int code);


int main()
{
  int code1 = 1;
  int code2 = 2;
  int code3 = 3;
  int code4 = 4;

  cout << "------ testing selectionSort1: Ascending moving largest to end  ------" << endl;
  test(code1);

  cout << "\n------ testing selectionSort2: Descending moving smallest to end  ------" << endl;
  test(code2);

  cout << "\n------ testing selectionSort3: Ascending moving smallest to beginning  ------" << endl;
  test(code3);

  cout << "\n------ testing selectionSort4: Descending moving largest to beginning  ------" << endl;
  test(code4);

  return 0;
}

//This function fills the array with random numbers between 1 and 100
void fill(int array[], int N)
{
  srand(time(0));
  for(int i = 0; i < N; i++){
    array[i] = rand() % 100 + 1;
  }

}



 
//       1 for selectionSort1
//       2 for selectionSort2
//       3 for selectionSort3
//       4 for selectionSort4

void test(int code)
{
  const int SIZE = 10; //constant SIZE set to 10
 
  int ar[SIZE];//declare an integer array using SIZE  

  fill(ar, SIZE); //fill the array by calling fill()

  print(ar, SIZE); //print the array by calling print() in array.h
  

  //create a switch statement here to call a different sort function depending on the code.
  switch(code){
  case 1:
    selectionSort1(ar, SIZE);
    break;
  case 2:
    selectionSort2(ar, SIZE);
    break;
  case 3:
    selectionSort3(ar, SIZE);
    break;
  case 4:
    selectionSort4(ar, SIZE);
    break;
  default:
    break;
  };

  cout << endl;

  print(ar, SIZE); //print the array - hopefully the numbers are sorted correctly

}



//this function sorts the numbers in ascending order by moving the largest to the end: smallest to largest
void selectionSort1(int array[], int N) 
{
  int lrgIndx; //the index of the largest value
  int temp; //temporary variable that holds the largest value

  //last is the last index in unsorted part
  for(int last = N-1; last >= 1; last--) 
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted part ([0..last])
      for(int i = 1; i <= last; i++) 
	{
	  if(array[i] > array[lrgIndx]) //The current item is larger 
	    lrgIndx = i;
	}

      //swap the largest with the last item in the unsorted part
      temp = array[lrgIndx]; 
      array[lrgIndx] = array[last]; 
      array[last] = temp;
    } 
}



//Change this function so it sorts the numbers in descending order by moving the smallest to the end: largest to smallest                                                                    
//You can change the variable names to suit their purposes. 
//The structure of this code shouldn't change.
void selectionSort2(int array[], int N)
{
  int smlIndx; //index of the smallest value                                                                                                                                               
  int temp; //temporary variable that holds the smallest value
                                                                                                                                  
  //last is the last index in the unsorted part                                                                                                                                              
  for(int last = N-1; last >= 1; last--)
    {
      smlIndx = 0; //assuming first item is smallest
                                                                                                                                      
      //find the smallest in unsorted part                                                                                                        
      for(int i = 1; i <= last; i++)
        {
          if(array[i] < array[smlIndx]) //the current item is smaller                                                                                                                
            smlIndx = i;
        }

      //swap the smallest with the last item in the unsorted part                                                                                                                  
      temp = array[smlIndx];
      array[smlIndx] = array[last];
      array[last] = temp;
    }
}




//Change this function so it sorts the numbers in ascending order by moving the smallest to the beginning: smallest to largest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort3(int array[], int N)
{
  int smlIndx; //index of the smallest value                                                                                                                                                               
  int temp; //temporary variable to hold the smallest value                                                                                                                                                   
  //first is the first index in the unsorted part                                                                                                                                    
  for(int first = 0; first <= N - 1; first++)
    {
      smlIndx = N - 1; //assume the last index is the smallest                                                                                                                                                  
      //find the smallest in the unsorted part                                                                                                                                                      
      for(int i = N - 2; i >= first; i--)
        {
          if(array[i] < array[smlIndx]) //current item is smaller                                                                                                                                            
            smlIndx = i;
        }

      //swap the smallest with the first item in the unsorted part                                                                                                                                                                              
      temp = array[smlIndx];
      array[smlIndx] = array[first];
      array[first] = temp;
    }
}



//Change this function so it sorts the numbers in descending order by moving the largest to the beginning: largest to smallest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort4(int array[], int N)
{
  int lrgIndx; //index of the largest value                                                                                                                                              
  int temp; //temporary variable to hold largest value                                                                                                                                         
  //first is the first index of the unsorted part                                                                                                                                             
  for(int first = 0; first <= N - 1; first++)
    {
      lrgIndx = N - 1; //assume the first index is the largest                                                                                                                                 
      // find the largest in the unsorted part                                                                                                                                                      
      for(int i = N - 2; i >= first; i--)
        {
          if(array[i] > array[lrgIndx]) //current item is larger                                                                                                                                            
            lrgIndx = i;
        }

      //swap the largest with the first item in the unsorted part                                                                                                                              
      temp = array[lrgIndx];
      array[lrgIndx] = array[first];
      array[first] = temp;
    }
}












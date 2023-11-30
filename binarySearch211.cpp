/***************************************************************************
CS211
Template created by Kazumi Slott
Implement binary search that works on an ascending and descending ordered list.
Your program will abort if the function doesn't return the correct value. 

Your name: Eric Coy
*****************************************************************************/
#include <iostream>
#include <assert.h>
using namespace std;

void reverseArray(int a[], int s);
int binarySearchAscend(const int a[], int s, int key);
int binarySearchDescend(const int a[], int s, int key);

int main()
{
  const int SIZE = 10;
  int ar[SIZE] = {1, 10, 20, 30, 40, 50, 60, 70, 80, 90};
  //testing reverseArray function
  /*
  for(int i = 0; i < SIZE; i++){
    cout << ar[i] << " ";
  }
  cout << endl;
  reverseArray(ar, SIZE);
  for(int i = 0; i < SIZE; i++){
    cout << ar[i] << " ";
  }
  cout << endl;
  */
  //test binarySearchAscend()
  for(int i = 0; i < SIZE; i++)
    assert(binarySearchAscend(ar, SIZE, 55) == -1);  //assert() terminates the program if the condition is false.

  assert(binarySearchAscend(ar, SIZE, 20) == 2); 
  int num = binarySearchAscend(ar, SIZE, 20);
  cout << num << endl;

  //call reverseArray() to reverse the elements in ar 
  reverseArray(ar, SIZE);
  //test binarySearchDescend() - mimic how you tested binarySearchAscend()
  assert(binarySearchDescend(ar, SIZE, 55) == -1);
  
  assert(binarySearchDescend(ar, SIZE, 30) == 6);
  num = binarySearchDescend(ar, SIZE, 30);
  cout << num << endl;
 
  return 0;
}



/****************************************************************************
This functioon reverse the contents of the array. Don't make a second array.
e.g. If ar is [5, 1, 3, 8, 2], this function changes the array to [2, 8, 3, 1, 5]
a is an integer array of any size.
s is the size of the array.
****************************************************************************/
void reverseArray(int a[], int s)
{
  int first = 0;
  int last = s - 1;
  int temp;
  while(first < last){
    temp = a[first];
    a[first] = a[last];
    a[last] = temp;
    first++;
    last--;
  }
}


/****************************************************************************
This function returns the index where key is found or -1 if key is not found.
a is an integer array of any size sorted in ascending order.
s is the size of the array.
key is the number being searched for.
****************************************************************************/
int binarySearchAscend(const int a[], int s, int key)
{
  int l = 0; //left boudary starts at first index
  int r = s - 1; //right boundary starts at last index
  int m; //middle point between left and right.

  //When l and r cross over, search ends. --> key was not found. 
  while(l < r)
    {
      //calculate the middle point between l and r
      m = (l + r)/2;

      if(a[m] == key) //key was found
	return m;
      else if(key > a[m])
	l = m + 1;
      else if(key < a[m])
	r = m - 1;
    }
  
  return -1; //key wasn't found
}

/****************************************************************************                                                             
This function returns the index where key is found or -1 if key is not found.                                                             
a is an integer array of any size sorted in descending order.                                                                                                     
s is the size of the array.                                                                                                               
key is the number being searched for.                                                                                                     
****************************************************************************/

int binarySearchDescend(const int a[], int s, int key)
{
  int l = 0; //left boudary starts at first index                                                                                      
  int r = s - 1; //right boundary starts at last index                                                                                     
  int m; //middle point between left and right.                                                                                           

  //When l and r cross over, search ends. --> key was not found.                                                                          
  while(l <= r)
    {
      //calculate the middle point between l and r                                                                                        
      m = (l + r)/2;

      if(a[m] == key) //key was found                                                                                                       
        return m;
      else if(key > a[m])
        r = m - 1;
      else if(key < a[m])
        l = m + 1;
    }

  return -1; //key wasn't found                                                                                                      
}


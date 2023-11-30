/*****************************************************
Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name:Eric Coy
*****************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
template <class T>
void fill(T a[], int n){
  for(int i = 0; i < n; i++){
    cout << "Enter an item: ";
    cin >> a[i];
  }
}

/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
template <class T>
void print(T a[], int n){
  for(int i = 0; i < n; i++){
    cout << left << setprecision(1) << fixed << setw(4) << a[i]; 
  }
}




/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
template <class T>
int getHighest(T a[], int n){
  int h = 0;
  for(int i = 0; i < n; i++){
    if(a[i] > a[h]){
      h = i;
    }
  }
  cout << "The highest is " << a[h] << " at index " << h << endl;
  return h;
}


/*******************************************
This function returns the index of the lowest value.

ar is an array of any data type.
n is the number of items in array
********************************************/
template <class T>
int getLowest(T a[], int n){
  int l = 0;
  for(int i = 0; i < n; i++){
    if(a[i] < a[l]){
      l = i;
    }
  }
  cout << "The lowest is " << a[l] << " at index " << l << endl;
  return l;
}




/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
template <class T>
int getAvg(T ar[], int n){
  double total = 0;
  double avg = 0;
  for(int i = 0; i < n; i++){
    total = total + ar[i];
  }
  avg = total / n;
  cout << "The average is " << setprecision(5) <<  avg << endl;
  return(double) avg;
}



/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4  
       
ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar
*******************************************/
template <class T>
int unique(const T ar[], T uniqAr[] , int n)
{
  int uniqAr_SZ = 7;
  uniqAr[uniqAr_SZ];
//uniqAr in the caller will be filled with only unique numbers
  int 1st_index = 0;
  uniqAr[]
  

  return uniqAr_SZ;
}




/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                                

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order 
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <class T>
void sort(T array[], int N)
{
  int lrgIndx; //the index of the largest value                                                                                               
  T temp; //temporary variable that holds the largest value                                                                                  

  //last is the last index in unsorted portion                                                                                                 
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest                                                                                      
      //find the largest in unsorted portion ([0..last])                                                                                       
      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger                                                                           
            lrgIndx = i;
        }

      //swap the largest with the last item in the unsorted portion                                                                            
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}



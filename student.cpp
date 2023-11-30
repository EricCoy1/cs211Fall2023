#include<iostream>
#include "student.h"
#include "array.h"
using namespace std;

Student::Student(string FN, string LN, char G, int ID){
  firstName = FN;
  lastName = LN;
  gender = G;
  stuID = ID;
  numOfClasses = 0;
  balance;
}

Student::Student(){
  firstName = "unknown";
  lastName = "unknown";
  gender = 'x';
  stuID = -1;
  numOfClasses = 0;
  balance;
}

int Student::addCourse(int crn){
  if(numOfClasses == 0){
    classes[numOfClasses] = crn;
    numOfClasses++;
      return 1;
  }
  if(numOfClasses >= MAX){
    return -1;
  }
  if(numOfClasses > 0){
    int index = 0;
    index = find(classes, MAX, crn);
    if(index == -1){
      classes[numOfClasses] = crn;
      numOfClasses++;
      return 1;
    }
    if(classes[index] == crn){
      return 0;
    }
  }
  
}

void Student::viewAllCourses() const{
  if(numOfClasses == 0){
    cout << "empty\n";
  }
  for(int i = 0; i < numOfClasses; i++){
    cout << left << setprecision(1) << fixed << setw(4) << classes[i];
  }
}

bool Student::dropCourse(int crn){
  bool result = remove(classes, numOfClasses, crn);
  if(result == true){
    numOfClasses--;
  }
  return result;
}

string Student::getFirstName() const{
  return firstName;
}

string Student::getLastName() const{
  return lastName;
}

char Student::getGender() const{
  return gender;
}

int Student::getNumClasses() const{
  return numOfClasses;
}

int Student::getStuID() const{
  return stuID;
}

int Student::getClassOf(int i) const{
  return classes[i];
}

Price Student::getBalance() const{
  return balance;
}

void Student::addFee(int d, int c){
  Price p(d, c);
  balance = balance + p;
}

void Student::reduceFee(int d, int c){
  Price p(d, c);
  balance = balance - p;
}

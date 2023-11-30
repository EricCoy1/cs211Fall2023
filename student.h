#include <string>
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H
#include "price.h"
const int MAX = 6;

class Student{
 private:
  string firstName;
  string lastName;
  char gender;
  int stuID;
  int numOfClasses;
  int classes[MAX];
  Price balance;

 public:
  Student(string FN, string LN, char G, int ID);
  Student();
  int addCourse(int crn);
  void viewAllCourses() const;
  bool dropCourse(int crn);
  string getFirstName() const;
  string getLastName() const;
  char getGender() const;
  int getNumClasses() const;
  int getStuID() const;
  int getClassOf(int i) const;
  Price getBalance() const;
  void addFee(int d, int c);
  void reduceFee(int d, int c);
};
#endif

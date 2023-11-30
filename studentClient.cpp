#include <iostream>
using namespace std;
#include "student.h"

int main(){

  Student s1("Eric", "Coy", 'M');

  int returnvalue;
  returnvalue = s1.addCourse(100);
  cout << "hello " << returnvalue << endl;
  returnvalue = s1.addCourse(100);
  cout << "bye " << returnvalue << endl;
  s1.addCourse(200);
  s1.addCourse(300);
  s1.addCourse(400);
  s1.viewAllCourses();
  cout << endl;
  s1.dropCourse(100);
  s1.viewAllCourses();
  cout << endl;
  
  
  
  return 0;
}

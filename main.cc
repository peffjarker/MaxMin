//*******************************************************************
//
//  Program:  Program 1 Student Records
//
//  Author:  Prof. David Chelberg modified by Jeff Parker
//  Email: chelberg@ohio.edu, jp344916@ohio.edu
//  ID: P100846031
//
//  Course: CS4040
//
//  Description:  This file contains code to test a solution to this
//                homework problem.
//
//                This file is provided for your benefit.  It
//                illustrates a potential implementation of a main
//                program that tests your algorithm for this problem.
//
//                It also illustrates one way to compute the time your
//                program takes to complete its task in real-world
//                seconds, which can be used to compare two potential
//                implementations to see which one might be faster.
//
// Originally written for CS4040/5040
//
// last-modified: Mon Oct 28 11:07:32 2019
//
//*******************************************************************

// NOTE: The code in this file does NOT conform completely to the
// style guidelines for this class, so would not get full points if
// submitted as is.

#include <vector>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#include "student.h"
#include "FindMaxMin.h"
using std::vector;
using std::cout;
using std::endl;

//******************************************************************
//
//  Function: timeval2sec
//
//  Purpose:  Computes number of seconds from timeval in microseconds
//
//  Parameters:  const timeval& T
//
//  Calls: None
//
//  Time complexity: O(c)
//
//  Space complexity: O(1+4)
//
//******************************************************************
double timeval2sec(const timeval& T) {
  // Constant for time unit conversion
  const double USEC_TO_SEC = 1000000.0;

  return ((double) T.tv_sec + (double) (T.tv_usec / USEC_TO_SEC));
}

//******************************************************************
//
//  Function: operator <<
//
//  Purpose:  Computes time of day in seconds
//
//  Parameters: None
//
//  Calls: function gettimeofday(&T, NULL)
//
//  Time complexity: O(c)
//
//  Space complexity: O(1)
//
//******************************************************************
double timeofday() {
  timeval T;
  gettimeofday(&T, NULL);
  return (timeval2sec(T));
}
//******************************************************************
//
//  Function: generateName
//
//  Purpose:  Creates a random string from size 2-9 for generating
//            a test set
//
//  Calls: None
//
//  Time complexity: O(c*k)
//
//  Space complexity: O(1+k+4+1)
//
//******************************************************************
string generateName() {
  int numberOfDigtsInFirstName = rand() % 7 + 2;
  string first_name = "";
  char digit;
  for (int i = 0; i < numberOfDigtsInFirstName; ++i) {
    digit = rand() % 26 + 97;
    first_name += digit;
  }
  return first_name;
}

//******************************************************************
//
//  Function: generateStudents
//
//  Purpose:  Generates num elements
//
//  Parameters:  size_t num
//
//  Calls: function gettimeofday(&T, NULL), function srand48(T.tv_usec)
//          function to_string(i), function generateName
//
//  Time complexity: O(n)
//
//  Space complexity: O(1+C)
//
//******************************************************************
vector<Student> generateStudents(size_t num)
{
  timeval T;
  gettimeofday(&T, NULL);
  // Sets the random number seed to the number of microseconds in the
  // current time.
  srand48(T.tv_usec);
  vector <Student> testing;
  for (size_t i = 0; i<num; ++i) {
    Student a;
    a.SSN=std::to_string(i);
    a.gpa=drand48();
    a.first_name=generateName();
    a.last_name=generateName();
    a.major=generateName();
    testing.push_back(a);
  }
  return(testing);
}

// Sample Main, needs more comments.
int main ()
{
  vector<Student> Students;
  const size_t NUM_STUDENTS=11;
  double start=timeofday();
  srand(time(NULL));
  Students = generateStudents(NUM_STUDENTS);


  Compare::clear();
  size_t min1 = 0; // initializes min1
  size_t min2 = 0; // initializes min2
  size_t max1 = 0; // initiailizes max1
  size_t max2 = 0; // initializes max2
  FindMaxMin(Students, max1, max2, min1, min2);

  cout << "FindMaxMin took " << timeofday() - start << " seconds"
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "FindMaxMin took " << Compare::get_count() << " comparisons"
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "Min1 at " << min1<<" min2 at " << min2 << " max1 at " << max1 << " max2 at " << max2 << endl;
  cout << "Min1\n" << Students[min1] << endl;
  cout << "Min2\n" << Students[min2] << endl;
  cout << "Max1\n" << Students[max1] << endl;
  cout << "Max2\n" << Students[max2] << endl;

  // Now test second function.
  start=timeofday();

  CompareGPA::clear();
  FindMaxMinGPA(Students, max1, max2, min1, min2);

  cout << "FindMaxMinGPA took " << timeofday() - start << " seconds"
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "FindMaxMinGPA took " << CompareGPA::get_count() << " comparisons"
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "Min1 at " << min1<<" min2 at " << min2 << " max1 at " << max1 << " max2 at " << max2 << endl;
  cout << "Min1\n" << Students[min1] << endl;
  cout << "Min2\n" << Students[min2] << endl;
  cout << "Max1\n" << Students[max1] << endl;
  cout << "Max2\n" << Students[max2] << endl;

  return(EXIT_SUCCESS);
}

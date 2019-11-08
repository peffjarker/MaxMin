//*******************************************************************
//
//  Program:      Program 1 - Find Max, Max2, Min & Min2 in O(3/2n)
//
//  Author:       Jeff Parker
//  Email:        jp34416@ohio.edu
//  ID:           PXXXXXXXXX
//
//  Course:       CS4040
//
//  Description:  This file contains the code to find the max and min
//                items in a vector of students. As well as the second
//                max and second min.
//
//  Date:         11/10/2019
//
//*******************************************************************
#include "FindMaxMin.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//******************************************************************
//
//  Function:     FindMaxMin
//
//  Purpose:      Finds the max, second max, min, and second min of students
//                based off of ordering in compare class functions.
//
//  Parameters:   const vector<Student> &students, size_t &max, size_t &max2,
//                size_t &min, size_t &min2
//
//  Calls:        function Compare::lt, function Compare::get_count,
//                functiondistance, vector.begin, vector.end
//
//  Time Complex: ~=O(3n/2)
//
//  Space Complex:O(1+16)
//
//******************************************************************
void FindMaxMin(const vector<Student> &students,
                size_t &max, size_t &max2,
                size_t &min, size_t &min2)
{
  // INITIALIZATION OF VARIABLES
  max = students.size()+1; // initializes max to be recognized as unset
  max2 = students.size()+1; // initializes max2 to be recognized as unset
  min = students.size()+1; // initializes min to be recognized as unset
  min2 = students.size()+1; // initializes min2 to be recognized as unset
  auto it = students.begin(); // creates iterator to traverse vector
  auto it2 = students.begin()+1; // creates iterator next to iterator it
  // FIND MAX MIN MAX2 MIN2
  for (it = students.begin(); it != students.end(); it = it+2) {
    // for case which input size is odd we need to check if we're accessing
    // data out of bounds
    if (it > students.end()) {
      return;
    }
    if (it == students.end()-1) {
      if (!(Compare::lt(*it, students[min2]))) {
        if (!(Compare::lt(*it, students[min]))) {
          min2 =  min;
          min = distance(students.begin(), it);
        } else {
          min2 = distance(students.begin(), it);
        }
      } else if (Compare::lt(*it, students[max2])) {
        if (Compare::lt(*it, students[max])) {
          max2 = max;
          max = distance(students.begin(), it);
        } else {
          max2 = distance(students.begin(), it);
        }
      }
      return;
    } else {
      it2 = it + 1;
      if (Compare::lt(*it2, *it)) {
        if (!(Compare::lt(*it, students[min2])) ||  min2 == students.size()+1) {
          if (!(Compare::lt(*it, students[min])) ||  min == students.size()+1) {
            if (Compare::get_count() == 1) {
               min = distance(students.begin(), it);
            } else {
               min2 =  min;
               min = distance(students.begin(), it);
            }
          } else {
            min2 = distance(students.begin(), it);
          }
        }
        if (Compare::lt(*it2, students[max2]) ||  max2 == students.size()+1) {
          if (Compare::lt(*it2, students[max]) ||  max == students.size()+1) {
            if (Compare::get_count() == 1) {
               max = distance(students.begin(), it2);
            } else {
               max2 =  max;
               max = distance(students.begin(), it2);
            }
          } else {
            max2 = distance(students.begin(), it2);
          }
        }
      } else {
        if (Compare::lt(*it, students[max2]) || max2 == students.size()+1) {
          if (Compare::lt(*it, students[max]) || max == students.size()+1) {
            if (Compare::get_count() == 1) {
              max = distance(students.begin(), it);
            } else {
              max2 = max;
              max = distance(students.begin(), it);
            }
          } else {
            max2 = distance(students.begin(), it);
          }
        }
        if (!(Compare::lt(*it2, students[min2])) || min2 == students.size()+1) {
          if (!(Compare::lt(*it2, students[min])) || min == students.size()+1) {
            if (Compare::get_count() == 1) {
              min = distance(students.begin(), it2);
            } else {
              min2 = min;
              min = distance(students.begin(), it2);
            }
          } else {
            min2 = distance(students.begin(), it2);
          }
        }
      }
    }
  }
  if (Compare::lt(students[min2], students[max2])) {
    int tmp = min2;
    min2 = max2;
    max2 = tmp;
  }
}

//******************************************************************
//
//  Function:     FindMaxMinGPA
//
//  Purpose:      Finds the max, second max, min, and second min of students
//                based off of ordering in compare class functions.
//
//  Parameters:   const vector<Student> &students, size_t &max, size_t &max2,
//                size_t &min, size_t &min2
//
//  Calls:        function Compare::lt, function Compare::get_count,
//                functiondistance, vector.begin, vector.end
//
//  Time Complex: =~O(3n/2)
//
//  Space Complex:O(1+16)
//
//******************************************************************
void FindMaxMinGPA(const vector<Student> &students,
		   size_t &max, size_t &max2,
		   size_t &min, size_t &min2)
{


  // INITIALIZATION OF VARIABLES

  max = students.size()+1; // initializes max to be recognized as unset
  max2 = students.size()+1; // initializes max2 to be recognized as unset
  min = students.size()+1; // initializes min to be recognized as unset
  min2 = students.size()+1; // initializes min2 to be recognized as unset
  auto it = students.begin(); // creates iterator to traverse vector
  auto it2 = students.begin()+1; // creates iterator next to iterator it
  // FIND MAX, MAX2, MIN, MIN2
  for (it = students.begin(); it != students.end(); it = it+2) {
    // for case which input size is odd we need to check if we're accessing
    // data out of bounds
    if (it > students.end()) {
      return;
    }
    if (it == students.end()-1) {
      if (!(CompareGPA::lt(*it, students[max2]))) {
        if (!(CompareGPA::lt(*it, students[max]))) {
          max2 = max;
          max = distance(students.begin(), it);
        } else {
          max2 = distance(students.begin(), it);
        }
      } else if (CompareGPA::lt(*it, students[min2])) {
        if (CompareGPA::lt(*it, students[min])) {
          min2 = min;
          min = distance(students.begin(), it);
        } else {
          min2 = distance(students.begin(), it);
        }
      }
    } else {
      it2 = it + 1;
      if (CompareGPA::lt(*it2, *it)) {
        if (!(CompareGPA::lt(*it, students[max2])) || max2 == students.size()+1) {
          if (!(CompareGPA::lt(*it, students[max])) || max == students.size()+1) {
            if (CompareGPA::get_count() == 1) {
              max = distance(students.begin(), it);
            } else {
              max2 = max;
              max = distance(students.begin(), it);
            }
          } else {
            max2 = distance(students.begin(), it);
          }
        }
        if (CompareGPA::lt(*it2, students[min2]) || min2 == students.size()+1) {
            if (CompareGPA::lt(*it2, students[min]) || min == students.size()+1) {
              if (CompareGPA::get_count() == 1) {
                min = distance(students.begin(), it2);
              } else {
                min2 = min;
                min = distance(students.begin(), it2);
              }
          } else {
            min2 = distance(students.begin(), it2);
          }
        }
      } else {
        if (CompareGPA::lt(*it, students[min2]) || min2 == students.size()+1) {
          if (CompareGPA::lt(*it, students[min]) || min == students.size()+1) {
            if (CompareGPA::get_count() == 1) {
              min = distance(students.begin(), it);
            } else {
              min2 = min;
              min = distance(students.begin(), it);
            }
          } else {
            min2 = distance(students.begin(), it);
          }
        }
        if (!(CompareGPA::lt(*it2, students[max2])) || max2 == students.size()+1) {
          if (!(CompareGPA::lt(*it2, students[max])) || max == students.size()+1) {
            if (CompareGPA::get_count() == 1) {
              max = distance(students.begin(), it2);
            } else {
              max2 = max;
              max = distance(students.begin(), it2);
            }
          } else {
            max2 = distance(students.begin(), it2);
          }
        }
      }
    }
  }
  if (CompareGPA::lt(students[max2], students[min2])) {
    int tmp = min2;
    min2 = max2;
    max2 = tmp;
  }
}

//*******************************************************************
//
//  Program:  Program 1 Student Records FindMaxMin
//
//  Author:  Prof. David Chelberg
//  Email: chelberg@ohio.edu
//  ID: PXXXXXXXXX
//
//  Course: CS4040
//
//  Description:  This file contains the Class definition for records used in FindMaxMin code.
//
// Originally written for CS4040/5040
//
// last-modified: Mon Oct 28 10:48:46 2019
//
//*******************************************************************
//
// NOTE YOU MAY NOT MODIFY THIS FILE IN ANY WAY FOR THIS ASSIGNMENT!
#include "student.h"

int Compare::count=0;
int CompareGPA::count=0;

// Comparison operators.
//
// You must use the following comparison operators for all your comparisons.
// What are their runtime and space?
//
// Be sure to add to the comments section the analysis of the runtime
// and space use of all functions!
//

//******************************************************************
//
//  Function: Compare::lt
//
//  Purpose: to determine if the first student record is less than
//           the second by name, then SSN to break ties.
//
//  Parameters:   const Student &a   Holds the data for the first student
//                const Student &b   Holds the data for the second student
//
//  Calls:  nothing
//
//  Time complexity:  O(c)
//
//  Space complexity:  O(1)
//
//******************************************************************
bool Compare::lt (const Student &a, const Student &b)
{
  count++;  // Keep track of how many comparisons are done!
  if (a.last_name < b.last_name) {
    return(true);
  }else if (a.last_name > b.last_name) {
    return(false);
  } else if (a.first_name < b.first_name)  {
    return(true);
  } else if (a.first_name > b.first_name) {
    return(false);
  } else {
    return((a.SSN < b.SSN));
  }
}

//******************************************************************
//
//  Function: Compare::eq
//
//  Purpose:  to determine if two student records are equal
//
//
//  Parameters:   const Student &a   Holds the data for the first student
//                const Student &b   Holds the data for the second student
//
//
//  Calls:  nothing
//
//  Time complexity:   O(c)
//
//  Space complexity: O(1)
//
//******************************************************************
bool Compare::eq (const Student &a, const Student &b)
{
  Compare::count++;  // Keep track of how many comparisons are done!
  if (a.last_name != b.last_name) {
    return(false);
  } else if (a.first_name != b.first_name)  {
    return(false);
  } else if (a.SSN != b.SSN) {
    return(false);
  } else if (a.major != b.major){
    return(false);
  } else if (a.gpa != b.gpa) {
    return(false);
  } else {
    return (true);
  }
}

//******************************************************************
//
//  Function: CompareGPA::lt
//
//  Purpose: to determine if the first student record is less than
//           the second by GPA, then name, then SSN to break ties.
//
//
//  Parameters:   const Student &a   Holds the data for the first student
//                const Student &b   Holds the data for the second student
//
//
//  Calls:  nothing
//
//  Time complexity:   O(c)
//
//  Space complexity:  O(1)
//
//******************************************************************
bool CompareGPA::lt (const Student &a, const Student &b)
{
  count++;  // Keep track of how many comparisons are done!
  if (a.gpa < b.gpa) {
    return(true);
  } else if (a.gpa >b.gpa) {
    return(false);
  } else if (a.last_name < b.last_name) {
    return(true);
  } else if (a.last_name > b.last_name) {
    return(false);
  } else if (a.first_name < b.first_name)  {
    return(true);
  } else if (a.first_name > b.first_name) {
    return(false);
  } else {
    return((a.SSN < b.SSN));
  }
}

// Output operator
// What is the runtime/space of this operator?
//
//******************************************************************
//
//  Function: operator <<
//
//  Purpose:  To output a student record
//
//  Parameters:  ostream &out
//               const Student &aStudent
//
//  Calls: None
//
//  Time complexity: O(c)
//
//  Space complexity: O(1)
//
//******************************************************************
ostream& operator << (ostream &out, const Student &aStudent)
{
  out << "SSN: "<< aStudent.SSN << endl;
  out << "First: " << aStudent.first_name << endl;
  out << "Last: " << aStudent.last_name << endl;
  out << "Major: " << aStudent.major << endl;
  out << "GPA: " << aStudent.gpa << endl;
  return(out);
}

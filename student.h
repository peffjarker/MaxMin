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
// last-modified: Mon Oct 28 10:48:21 2019
//
//*******************************************************************
//
// NOTE YOU MAY NOT MODIFY THIS FILE IN ANY WAY FOR THIS ASSIGNMENT!
#ifndef student_h
#define student_h
#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::ostream;

class Student {
  public:
  string SSN;
  string first_name;
  string last_name;
  string major;
  float  gpa;
};

class Compare {
public:
  static bool lt (const Student &a, const Student &b);
  static bool eq (const Student &a, const Student &b);

  // Setter (clear the count of number of comparisons between runs)
  static void clear(){
    count=0;
  }

  // Getter
  static int get_count(){
    return(count);
  }
private:
  static int count;
};

class CompareGPA :public Compare{
public:
  static bool lt (const Student &a, const Student &b);

  // Setter (clear the count of number of comparisons between runs)
  static void clear(){
    count=0;
  }
  // Getter
  static int get_count(){
    return(count);
  }
private:
  static int count;
};

extern ostream& operator << (ostream &out, const Student &aStudent);

#endif

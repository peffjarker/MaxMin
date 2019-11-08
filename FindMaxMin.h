//*******************************************************************
//
//  Program:  Program 1 Student Records FindMaxMin.h
//
//  Author:  Prof. David Chelberg
//  Email: chelberg@ohio.edu
//  ID: PXXXXXXXXX
//
//  Course: CS4040
//
//  Description: This file contains the header code for finding the
//               max and min items in a vector of students. As well as
//               the second max and second min.
//
// Originally written for CS4040/5040
//
// last-modified: Mon Oct 28 11:23:04 2019
//
//*******************************************************************
//
#ifndef FindMaxMin_h
#define FindMaxMin_h

#include "student.h"
#include <vector>
using std::vector;

//******************************************************************
//
//  Function: FindMaxMin
//
//  Purpose:
//
//
//  Parameters:
//
//
//  Calls:
//
//  Time complexity:
//
//  Space complexity:
//
//******************************************************************
void FindMaxMin(const vector<Student> &students,
                size_t &max, size_t &max2,
                size_t &min, size_t &min2);

//******************************************************************
//
//  Function: FindMaxMinGPA
//
//  Purpose:
//
//
//  Parameters:
//
//
//  Calls:
//
//  Time complexity:
//
//  Space complexity:
//
//******************************************************************
void FindMaxMinGPA(const vector<Student> &students,
		   size_t &max, size_t &max2,
		   size_t &min, size_t &min2);
#endif

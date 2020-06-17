/*
CIS 22B Project Final

report.cpp module containing functions to report inventory listings with sorted information
These functions accept a single Book object array parameter and outputs the data to console
When the user selects the each choice in bookmain.cpp, the respective function will be called

Name: Guy Rosenberg
*/ 

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//report.cpp declarations
void list_Info(Book b[]);
void list_wValue(Book b[]);
void list_rValue(Book b[]);
void list_Quantity(Book b[]);
void list_Cost(Book b[]);
void list_Age(Book b[]);


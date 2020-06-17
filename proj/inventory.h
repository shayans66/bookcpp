/*
 CIS 22B Project Final

 inventory.cpp module containing functions to look up, add, edit, and delete books and their attributes
 These functions accept a single Book object array parameter and outputs the data to console
 When the user selects the each choice in bookmain.cpp, the respective function will be called

 Name: Elroy Lobo
 */

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "book.h""

using namespace std;

//inventory.cpp declarations
int Lookup_Book(Book b[], string title);
void Add_Book(Book b[], int index);
void Edit_Book(Book b[]);
void Delete_Book(Book b[], string book);

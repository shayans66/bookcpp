/*
CIS 22B Project Final

report.cpp module containing functions to report inventory listings with sorted information
These functions accept a single Book object array parameter and outputs the data to console
When the user selects the each choice in bookmain.cpp, the respective function will be called

Name: Guy Rosenberg
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include "book.h"
#include "report.h"

using namespace std;

// Simple swap function to move Book objects in array
void swap(Book& a, Book& b) {
    Book temp;
    temp = a;
    a = b;
    b = temp;
}
// Function that uses a selection sort to put the Book object array in ascending order by Quantity
void sortByQuantity(Book b[], int size)
{
    int i, j, min_index;
    // outer loop iterating through each index
    for (i = 0; i < size - 1; i++) {
        min_index = i; // set min_index to i after each iteration of loop
        // inner loop iterating through initial index + 1
        for (j = i + 1; j < size; j++) {
            if (b[j].GetQuantity() < b[min_index].GetQuantity())
                min_index = j;
            // Swaps next smallest element with element at index i
            swap(b[i], b[min_index]);
        }
    }
}
// Function that uses a selection sort to put the Book object array in ascending order by Cost
void sortByCost(Book b[], int size)
{
    int i, j, min_index;
    // outer loop iterating through each index
    for (i = 0; i < size - 1; i++) {
        min_index = i; // set min_index to i after each iteration of loop
        // inner loop iterating through initial index + 1
        for (j = i + 1; j < size; j++) {
            if (b[j].GetCost() < b[min_index].GetCost())
                min_index = j;
            // Swaps next smallest element with element at index i
            swap(b[i], b[min_index]);
        }
    }
}
// Function that uses a selection sort to put the Book object array in ascending order by Age
void sortByAge(Book b[], int size)
{
    int i, j, min_index;
    // outer loop iterating through each index
    for (i = 0; i < size - 1; i++) {
        min_index = i; // set min_index to i after each iteration of loop
        // inner loop iterating through initial index + 1
        for (j = i + 1; j < size; j++) {
            if (stoi(b[j].GetDate()) < stoi(b[min_index].GetDate()))
                min_index = j;
            // Swaps next smallest element with element at index i
            swap(b[i], b[min_index]);
        }
    }
}

// Inventory Information Listing
// outputs to console
void list_Info(Book b[]) {
    for (int i = 0; i < 50; i++) {
        cout << b[i].GetTitle() << " " << b[i].GetAuthor() << " " << b[i].GetPublisher() << " " << b[i].GetIsbn() << endl;
    }
}
// Inventory Wholesale Value Listing
// outputs to console
void list_wValue(Book b[]) {
    double wTotal = 0;
    for (int i = 0; i < 50; i++) {
        cout << b[i].GetTitle() << ": " << b[i].GetCost() << endl;
        wTotal += b[i].GetCost();
    }
    cout << wTotal << endl;
}
// Inventory Retail Value Listing
// outputs to console
void list_rValue(Book b[]) {
    double rTotal = 0;
    for (int i = 0; i < 50; i++) {
        cout << b[i].GetTitle() << ": " << b[i].GetPrice() << endl;
        rTotal += b[i].GetPrice();
    }
    cout << rTotal << endl;
}
// Sorts and Lists by Quantity (higher first)
// outputs array in reverse (sorted in ascending)
void list_Quantity(Book b[]) {
    sortByQuantity(b, 50);
    for (int i = 50; i > 0; i--) {
        cout << b[i].GetTitle() << ": " << b[i].GetQuantity() << endl;
    }
}
// Sorts and Lists by Cost (higher first)
// outputs array in reverse (sorted in ascending)
void list_Cost(Book b[]) {
    sortByCost(b, 50);
    for (int i = 50; i > 0; i--) {
        cout << b[i].GetTitle() << ": " << b[i].GetCost() << endl;
    }
}
// Sorts and Lists by Age (oldest first/earlier date)
// outputs array
void list_Age(Book b[]) {
    sortByAge(b, 50);
    for (int i = 0; i < 50; i++) {
        cout << b[i].GetTitle() << ": " << b[i].GetDate() << endl;
    }
}

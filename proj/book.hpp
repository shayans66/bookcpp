/*
 Names:            Elroy Lobo and Cecily Flores
 Lab:            5 - Operator overloading in classes
 File name:        book.h
 Purpose:        The header file that declares and initializes the classes and variables
 */

#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Book
{
public:
    //Declare constructors
    Book();
    
    //Constructor to initialize 2 arbitrary attributes
    Book(string title, string publisher);
    
    //Constructor to initialize all attributes
    Book(string isbn, string title, string author,
         string publisher, string date, int quant, double cost,
         double price);
    
    //Destructor
    ~Book();
    
    // 1 Getters and setters Isbn
    inline string GetIsbn() const {
        return isbn;
    }
    inline void SetIsbn(string nIsbn) {
        this->isbn = nIsbn;
    }
    
    // 2 Getters and setters title
    inline string GetTitle() const {
        return title;
    }
    inline void SetTitle(string nTitle) {
        this->title = nTitle;
    }
    // 3 Getters and setters author
    inline string GetAuthor() const {
        return author;
    }
    inline void SetAuthor(string nAuthor) {
        this->author = nAuthor;
    }
    // 4 Getters and setters publisher
    inline string GetPublisher() const {
        return publisher;
    }
    inline void SetPublisher(string nPublisher) {
        this->publisher = nPublisher;
    }
    // 5 Getters and setters date
    inline string GetDate() const {
        return date;
    }
    inline void SetDate(string date) {
        this->date = date;
    }
    // 6 Getters and setters quantity
    inline int GetQuantity() const {
        return quantity;
    }
    inline void SetQuantity(int quantity) {
        this->quantity = quantity;
    }
    // 7 Getters and setters cost
    inline double GetCost() const {
        return cost;
    }
    inline void SetCost(double cost) {
        this->cost = cost;
    }
    // 8 Getters and setters price
    inline double GetPrice() const {
        return price;
    }
    inline void SetPrice(double price) {
        this->price = price;
    }
    
    //Operators overloads
    void operator= (const Book& other);
    //Notice the size of some isbn (without dash) is 13 digits therefore cannot be just 'int' but 'long long int'
    operator long long int();
    bool operator==(const Book& other);
    
    //Friends operators
    friend istream& operator>>(istream& input, Book& b);
    friend ostream& operator<<(ostream& output, Book& b);
    
private:
    string isbn;
    string title;
    string author;
    string publisher;
    string date;    //Date as string because all it will do is display
    int quantity;
    double cost;
    double price;
    
};

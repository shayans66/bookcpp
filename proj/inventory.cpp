/*
 CIS 22B Project Final

 inventory.cpp module containing functions to look up, add, edit, and delete books and their attributes
 These functions accept a single Book object array parameter and outputs the data to console
 When the user selects the each choice in bookmain.cpp, the respective function will be called

 Name: Elroy Lobo
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <string>	//string to int, stoi
#include <stdlib.h>	//string to double, atof
#include <iomanip>  //formats the output
#include "book.h"
#include "report.h"

using namespace std;


int Lookup_Book(Book b[], string title)
{
    //	std::cout << "Please enter the Book Title" << endl;
    //	string bookTitle;
    //
    //	cin.ignore();
    //	getline(cin, bookTitle);
    int flag = -1;
    for (int i = 0; i < 50; i++)
    {
        Book tempBook = b[i];	//Get book
        string Booktitle = tempBook.GetTitle();

        Booktitle = Booktitle.erase(Booktitle.size() - 1);
        //cout<<"The length is "<<title.length() << " ------"<<Booktitle.length()<<"\n";
        if (title == Booktitle)
        {
            flag = i;
            cout << endl;
            cout << "Found the Book" << endl;
            std::cout << "Title: " << tempBook.GetTitle() << endl;
            std::cout << "Author: " << tempBook.GetAuthor() << endl;
            std::cout << "ISBN: " << tempBook.GetIsbn() << endl;
            std::cout << "Publisher: " << tempBook.GetPublisher() << endl;
            std::cout << "Date: " << tempBook.GetDate() << endl;
            std::cout << "Quantity: " << tempBook.GetQuantity() << endl;
            std::cout << "Cost: $" << setprecision(2) << fixed << tempBook.GetCost() << endl;
            std::cout << "Price: $" << setprecision(2) << fixed << tempBook.GetPrice() << endl;
            std::cout << endl;
            break;
        }
    }
    if (flag == -1)
    {
        cout << "Book Not found" << endl;
    }
    return flag;
}


void Add_Book(Book b[], int index)
{
    string title, author, ISBN, publisher, date, squantity, scost, sprice, garbage;
    float cost, price;
    int quantity = 0;
    cout << "Enter the title of the book";

    std::getline(std::cin, title);

    std::cout << "Enter the author: ";
    std::getline(std::cin, author);

    std::cout << "Enter the ISBN: ";
    std::getline(std::cin, ISBN);

    std::cout << "Enter the publisher: ";
    std::getline(std::cin, publisher);

    std::cout << "Enter the date: ";
    std::getline(std::cin, date);


    std::cout << "Enter the quantity: ";
    std::getline(std::cin, squantity);

    quantity = atoi(squantity.c_str());

    std::cout << "Enter the cost: ";
    std::getline(std::cin, scost);

    scost.erase(0, 1);
    cost = atof(scost.c_str());	//c_str converts string to c-like string, char array

    std::cout << "Enter the price: ";
    std::getline(std::cin, sprice);

    sprice.erase(0, 1);
    price = atof(sprice.c_str());	//c_str converts string to c-like string, char array

    std::cout << "Enter the garbage: ";
    std::getline(std::cin, garbage);

    Book tempBook(ISBN, title, author, publisher, date, quantity, cost, price);

    b[index++] = tempBook;

}



void Delete_Book(Book b[], string book)
{
    int index = Lookup_Book(b, book);
    if (index == -1) {
        cout << "Book is not present";
    }
    else {

        for (int i = index; i < 50; i++) {
            b[i] = b[i + 1];
        }
    }
}


void Edit_Book(Book b[])
{
    string name;
    cout << "Enter the title name for the book you want to edit";
    getline(cin, name);
    int index;
    if ((index = Lookup_Book(b, name)) == 0) {  // book is found
        int choice;
        cout << "What option you want to change:\n 1: title 2: author 3: ISBN 4: Cost 5:quantity 6:Date 7 Publisher 8: price";
        cin >> choice;

        switch (choice) {
        case 1: {
            string title;
            cout << "Enter the new title";
            getline(cin, title);
            b[index].SetTitle(title);
            break;
        }
        case 2: {
            string author;
            cout << "Enter the new author name";
            getline(cin, author);
            b[index].SetAuthor(author);
            break;
        }
        case 3: {
            string ISBN;
            cout << "Enter the new ISBN";
            getline(cin, ISBN);
            b[index].SetIsbn(ISBN);
            break;
        }
        case 4: {
            float cost;
            string scost;
            std::cout << "Enter the cost: ";
            std::getline(std::cin, scost);
            scost.erase(0, 1);
            cost = atof(scost.c_str());
            b[index].SetCost(cost);
            break;
        }
        case 5: {
            int quantity;
            string squantity;
            std::cout << "Enter the quantity: ";
            std::getline(std::cin, squantity);

            quantity = atoi(squantity.c_str());
            b[index].SetQuantity(quantity);
            break;
        }

        case 6: {

            string date;
            std::cout << "Enter the date added: ";
            getline(cin, date);
            b[index].SetDate(date);
            break;

        }
        case 7: {


            string publisher;
            std::cout << "Enter the publisher name: ";
            getline(cin, publisher);
            b[index].SetPublisher(publisher);
            break;
            break;
        }
        case 8: {
            string sprice;
            float price;
            std::cout << "Enter the price: $";
            std::getline(std::cin, sprice);
            price = stoi(sprice.c_str());
            b[index].SetPrice(price);
            break;
        }
        default:
            break;
        }

    }
    else {
        cout << "the book you want is not present ";
    }

}

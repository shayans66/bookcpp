#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>	//Read data
#include <string>	//string to int, stoi
#include <stdlib.h>	//string to double, atof
#include <iomanip>  //formats the output
#include <ctime>
#include "book.h"	//Include the book header
#include "report.h" //Includes the report header

using namespace std;

int main() {
	string dataFile = "bookdata.txt"; //place path to data file
	string rowData;	//String to read if row/line in text

	//Declare a single variable per each of the data to parse
	string isbn = "";	//Naming this data the same as in the
	string title = "";	//class attributes makes them more readable
	string author = "";
	string publisher = "";
	string date = "";
	int quantity = 0;
	double cost = 0;
	double price = 0;

	int i = 0;	//Index per each of the row / lines read
	int total = 8;
	int index = 0;	//Index per each element in array

	Book allBooks[50];//Array to store 10 books

	cout << "===================================================" << endl;
	cout << "		Serendipity Booksellers				" << endl;
	cout << "			   Main Menu					" << endl;
	cout << "===================================================" << endl;
	cout << "		1. Cashier Module" << endl;
	cout << "		2. Inventory Database Module " << endl;
	cout << "		3. Report Module " << endl;
	cout << "		4. Exit " << endl << endl;
	cout << "		Enter Your Choice:" << endl;

	ifstream fileHandler(dataFile);	//Create file handler
	if (fileHandler.is_open())
		while (fileHandler.good() && index < 5)     //while there is data
			fileHandler >> allBooks[index++]; //Use overload input stream (file handler is an input stream )

	int choice;
	cin >> choice;


	if (choice == 1)
	{
		std::cout << "Please enter the Book Title" << endl;
		string bookTitle;
		cin.ignore();
		getline(cin, bookTitle);
		std::cout << "===================================================" << endl;
		std::cout << "		Serendipity Booksellers		" << endl;
		std::cout << "===================================================" << endl;
		//std::cout << "Date:" << (timeStruct->tm_year) << '-' << (timeStruct->tm_mon) << '-' << (timeStruct->tm_mday) << std::endl;
		std::cout << "Date:" << endl;
		int flag;
		for (int i = 0; i < 50; i++)
		{
			flag = 1;
			Book tempBook = allBooks[i];	//Get book
			string title = tempBook.GetTitle();
			double tax = 0.05;
			if (title.compare(bookTitle) == 0)
			{
				int quantity;
				std::cout << "Enter Quantity" << endl;
				cin >> quantity;
				std::cout << "Quantity		ISBN		Title					Price		Total" << endl;
				std::cout << "-------------------------------------------------------------------" << endl;
				std::cout << quantity << "		" << tempBook.GetIsbn() << "		" << tempBook.GetTitle() << "		" << tempBook.GetPrice() << "		" << quantity * tempBook.GetPrice() << endl << endl;
				std::cout << "			Subtotal" << quantity * tempBook.GetPrice() << endl;
				double taxAmount = quantity * tempBook.GetPrice() * tax;
				std::cout << "			Tax		" << taxAmount << endl;
				std::cout << "			Total	" << quantity * tempBook.GetPrice() + taxAmount << endl;
				std::cout << "Thank You for Shopping with us at Serendipity";
				flag = 0;
				break;
			}


		}
		if (flag == 1)
		{
			cout << "No Book with that Title found" << endl;
		}

	}

	if (choice == 2)
	{
		std::cout << "===================================================" << endl;
		std::cout << "		Serendipity Booksellers				" << endl;
		std::cout << "			   Inventory Database					" << endl;
		std::cout << "===================================================" << endl;
		std::cout << "		1. Look Up a Book" << endl;
		std::cout << "	    2. Add a Book " << endl;
		std::cout << "		3. Edit a Book Record " << endl;
		std::cout << "		4. Delete a Book " << endl << endl;
		std::cout << "		4. Return to the Main Menu " << endl << endl;

		int choice;
		std::cout << "Enter your choice:" << endl;
		cin >> choice;
		if (choice == 1)
		{
			std::cout << "Please enter the Book Title" << endl;
			string bookTitle;
			cin.ignore();
			getline(cin, bookTitle);
			int flag;
			for (int i = 0; i < 50; i++)
			{
				flag = 1;
				Book tempBook = allBooks[i];	//Get book
				string title = tempBook.GetTitle();
				if (title.compare(bookTitle) == 0)
				{
					flag = 0;
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
				}
			}
			if (flag == 1)
			{
				cout << "Book Not found" << endl;
			}
		}
		if (choice == 2)
		{
			if (fileHandler.is_open())
			{
				for (int i = 5; i < 10; i++) {

					string squantity, scost, sprice, garbage;

					getline(fileHandler, title);
					getline(fileHandler, author);
					getline(fileHandler, isbn);
					getline(fileHandler, publisher);
					getline(fileHandler, date);
					getline(fileHandler, squantity);
					quantity = atoi(squantity.c_str());


					getline(fileHandler, scost);
					scost.erase(0, 1);
					cost = atof(scost.c_str());	//c_str converts string to c-like string, char array

					getline(fileHandler, sprice);
					sprice.erase(0, 1);
					price = atof(sprice.c_str());	//c_str converts string to c-like string, char array
					getline(fileHandler, garbage);
					//Create new book on last index 7
					Book tempBook(isbn, title, author, publisher, date, quantity, cost, price);
					//Add it to array starting in 5 and up to 10
					allBooks[index++] = tempBook;
				}
			}
		}
		if (choice == 3)
		{
			std::cout << "Oops" << endl;
		}
		if (choice == 4)
		{
			std::cout << "Please enter the Book Title to be deleted" << endl;
			string bookTitle;
			cin.ignore();
			getline(cin, bookTitle);
			for (int i = 0; i < 50; i++)
			{
				Book tempBook = allBooks[i];	//Get book
				string title = tempBook.GetTitle();
				if (title.compare(bookTitle) == 0)
					int foundIndex = i;
				break;
			}
			int j;
			for (j = i; j + 1 < 5; j++)
			{
				allBooks[j] = allBooks[j + 1];
			}
			index = j;
		}

	}

	if (choice == 3)
	{
		cout << "===================================================" << endl;
		cout << "		Serendipity Booksellers				" << endl;
		cout << "			   Reports					" << endl;
		cout << "===================================================" << endl;
		cout << "		1. Inventory Listing" << endl;
		cout << "	    2. Inventory Wholesale Value " << endl;
		cout << "		3. Inventory Retail Value " << endl;
		cout << "		4. Listing by Quantity " << endl;
		cout << "		5. Listing by cost " << endl;
		cout << "		6. Listing by Age" << endl << endl;
		cout << "		Enter Your Choice:" << endl;

		int choice;
		cin >> choice;
		// Inventory Listing
		if (choice == 1)
		{
			cout << "List of all Books identifying information (title,author,publisher,isbn)" << endl;
			list_Info(allBooks);
		}
		// Inventory Wholesale Value
		if (choice == 2)
		{
			cout << "List of all Books Wholesale Value:" << endl;
			list_wValue(allBooks);
		}
		// Inventory Retail Value
		if (choice == 3)
		{
			cout << "List of all Books Retail Value:" << endl;
			list_rValue(allBooks);
		}
		// Listing by Quantity
		if (choice == 4)
		{
			cout << "List of all Books by Quantity (High to Low):" << endl;
			list_Quantity(allBooks);
		}
		// Listing by Cost
		if (choice == 5)
		{
			cout << "List of all Books by Cost (High to Low):" << endl;
			list_Cost(allBooks);
		}
		// Listing by Age
		if (choice == 6)
		{
			cout << "List of all Books by Date (Older first):" << endl;
			list_Age(allBooks);
		}
	}

	if (choice == 4)
	{
		fileHandler.close();	//Always closes file
		return 0;
	}

	fileHandler.close();	//Always closes file
	return 0;
}

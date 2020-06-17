/*
Names:			Elroy Lobo and Cecily Flores
Lab:			5 - Operator overloading in classes
File name:		book.cpp

Includes:		book.h - the header file

Purpose:		Constructors, deconstructors, input/output operators, and 
					initialization for the other files used
*/


#include "book.h"

using namespace std;
//Default constructor with default values
Book::Book() {
	this->isbn = "";
	this->title = "";
	this->author = "";
	this->publisher = "";
	this->date = "";
	this->quantity = 0;
	this->cost = 0;
	this->price = 0;
}


Book::Book(string title, string publisher) 
{
	this->title = title;
	this->publisher = publisher;
	this->quantity = 0;
	this->cost = 0;
	this->price = 0;
}


//Use parameter values to initialize attributes
Book::Book(string isbn, string title, string author, string publisher, string date, int quant, double cost, double price)
{
	this->isbn = isbn;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
	this->date = date;
	this->quantity = quant;
	this->cost = cost;
	this->price = price;
}
// deconstructor
Book::~Book()
{

}

void Book::operator=(const Book& other)
{
	//Copy over all properties to this project
	this->isbn = other.isbn;
	this->title = other.title;
	this->author = other.author;
	this->publisher = other.publisher;
	this->date = other.date;
	this->quantity = other.quantity;
	this->cost = other.cost;
	this->price = other.price;

}

Book::operator long long int()
{
	string removeDash = this->isbn;	//Copy the isbn as string
	size_t foundPos = this->isbn.find("-");		//Try to find dash
	if (foundPos != string::npos)
		removeDash = removeDash.replace(foundPos, 1, "");		//Remove where the dash occurs
	long long isbnInt = stoll(removeDash);	//Convert to integer, once dash is removed

	return isbnInt;
}

// 
bool Book::operator==(const Book& other)
{
	//Compare all member data to make sure they match
	if (this->isbn == other.isbn &&
		this->title == other.title &&
		this->author == other.author &&
		this->publisher == other.publisher &&
		this->date == other.date &&
		this->quantity == other.quantity &&
		this->cost == other.cost &&
		this->price == other.price) {
		return true;
	}
	else
		return false;
}

// input stream operator
istream& operator>>(istream& input, Book& created) {

	//Declare a single variable per each of the data to parse
	string isbn = "";	//Naming this data the same as in the 
	string title = "";	//class attributes makes them more readable 
	string author = "";
	string publisher = "";
	string date = "";
	int quantity = 0;
	double cost = 0;
	double price = 0;

	string squantity, scost, sprice, garbage;
	string rowData;





	getline(input, title);
	getline(input, author);
	getline(input, isbn);
	getline(input, publisher);
	getline(input, date);
	getline(input, squantity);
	quantity = atoi(squantity.c_str());


	getline(input, scost);
	scost.erase(0, 1);
	cost = atof(scost.c_str());	//c_str converts string to c-like string, char array

	getline(input, sprice);
	sprice.erase(0, 1);
	price = atof(sprice.c_str());	//c_str converts string to c-like string, char array
	getline(input, garbage);
	//Create new book on last index 7
	Book tempBook(isbn, title, author, publisher, date, quantity, cost, price);

	created = tempBook;	//Uses member operator overload assignment

	return input;
}

//output stream operator
ostream& operator<<(ostream& output, Book& tempBook)
{
	output << "Title: " << tempBook.GetTitle() << endl;
	output << "Author: " << tempBook.GetAuthor() << endl;
	output << "ISBN: " << tempBook.GetIsbn() << endl;
	output << "Publisher: " << tempBook.GetPublisher() << endl;
	output << "Date: " << tempBook.GetDate() << endl;
	output << "Quantity: " << tempBook.GetQuantity() << endl;
	output << "Cost: $" << tempBook.GetCost() << endl;
	output << "Price: $" << tempBook.GetPrice() << endl;
	output << endl;
	return output;
}
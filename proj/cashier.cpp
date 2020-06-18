//
//  cashier.cpp
//  proj
//
//  Created by android on 6/17/20.
//  Copyright © 2020 android. All rights reserved.
//

#include "cashier.h"
#include "book.h"

#include "inventory.h"


double Cashier::calculateTax(double price, double tax){
    return tax * price;
}


void Cashier::purchaseBook(string bookTitle){
    
    Book *books = this-> allBooks;
    int index = Lookup_Book(books, bookTitle);
    
    if(index==-1){
        return;
    }
    Book tempBook = books[index];
    
    int quantity = 0;
    std::cout << "Enter Quantity" << endl;
    cin >> quantity;
    std::cout << "Quantity        ISBN        Title                    Price        Total" << endl;
    std::cout << "-------------------------------------------------------------------" << endl;
    std::cout << quantity << "        " << tempBook.GetIsbn() << "        " << tempBook.GetTitle() << "        " << tempBook.GetPrice() << "        " << quantity * tempBook.GetPrice() << endl << endl;
    std::cout << "            Subtotal" << quantity * tempBook.GetPrice() << endl;
    double taxAmount = quantity * calculateTax(tempBook.GetPrice(), .08);
    std::cout << "            Tax        " << taxAmount << endl;
    std::cout << "            Total    " << quantity * tempBook.GetPrice() + taxAmount << endl;
    std::cout << "Thank You for Shopping with us at Serendipity";
   
    
    int bookquantity = books[index].GetQuantity();
    books[index].SetQuantity(books[index].GetQuantity()-1);
    
    if(bookquantity==0){
        Delete_Book(books, bookTitle);
        
    }
    
    
}




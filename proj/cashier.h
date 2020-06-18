//
//  cashier.hpp
//  proj
//
//  Created by android on 6/17/20.
//  Copyright © 2020 android. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>

#include "book.h"


using namespace std;

class Cashier {
private:
    Book* allBooks;
public:
    Cashier(Book* books) {
        allBooks = books;
    }
    
    
    double calculateTax(double price, double tax);


    void purchaseBook(string bookTitle);
    
};




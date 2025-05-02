/*****************************************************************************
                  Workshop - #3 (Part - 2)>
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#include "Vendor.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace seneca {
    // Constructor: Initializes the Vendor object with default values
    Vendor::Vendor() : orders(nullptr), numOrders(0), 
        capacity(0), totalPrice(0.0) {}
    // Destructor: Responsible for cleaning up 
    // dynamically allocated memory to prevent memory leaks.
    Vendor::~Vendor() {
        delete[] orders; // Properly deallocate memory
    }
    // setEmpty: Resets the Vendor object to an empty state.
    void Vendor::setEmpty() {
        delete[] orders; // Deallocate existing orders
        orders = nullptr; // Nullify the pointer
        numOrders = 0;
        capacity = 0;
        totalPrice = 0.0;
    }
    // takeOrders: Interacts with the user to take ice cream orders.
// This function first displays a welcoming message and prompts the
//  user for the number of ice cream orders.
// It then ensures there is enough capacity to store the 
// new orders, resizing the dynamic array if necessary.
// For each order, it prompts the user to fill in the details 
// and then stores the order in the dynamic array.
    void Vendor::takeOrders() {
        std::cout << "Seneca Icecream shop\n"
            << "          @\n"
            << "        (' .)\n"
            << "       (*.`. )\n"
            << "        \\###/\n"
            << "         \\#/\n"
            << "          V\nHow many Icecreams?\n> ";
        int ordersCount;
        std::cin >> ordersCount;
        std::cin.ignore(256, '\n');
        // Check if there is enough capacity to 
        // store the new orders, resize if necessary.
        if (ordersCount + numOrders > capacity) {
            resize(ordersCount + numOrders);
        }
        // Loop through the number of orders, taking each order's details.
        for (int i = 0; i < ordersCount; ++i) {
            std::cout << "Order number " << (i + 1) << ":\n";
            Icecream order;
            order.getOrder(); // Populate order
            // Assign order and increment numOrders
            orders[numOrders++] = order; 
        }
    }
    // displayOrders: Prints a summary of 
    // all orders taken so far. It lists each order's details.
    void Vendor::displayOrders() const {
        std::cout << "\n********** Order Summary **********\n";
        double subTotal = 0.0;
        // Iterate through each order to display its details.
        for (int i = 0; i < numOrders; ++i) {
            std::cout << "Order No: " << (i + 1) << ":\n";
            orders[i].printOrder();
            // Adds space between orders but not before the summary
            subTotal += orders[i].getPrice(); 
            if (i < numOrders - 1) {
                // Adds space between orders but not before the summary
                std::cout << "\n"; 
            }
        
            
        }
        
        double tax = subTotal * taxRate;
        double total = subTotal + tax;

        std::cout << "-----------------------------------\n";
        displayPriceLine("Price:", subTotal);
        displayPriceLine("Tax:", tax);
        displayPriceLine("Total Price ($):", total);
    }
    // clearData: Resets the Vendor object to its default 
    // state by deallocating any dynamic memory and resetting member variables.
// This function is typically called to clean up resources
//  or reinitialize the object before taking new orders.
    void Vendor::clearData() {
        setEmpty(); // Reset and deallocate
    }
    // resize: Adjusts the size of the dynamic array 
    // that stores orders to accommodate more orders.
// This method is necessary when the current capacity
//  is not sufficient to hold additional orders.
    void Vendor::resize(int newSize) {
        if (newSize <= capacity) {
            // newSize must be greater than the 
            // current capacity to justify a resize.
            return;
        }
        Icecream* newOrders = new Icecream[newSize];
        for (int i = 0; i < numOrders; ++i) {
            newOrders[i] = orders[i];
        }
        delete[] orders;
        orders = newOrders;
        capacity = newSize;
    }
    // displayPriceLine: Formats and displays a line item of the
    //  price summary, including a label and an amount.
// This function is used to maintain consistent
//  formatting for displaying prices in the order summary.
    void Vendor::displayPriceLine(const char* label, double amount) const {
        std::cout << label;
        std::cout.width(35 - std::strlen(label));
        std::cout.setf(std::ios::right);
        std::cout << std::fixed << std::setprecision(2) << amount << "\n";
        std::cout.unsetf(std::ios::right);
    }

} // namespace seneca

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
#ifndef VENDOR_H
#define VENDOR_H

#include "Icecream.h"

namespace seneca {

    class Vendor {
    private:
        // Pointer to dynamically allocated array of Icecream objects
        Icecream* orders; 
        int numOrders;    // Number of actual orders
        int capacity;     // Capacity of the dynamically allocated array
        double totalPrice;
        const double taxRate = 0.13; // 13% tax rate

    public:
        Vendor();
        ~Vendor();
        // setEmpty: Prepares the Vendor object for 
        // reuse by clearing any existing data.
        void setEmpty();
        //Interacts with the user to collect 
        // details about each ice cream order.
        void takeOrders();
        //Outputs a summary of all orders taken so far, 
        // including details for each order.
        void displayOrders() const;
        // Cleans up resources associated with the 
        // Vendor object, ensuring no memory leaks occur.
        void clearData();
        // Helper function to resize the dynamic array
        void resize(int newSize); 
        //A utility function used within displayOrders 
        // to format and display each line of the price summary.
        void displayPriceLine(const char* label, double amount) const;
    };

} // namespace seneca

#endif // VENDOR_H


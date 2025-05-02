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
#ifndef ICECREAM_H
#define ICECREAM_H

#include <iostream>

namespace seneca {

    class Icecream {
    private:
        char* flavor; // Dynamically allocated C-style string for flavor
        int scoops;   // Number of scoops
        bool vanillaWafer; // Indicates if a vanilla wafer cone is included
        double price; // Total price of the ice cream order

        // Private helper function to deallocate 
        // and allocate memory for the flavor
        void setFlavor(const char* name);

        // Converts choice to flavor name
        const char* getFlavorName(int choice) const;
       

    public:
        Icecream(); // Default constructor
        ~Icecream(); // Destructor

        // Rule of Three to manage deep copy of dynamic memory
        Icecream(const Icecream& other); // Copy constructor
        Icecream& operator=(const Icecream& other); // Copy assignment operator

        void getOrder(); // Captures an order from user input
        void printOrder() const; // Prints the order details
        double getPrice() const; // Returns the price of the ice cream
        
    };

} // namespace seneca

#endif // ICECREAM_H

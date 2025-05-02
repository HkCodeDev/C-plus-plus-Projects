/*****************************************************************************
                  Workshop - #3 (Part - 1)>
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Car.h" // Include the Car class

namespace seneca {
    class Customer {
    private:
        int m_id;
        char* m_name;
        // Pointer to a Car object, not dynamically allocated here
        const Car* m_car; 

    public:
        Customer();
        ~Customer();
        //This query method checks if the object is in a safe empty state.
        bool isEmpty() const;
        //This method sets the customer to a safe empty s
        // tate by setting the pointers to null and the id to 0.
        void setEmpty();
        //This Member function deallocates the dynamically
        //  allocated memory for the m_name member variable.
        void deallocateMemory();
        //Member function to Set the Customer name, ID and Car.
        void set(int customerId, const char* name, const Car* car);
        //This function displays the Customer in the intended format
        void display() const;
        // Return the car object by dereferencing the pointer
        const Car& car() const; 
    };
}

#endif // CUSTOMER_H

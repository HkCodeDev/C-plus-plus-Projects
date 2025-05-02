/*****************************************************************************
                  Workshop - #8 (Part - 1)>
Full Name : Hoda Karimi
Student ID# : 138611223
File: iAccount.h
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#ifndef SENECA_IACCOUNT_H
#define SENECA_IACCOUNT_H

#include <iostream>

namespace seneca {
    // The iAccount interface defines the structure for account types.
    // It ensures all derived account types implement these functions.
    class iAccount {
    public:
        // Credit function to add funds to the account.
        //  Must be implemented by derived classes.
        virtual bool credit(double amount) = 0;
        // Debit function to withdraw funds from the
        //  account. Must be implemented by derived classes.
        virtual bool debit(double amount) = 0;
        // Performs end-of-month operations. 
        // Implementation is specific to derived classes.
        virtual void monthEnd() = 0;
        // Displays account details. Must be implemented by
        //  derived classes to output specific information.
        virtual void display(std::ostream& out) const = 0;
        // Virtual destructor to allow derived classes 
        // to clean up resources if needed.
        virtual ~iAccount() = default;
    };

    // Helper function to create instances of derived
    //  Account types based on the specified type and initial balance.
   // 'type' determines which kind of account 
   // object to create and return as a pointer to iAccount.
    iAccount* CreateAccount(const char* type, double balance);

}

#endif // SENECA_IACCOUNT_H

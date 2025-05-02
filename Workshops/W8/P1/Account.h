/*****************************************************************************
                  Workshop - #8 (Part - 1)>
                  
Full Name : Hoda Karimi
Student ID# : 138611223
File: Account.h
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H

#include "iAccount.h"

namespace seneca {
    // The Account class, inheriting from the iAccount interface.
    // It serves as a base class for different types of bank accounts.
    class Account : public iAccount {
    protected:
        double accountBalance;

    public:
        // Constructor that initializes the account
        //  with a given balance.
      // The actual balance initialization logic is 
      // implemented in the Account.cpp file.
        Account(double balance);
        // Implement the credit and debit functions here
        //  if they share common behavior between account types
        virtual bool credit(double amount) override;
        // Debit (subtract) an amount from the account
        //  balance if sufficient funds exist.
        // Returns true if successful. This function is 
        // virtual, allowing for override by derived classes.
        virtual bool debit(double amount) override;
    protected:
        // Retrieves the current account balance.
        // Protected function, accessible only within 
        // this class and derived classes.
        double balance() const;
    };

}

#endif // SENECA_ACCOUNT_H

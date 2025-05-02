/*****************************************************************************
                  Workshop - #8 (Part - 1)>
                 
Full Name : Hoda Karimi
Student ID# : 138611223
File: Account.cpp
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#include "Account.h"

namespace seneca {

    // Constructor initializes the account balance.
    //  If the initial balance is negative,
    // it sets the account balance to 0.0.
    Account::Account(double balance) : 
        accountBalance(balance > 0 ? balance : 0.0) {}
    // Attempts to credit (add) a positive amount to the account balance.
    // Returns true if the operation is successful.
    bool Account::credit(double amount) {
        if (amount > 0) {
            accountBalance += amount;
            return true;
        }
        return false;
    }
    // Attempts to debit (subtract) a positive amount from the account balance
    // only if the amount does not exceed the current balance.
    // Returns true if the operation is successful.
    bool Account::debit(double amount) {
        if (amount > 0 && amount <= accountBalance) {
            accountBalance -= amount;
            return true;
        }
        return false;
    }
    // Returns the current account balance.
    double Account::balance() const {
        return accountBalance;
    }

}

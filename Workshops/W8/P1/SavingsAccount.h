/*****************************************************************************
                  Workshop - #8 (Part - 1)>
                  File: BanckAccount.h
Full Name : Hoda Karimi
Student ID# : 138611223
File: SavingAccount.h
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H

#include "Account.h"

namespace seneca {
    // SavingsAccount class inherits from Account. 
    // It represents a savings account that can earn interest.
    class SavingsAccount : public Account {
        double interestRate;// Interest rate for the savings account.

    public:
        // Constructor initializes a SavingsAccount 
        // with a starting balance and an interest rate.
        // If the provided interest rate is negative, 
        // it will be set to 0.0 in the implementation.
        SavingsAccount(double balance, double interestRate);
        // Overrides the monthEnd function from 
        // the Account class. This function calculates the
        // interest earned at the end of the 
        // month and adds it to the account balance.
        void monthEnd() override;
        // Overrides the display function to
        //  output the details of the savings account, including
        // the account type, balance,
        //  and interest rate, to the provided output stream.
        void display(std::ostream& out) const override;
    };

}

#endif // SENECA_SAVINGSACCOUNT_H

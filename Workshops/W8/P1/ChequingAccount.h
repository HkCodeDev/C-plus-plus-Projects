/*****************************************************************************
                  Workshop - #8 (Part - 1)>
                  
Full Name : Hoda Karimi
Student ID# : 138611223
File: ChequingAccount.h
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#ifndef SENECA_CHEQUINGACCOUNT_H
#define SENECA_CHEQUINGACCOUNT_H

#include "Account.h"

namespace seneca {
    // ChequingAccount class inherits from Account
    //  class and represents a checking account
   // with transaction fees and a monthly fee.
    class ChequingAccount : public Account {
        // Transaction fee charged per operation (credit or debit).
        double transactionFee;
        // Fixed monthly maintenance fee.
        double monthlyFee;

    public:
        // Constructor that initializes the chequing 
        // account with a balance, transaction fee, and monthly fee.
        ChequingAccount(double balance, double transactionFee, double monthlyFee);
        // Overrides the credit function to include transaction
        //  fee deduction after crediting an amount.
        bool credit(double amount) override;
        // Overrides the debit function to include
        //  transaction fee deduction after debiting an amount.
        bool debit(double amount) override;
        // Implements the monthly fee deduction from the account balance.
        void monthEnd() override;
        // Displays the account details, including type,
        //  balance, transaction fee, and monthly fee.
        void display(std::ostream& out) const override;
    };

}

#endif // SENECA_CHEQUINGACCOUNT_H

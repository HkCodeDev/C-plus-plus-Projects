/*****************************************************************************
                  Workshop - #7 (Part - 1)>
                  File: SavingAccount.h
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#ifndef SENECA_SAVINGSACCOUNT_H  
#define SENECA_SAVINGSACCOUNT_H
#include "BankAccount.h"

namespace seneca {
    // Declares the SavingsAccount class, 
    // which inherits publicly from BankAccount.
    class SavingsAccount : public BankAccount {
    private:
        // Stores the interest rate of the savings account.
        double m_interest;
        // Stores the date when the interest was last applied.
        Date m_interestDate;
        // Private method to write the interest 
        // rate to an output stream in a formatted way.
        void writeInterest(std::ostream& out) const;

    public:
        // Constructor to initialize a SavingsAccount object
        //  with name, open date, deposit info, balance, 
        // interest rate, and the interest date.
        SavingsAccount(const char* name, Date openDate,
            DepositInfo depInfo, double balance, double interest, Date interestDate);
        // Public method to apply interest to the 
        // account balance based on the interest 
        // rate and update the interest date.
        void applyInterest(Date& dt);
        // Overrides the write method from 
        // BankAccount to include savings account-specific information.
        std::ostream& write(std::ostream& out) const override; 
        // Overrides the read method from BankAccount 
        // to include savings account-specific information.
        std::istream& read(std::istream& in) override; 
        // Friend declarations for the insertion and extraction operators 
        // to access private and protected members of SavingsAccount.
        friend std::istream& operator>>(std::istream& in, SavingsAccount& acct);
        friend std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct);
    };

}
#endif
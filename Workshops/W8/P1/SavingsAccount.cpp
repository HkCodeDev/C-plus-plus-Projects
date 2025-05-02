/*****************************************************************************
                  Workshop - #8 (Part - 1)>
             
Full Name : Hoda Karimi
Student ID# : 138611223
File: SavingAccount.cpp
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#include "SavingsAccount.h"
#include <iomanip> 


namespace seneca {
    // Constructor for SavingsAccount that initializes the 
    // account with a balance and an interest rate.
    // Ensures the interest rate is not negative; otherwise, it is set to 0.0.
    SavingsAccount::SavingsAccount(double balance, double rate)
        : Account(balance), interestRate(rate > 0 ? rate : 0.0) {}
    // Implements the monthEnd function specific 
    // to SavingsAccount by applying the interest rate
    // to the account balance and crediting the
    //  calculated interest to the account.
    void SavingsAccount::monthEnd() {
        double interest = accountBalance * interestRate;
        credit(interest);
    }
    // Overrides the display function to 
    // output the account type, current balance, and interest rate
    // to the specified output stream in a readable format.
    void SavingsAccount::display(std::ostream& out) const {
        out << "Account type: Savings\n";
        out << "Balance: $" << std::fixed << std::setprecision(2) << balance() << "\n";
        out << "Interest Rate (%): " << std::fixed << std::setprecision(2) << interestRate * 100 << "\n";
    }

}

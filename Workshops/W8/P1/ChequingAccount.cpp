/*****************************************************************************
                  Workshop - #8 (Part - 1)>
Full Name : Hoda Karimi
Student ID# : 138611223
File: ChequingAccount.cpp
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#include "ChequingAccount.h"
#include <iomanip> 


namespace seneca {
    // Constructor for the ChequingAccount class.
    //  Initializes the account with a balance,
  // a transaction fee, and a monthly fee. Negative fees are set to 0.0.
    ChequingAccount::ChequingAccount(double balance, double transFee, double monthFee)
        : Account(balance), transactionFee(transFee > 0 ? transFee : 0.0), monthlyFee(monthFee > 0 ? monthFee : 0.0) {}
    // Credits an amount to the account and then debits the transaction fee.
    // Returns true if both operations are successful.
    bool ChequingAccount::credit(double amount) {
        if (Account::credit(amount)) {
            return Account::debit(transactionFee);
        }
        return false;
    }
    // Debits an amount from the account 
    // and then debits the transaction fee.
    // Returns true if both operations are successful.
    bool ChequingAccount::debit(double amount) {
        if (Account::debit(amount)) {
            return Account::debit(transactionFee);
        }
        return false;
    }
    // Debits the monthly fee from the account at the end of the month.
    void ChequingAccount::monthEnd() {
        Account::debit(monthlyFee);
    }
    // Displays the account details to the provided output stream.
    void ChequingAccount::display(std::ostream& out) const {
        out << "Account type: Chequing\n";
        out << "Balance: $" << std::fixed << std::setprecision(2) <<
            balance() << "\n";
        out << "Per Transaction Fee: " << std::fixed << std::setprecision(2) 
            << transactionFee << "\n";
        out << "Monthly Fee: " << std::fixed << 
            std::setprecision(2) << monthlyFee << "\n";
    }


}

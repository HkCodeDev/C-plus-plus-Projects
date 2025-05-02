/*****************************************************************************
                  Workshop - #7 (Part - 1)>
                  File: BanckAccount.h
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#ifndef SENECA_BANKACCOUNT_H  
#define SENECA_BANKACCOUNT_H
#include "DepositUtility.h"

namespace seneca {

    class BankAccount {
    private:
        char m_name[51]; 
        Date m_openDate;
        DepositInfo m_depInfo;
        double m_balance;

    protected:
        // Returns the current balance of the account.
        double getBalance() const;
        // Sets the account's balance to a new value.
        void setBalance(double balance);
        // Helper method to write an amount as currency to an output stream,
    //  formatting it with 2 decimal places and a dollar sign.
        void writeCurrency(std::ostream& out, double amount) const;

    public:
        // Public constructor to initialize a BankAccount object with name,
        //  opening date, deposit information, and balance.
        BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
        // Virtual function to serialize the BankAccount's data to an 
        // output stream in a readable format. Marked as const.
        virtual std::ostream& write(std::ostream& out) const; 
        // Virtual function to deserialize data from 
        // an input stream to populate the BankAccount's data.
        virtual std::istream& read(std::istream& in); 
        // Friends of the class, allowing these operator overloads 
        // to access private and protected members directly.
        friend std::istream& operator>>(std::istream& in, BankAccount& acct);
        friend std::ostream& operator<<(std::ostream& out, const BankAccount& acct);
    };

}
#endif

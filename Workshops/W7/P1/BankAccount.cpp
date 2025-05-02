/*****************************************************************************
                  Workshop - #7 (Part - 1)>
                  File: BankAccount.cpp
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "BankAccount.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace seneca {
    // Constructor definition: Initializes a BankAccount object with name,
    //  opening date, deposit information, and balance.
    BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo
        , double balance) : m_openDate(openDate), m_depInfo(depInfo), m_balance(balance) {
        // Copies the name into m_name, ensuring it does not exceed 50 characters.
        strncpy(m_name, name, 50);
        // Ensures the string is null-terminated.
        m_name[50] = '\0'; 
    }
    // Returns the current balance of the account.
    double BankAccount::getBalance() const {
        return m_balance;
    }
    // Sets the account's balance to a new value.
    void BankAccount::setBalance(double balance) {
        m_balance = balance;
    }
    // Helper method to write an amount as currency to an output stream,
    //  formatting it with 2 decimal places and a dollar sign.
    void BankAccount::writeCurrency(std::ostream& out, double amount) const {
        out << std::fixed << std::setprecision(2) << '$' << amount;
    }
    // Serializes the BankAccount's data to an output stream in a readable format.
    std::ostream& BankAccount::write(std::ostream& out) const {
        out << ">> "<< m_name << " | ";
        writeCurrency(out, m_balance);
        out << " | ";
        m_openDate.write(out);
        out << " | ";
        m_depInfo.write(out);
        return out;
    }
    // Deserializes data from an input 
    // stream to populate the BankAccount's data.
    std::istream& BankAccount::read(std::istream& in) {
        std::cout << "Name: ";
        in >> std::ws; // Consume any leading whitespace
        // Reads a line of text into m_name, 
        // up to 50 characters, for the account name.
        in.getline(m_name, 51);

        std::cout << "Opening Balance: ";
        in >> m_balance;// Reads the opening balance.

        std::cout << "Date Opened ";
        m_openDate.read(in);

        
        in >> m_depInfo;

        return in;
    }
    // Overloads the extraction operator to read BankAccount
    //  data from an input stream using the read method.
    std::istream& operator>>(std::istream& in, BankAccount& acct) {
        return acct.read(in);
    }
    // Overloads the insertion operator to write BankAccount 
    // data to an output stream using the write method.
    std::ostream& operator<<(std::ostream& out, const BankAccount& acct) {
        return acct.write(out);
    }

}

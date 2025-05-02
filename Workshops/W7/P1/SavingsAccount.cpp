/*****************************************************************************
                  Workshop - #7 (Part - 1)>
                  File: SavingAccount.cpp
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
#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>
#include <cmath>

namespace seneca {
    // Constructor for the SavingsAccount class, 
    // initializing it with name, open date, 
    // deposit info, balance, interest rate, and interest date.
    // Inherits from BankAccount.
    SavingsAccount::SavingsAccount(const char* name, Date openDate,
        DepositInfo depInfo, double balance, double interest, Date interestDate)
        : BankAccount(name, openDate, depInfo, balance), m_interest(interest), m_interestDate(interestDate) {}
    // Writes the interest rate to an output stream in a formatted way.
    void SavingsAccount::writeInterest(std::ostream& out) const {
        out << std::fixed << std::setprecision(3) << m_interest << "%";
    }

    // Applies interest to the account balance and updates the interest date.
    void SavingsAccount::applyInterest(Date& dt) {
        // Calculates interest based on current balance and rate.
        double interestAmount = getBalance() * m_interest; 
        // New balance after adding interest.
        double newBalance = getBalance() + interestAmount;
        // Updates account balance.
        setBalance(newBalance); 
      // Outputs detailed interest application info to standard output.
        std::cout << std::fixed << std::setprecision(2); 
        std::cout << "   $" << getBalance() - interestAmount
            << " + $" << interestAmount
            << " (" << std::fixed << std::setprecision(3) << m_interest << "%) = $";
        std::cout << std::fixed << std::setprecision(2) <<newBalance << " | ";
        m_interestDate.write(std::cout);
        std::cout << " => ";
        dt.write(std::cout);// New interest date.
        std::cout << std::endl;

        m_interestDate = dt; // Updates the interest date.
    }
    // Serializes the SavingsAccount's data to an output 
    // stream in a readable format.
    std::ostream& SavingsAccount::write(std::ostream& out) const{
        // Calls the base class method to write common data.
        BankAccount::write(out);
        out << " | ";
        writeInterest(out);// Writes the interest rate.
        out << " | ";
        m_interestDate.write(out); // Writes the interest date.
        return out;
    }
    // Deserializes data from an input stream 
    // to populate the SavingsAccount's data.
    std::istream& SavingsAccount::read(std::istream& in) {
        // Calls the base class method to read common data.
        BankAccount::read(in);

        std::cout << "Interest Date ";// Reads the interest date.
        m_interestDate.read(in);

        std::cout << "Interest Rate: ";// Reads the interest rate.
        in >> m_interest;

        return in;
    }
    // Overloads the extraction operator to read
    //  SavingsAccount data from an input stream using the read method.
    std::istream& operator>>(std::istream& in, SavingsAccount& acct) {
        return acct.read(in);
    }
    // Overloads the insertion operator to write SavingsAccount
    //  data to an output stream using the write method.
    std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct) {
        return acct.write(out);
    }

}
